/***************************************************************************
 * Copyright (C) gempa GmbH                                                *
 * All rights reserved.                                                    *
 * Contact: gempa GmbH (seiscomp-dev@gempa.de)                             *
 *                                                                         *
 * GNU Affero General Public License Usage                                 *
 * This file may be used under the terms of the GNU Affero                 *
 * Public License version 3.0 as published by the Free Software Foundation *
 * and appearing in the file LICENSE included in the packaging of this     *
 * file. Please review the following information to ensure the GNU Affero  *
 * Public License version 3.0 requirements will be met:                    *
 * https://www.gnu.org/licenses/agpl-3.0.html.                             *
 *                                                                         *
 * Other Usage                                                             *
 * Alternatively, this file may be used in accordance with the terms and   *
 * conditions contained in a signed written agreement between you and      *
 * gempa GmbH.                                                             *
 ***************************************************************************/

#include <seiscomp/config/config.h>
#include <seiscomp/config/strings.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <unistd.h>

#if WIN32

#include <direct.h>
#define PATH_MAX MAX_PATH

char *realpath(const char *relPath, char *absPath) {
	return _fullpath(absPath, relPath, PATH_MAX);
}

#endif


#ifndef WIN32
const char *homeDir() {
	const char *dir = getenv("HOME");
	if ( !dir )
		dir = ".";
#else
	char dir[MAX_PATH];
	if ( SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA, NULL, SHGFP_TYPE_CURRENT, dir) != S_OK )
		dir = ".";
#endif
	return dir;
}


#define BLOCK_BEGIN "{"
#define BLOCK_END   "}"

#define KEYWORD_INCLUDE   "include"


namespace Seiscomp {
namespace Config {

// ----------------------------------------------------------------------
// config.ipp
// ----------------------------------------------------------------------
#include <seiscomp/config/config.ipp>


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
namespace {

std::string CONF_NULL_OBJECT = "___CONFIG_NULL_OBJECT___";
std::string controls = "\n\t";
std::string quotable = controls + "\\\v\f\r ,=${}";

std::string stripEscapes(const std::string &str) {
	std::string tmpString(str);
	size_t pos = tmpString.find('\\');
	while ( pos != std::string::npos ) {
		if ( pos < tmpString.size()-1 && tmpString[pos+1] == '"' )
			tmpString.erase(tmpString.begin() + pos);
		pos = tmpString.find('\\', pos+1);
	}

	return tmpString;
}

std::string escapeDoubleQuotes(const std::string &str) {
	std::string tmpString(str);
	size_t pos = tmpString.find('\"');
	while ( pos != std::string::npos ) {
		tmpString.insert(tmpString.begin() + pos, '\\');
		pos = tmpString.find('\"', pos+2);
	}

	return tmpString;
}

std::string splitControls(const std::string &str) {
	std::string out;
	for ( size_t i = 0; i < str.size(); ++i ) {
		if ( str[i] == '\n' ) {
			out += "\"\\n\"";
		}
		else if ( str[i] == '\t' ) {
			out += "\"\\t\"";
		}
		else {
			out += str[i];
		}
	}
	return out;
}

std::string quote(const std::string &str) {
	if ( str.empty() ) {
		return "\"\"";
	}

	if ( str.find_first_of(quotable) != std::string::npos ) {
		return std::string("\"") + splitControls(str) + "\"";
	}

	return str;
}


std::ostream &escapeName(std::ostream &os, const std::string &name) {
	for ( char ch : name ) {
		if ( quotable.find(ch) != std::string::npos )
			os << '\\';
		os << ch;
	}

	return os;
}


struct DefaultLogger : Logger {
	void log(LogLevel l, const char *filename, int line, const char *msg) {
		if ( filename && *filename != '\0' )
			std::cerr << filename << ":" << line << ": ";

		switch ( l ) {
			case ERROR:
				std::cerr << "error: ";
				break;
			case WARNING:
				std::cerr << "warning: ";
				break;
			case INFO:
				std::cerr << "info: ";
				break;
			case DEBUG:
				std::cerr << "debug: ";
				break;
		}

		std::cerr << msg << std::endl;
	}
};


DefaultLogger __logger__;


} // namespace
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
template <>
std::string Config::get<std::string>(const std::string& name) const {
	const Symbol* symbol = _symbolTable->get(name);
	if (!symbol)
		throw OptionNotFoundException(name);

	return symbol->values[0];
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
template <>
bool Config::get<bool>(const std::string& name) const {
	const Symbol* symbol = _symbolTable->get(name);
	if (!symbol)
		throw OptionNotFoundException(name);

	std::string tmpVal = symbol->values[0];
	if (Private::compareNoCase(tmpVal, "true") == 0)
		return true;
	else if (Private::compareNoCase(tmpVal, "false") == 0)
		return false;

	bool value;
	if (!Private::fromString(value, symbol->values[0]))
		throw TypeConversionException(symbol->values[0]);

	return value;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
template <>
std::vector<std::string> Config::getVec<std::string>(const std::string& name) const {
	const Symbol* symbol = _symbolTable->get(name);
	if (!symbol)
		throw OptionNotFoundException(name);

	std::vector<std::string> tmpVec;
	for (size_t i = 0; i < symbol->values.size(); ++i)
		tmpVec.push_back(stripEscapes(symbol->values[i]));

	return tmpVec;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
template <>
std::vector<bool> Config::getVec<bool>(const std::string& name) const {
	const Symbol* symbol = _symbolTable->get(name);
	if (!symbol)
		throw OptionNotFoundException(name);

	std::vector<bool> values;
	for (size_t i = 0; i < symbol->values.size(); ++i)
	{
		if (Private::compareNoCase(symbol->values[i], "true") == 0)
			values.push_back(true);
		else if (Private::compareNoCase(symbol->values[i], "false") == 0)
			values.push_back(false);
		else
		{
			bool value;
			if (!Private::fromString(value, symbol->values[i]))
				throw TypeConversionException(symbol->values[i]);
			values.push_back(value);
		}
	}
	return values;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Config::Config()
: _stage(0), _resolveReferences(true), _logger(&__logger__), _symbolTable(nullptr),
  _trackVariables(false) {
	init();
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Config::~Config() {
	releaseSymbolTable();
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Config::setCaseSensitivityCheck(bool f) {
	_symbolTable->setCaseSensitivityCheck(f);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::readConfig(const std::string &filename, int stage, bool raw) {
	_stage = stage;
	_resolveReferences = !raw;

	if ( !_symbolTable ) init();
	_line = 0;
	_fileName.assign(filename);

	std::istream *is;
	std::fstream file;

	if ( _fileName == "-" )
		is = &std::cin;
	else {
		file.open(_fileName.c_str(), std::ios_base::in);
		if ( file.rdstate() != std::ios_base::goodbit ) {
			//SEISCOMP_ERROR("Could not read file %s", _fileName.c_str());
			return false;
		}
		is = &file;
	}

	_symbolTable->addToIncludedFiles(_fileName);

	bool result = parseFile(*is);

	return result;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::readInternalConfig(const std::string &file,
                                SymbolTable* symbolTable,
                                const std::string &namespacePrefix,
                                int stage, bool raw) {
	if ( _symbolTable ) {
		_symbolTable->decrementObjectCount();
		if ( _symbolTable->objectCount() <= 0 ) {
			delete _symbolTable;
			_symbolTable = nullptr;
		}
	}
	_symbolTable = symbolTable;
	_symbolTable->incrementObjectCount();

	_defaultNamespacePrefix = namespacePrefix;

	return readConfig(file, stage, raw);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::writeConfig(const std::string &filename, bool localOnly,
                         bool multilineLists) {
	int firstLine = true;

	std::ostream *os;
	std::fstream file;

	if ( filename == "-" )
		os = &std::cout;
	else {
		file.open(filename.c_str(), std::ios_base::out | std::ios_base::trunc);
		if ( file.rdstate() != std::ios_base::goodbit ) {
			//SEISCOMP_ERROR("Could not open file %s", file.c_str());
			return false;
		}
		os = &file;
	}

	for ( const auto &symbol : *_symbolTable ) {
		if ( localOnly ) {
			if ( !symbol->uri.empty() && symbol->uri != filename ) {
				continue;
			}
		}

		if ( !firstLine )
			*os << std::endl;
		else
			firstLine = false;

		if ( !symbol->comment.empty() )
			*os << symbol->comment << std::endl;

		writeSymbol(*os, symbol, multilineLists);
	}

	return true;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::writeConfig(bool localOnly)
{
	return writeConfig(_fileName, localOnly);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Config::writeValues(std::ostream &os, const Symbol *symbol,
                         bool multilineLists)
{
	if ( symbol->values.empty() )
		os << "\"\"";
	else if ( multilineLists ) {
		os << quote(escapeDoubleQuotes(symbol->values[0]));
		if ( symbol->values.size() > 1 ) {
			// Evaluate the complete length of the values
			size_t valueCharacterLength = 0;
			for ( size_t i = 0; i < symbol->values.size(); ++i )
				valueCharacterLength += symbol->values[i].size();
			valueCharacterLength += (symbol->values.size()-1)*2;

			if ( valueCharacterLength > 80 ) {
				os << ",\\" << std::endl;
				size_t prefix = symbol->name.size() + 3;
				for ( size_t i = 1; i < symbol->values.size(); ++i ) {
					for ( size_t f = 0; f < prefix; ++f ) os << ' ';
					os << quote(escapeDoubleQuotes(symbol->values[i]));
					if ( i < symbol->values.size()-1 )
						os << ",\\" << std::endl;
				}
			}
			else {
				for ( size_t i = 1; i < symbol->values.size(); ++i ) {
					if ( i != 0 ) os << ", ";
					os << quote(escapeDoubleQuotes(symbol->values[i]));
				}
			}
		}
	}
	else {
		for ( size_t i = 0; i < symbol->values.size(); ++i ) {
			if ( i != 0 ) os << ", ";
			os << quote(escapeDoubleQuotes(symbol->values[i]));
		}
	}
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Config::writeContent(std::ostream &os, const Symbol *symbol,
                          bool multilineLists) {
	if ( symbol->content.empty() )
		os << "\"\"";
	else {
		std::vector<std::string> values;
		std::string errorMsg;
		if ( !multilineLists
		  || !parseRValue(symbol->content, values, nullptr, false, true, &errorMsg) )
			os << symbol->content;
		else if ( !values.empty() ) {
			os << values[0];
			if ( values.size() > 1 ) {
				// Evaluate the complete length of the values
				size_t valueCharacterLength = 0;
				for ( size_t i = 0; i < values.size(); ++i )
					valueCharacterLength += values[i].size();
				valueCharacterLength += (values.size()-1)*2;

				if ( valueCharacterLength > 80 ) {
					os << ",\\" << std::endl;
					size_t prefix = symbol->name.size() + 3;
					for ( size_t i = 1; i < values.size(); ++i ) {
						for ( size_t f = 0; f < prefix; ++f ) os << ' ';
						os << values[i];
						if ( i < values.size()-1 )
							os << ",\\" << std::endl;
					}
				}
				else {
					for ( size_t i = 1; i < values.size(); ++i ) {
						if ( i != 0 ) os << ", ";
						os << values[i];
					}
				}
			}
		}
	}
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Config::writeSymbol(std::ostream &os, const Symbol *symbol,
                         bool multilineLists) {
	escapeName(os, symbol->name) << " = ";
	writeValues(os, symbol, multilineLists);
	os << std::endl;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
std::string Config::escapeIdentifier(const std::string &name) {
	std::stringstream sstream;
	escapeName(sstream, name);
	return sstream.str();
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Config::trackVariables(bool enabled) {
	if ( !enabled )
		_variables.clear();
	_trackVariables = enabled;
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
const Variables& Config::getVariables() const {
	return _variables;
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
std::string Config::escape(const std::string &s) const {
	return quote(escapeDoubleQuotes(s));
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Config &Config::operator=(Config &&other) {
	// Move common attributes
	_stage = std::move(other._stage);
	_line = std::move(other._line);
	_resolveReferences = std::move(other._resolveReferences);
	_fileName = std::move(other._fileName);
	_namespaces = std::move(other._namespaces);
	_namespacePrefix = std::move(other._namespacePrefix);
	_defaultNamespacePrefix = std::move(other._defaultNamespacePrefix);

	_logger = other._logger; other._logger = nullptr;
	_symbolTable = other._symbolTable; _symbolTable = nullptr;
	_trackVariables = std::move(other._trackVariables);
	_variables = std::move(other._variables);

	return *this;
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
std::string Config::visitedFilesToString() {
	std::stringstream ss;
	SymbolTable::IncludedFiles::iterator fileIt = _symbolTable->includesBegin();
	for ( ; fileIt != _symbolTable->includesEnd(); ++fileIt)
		ss << *fileIt << std::endl;
	return ss.str();
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Config::setLogger(Logger *logger) {
	_logger = logger;
	if ( _symbolTable )
		_symbolTable->setLogger(logger);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
std::string Config::symbolsToString() {
	return _symbolTable->toString();
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<





// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::parseFile(std::istream &is) {
	std::string entry;
	std::string comment;
	std::string line;
	bool stringMode = false;
	bool success = true;

	_namespacePrefix = _defaultNamespacePrefix;
	_namespaces.clear();

	while ( getline(is, line) ) {
		++_line;
		Private::trim(line);
		if ( line.empty() ) continue;

		// Handle comments
		std::string::iterator current  = line.begin();
		std::string::iterator next     = line.begin();
		std::string::iterator previous = line.begin();
		for ( ; current != line.end(); ++current ) {
			if ( current + 1 != line.end() )
				next = current + 1;
			if ( current != line.begin() )
				previous = current - 1;

			if ( *current == '"' ) {
				if ( (*previous != '\\') || stringMode ) {
					// Escape mode only valid outside of strings
					stringMode = !stringMode;
				}
			}
			else if ( *current == '#' && !stringMode ) {
				if ( !comment.empty() )
					comment += '\n';
				std::copy(current, line.end(), std::back_inserter(comment));
				break;
			}
			entry.push_back(*current);
		}

		entry = Private::trim(entry);
		if ( entry.empty() ) continue;

		if ( *entry.rbegin() != '\\' ) {
			if ( stringMode ) {
				CONFIG_ERROR("%s", "Missing terminating \" character");
				stringMode = false;
				success = false;
				entry.clear();
				continue;
			}

			if ( !handleEntry(entry + '\n', comment) ) {
				success = false;
			}
			entry.clear();
			comment.clear();
		}
		else {
			entry.erase(entry.size() - 1);
		}
	}

	if ( !_namespaces.empty() ) {
		CONFIG_ERROR("Namespace '%s' has not been closed", _namespaces.back().c_str());
		return false;
	}

	return success;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Config::init() {
	if ( !_symbolTable ) {
		_symbolTable = new SymbolTable;
		_symbolTable->setLogger(_logger);
	}
	_symbolTable->incrementObjectCount();
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::handleEntry(const std::string& entry, const std::string& comment) {
	std::string errmsg;

	//SEISCOMP_DEBUG("Scanning entry: %s", entry.c_str());
	std::vector<std::string> tokens = tokenize(entry);

	//SEISCOMP_DEBUG("Parsing entry");
	if ( tokens.size() < 2 ) {
		if ( (tokens.size() == 1) && (tokens[0] == BLOCK_END) ) {
			if ( _namespaces.empty() ) {
				CONFIG_ERROR("Unexpected closing block: %s", entry.c_str());
				return false;
			}

			_namespaces.pop_back();

			// Update prefix
			_namespacePrefix = _defaultNamespacePrefix;

			Namespaces::iterator it = _namespaces.begin();
			for ( ; it != _namespaces.end(); ++it ) {
				_namespacePrefix += *it;
				_namespacePrefix += '.';
			}

			return true;
		}
		else {
			CONFIG_ERROR("Config entry malformed: Too few parameters for %s", entry.c_str());
			return false;
		}
	}

	if ( tokens[0][0] == '$' ) {
		CONFIG_ERROR("Cannot assign to rvalue: %s", tokens[0].c_str());
		return false;
	}

	// Handle operators
	std::vector<std::string> parsedValues;
	if ( tokens[0] == KEYWORD_INCLUDE ) {
		if ( tokens.size() > 2 ) {
			CONFIG_ERROR("Operator %s has too many operands -> %s file",
			          tokens[0].c_str(), tokens[0].c_str());
			return false;
		}

		if ( !parseRValue(tokens[1], parsedValues, _symbolTable,
		                  _resolveReferences, false, &errmsg) ) {
			CONFIG_ERROR("%s", errmsg.c_str());
			return false;
		}

		if ( !handleInclude(parsedValues[0]) ) {
			CONFIG_ERROR("Could not read include file %s", parsedValues[0].c_str());
			return false;
		}
	}
	else if ( tokens[0] == "del" ) {
		if ( tokens.size() == 1 ) {
			//SEISCOMP_ERROR("[%s:%d] Missing operands for %s operator: %s",
			//		_fileName.c_str(), _line, tokens[0].c_str(), entry.c_str());
			return false;
		}

		std::string tmp;
		for ( size_t i = 1; i < tokens.size(); ++i )
			tmp += tokens[i];

		parsedValues.clear();
		if ( !parseRValue(tmp, parsedValues, _symbolTable,
		                  _resolveReferences, false, &errmsg) ) {
			CONFIG_ERROR("%s", errmsg.c_str());
			return false;
		}

		std::vector<std::string>::const_iterator it = parsedValues.begin();
		for ( ; it != parsedValues.end(); ++it ) {
			if ( !_symbolTable->remove(_namespacePrefix + *it) ) {
				CONFIG_ERROR("Could not remove variable %s from symbol table",
				             (_namespacePrefix + (*it)).c_str());
				return false;
			}
		}
	}
	else if ( (tokens.size() == 2) && (tokens[1] == BLOCK_BEGIN) ) {
		_namespaces.push_back(tokens[0]);
		_namespacePrefix += tokens[0];
		_namespacePrefix += ".";
	}
	else if ( tokens[1] == "=" ) {
		if ( tokens.size() < 3 ) {
			CONFIG_ERROR("RValue missing in assignment: %s", entry.c_str());
			return false;
		}

		std::vector<std::string> values;
		std::string tmp;
		for ( size_t i = 2; i < tokens.size(); ++i )
			tmp += tokens[i];

		if ( !eval(tmp, values, _resolveReferences, &errmsg) ) {
			CONFIG_ERROR("%s", errmsg.c_str());
			return false;
		}

		handleAssignment(tokens[0], tmp, values, comment);
	}
	else {
		CONFIG_ERROR("Invalid entry: %s", entry.c_str());
		return false;
	}

	return true;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::handleInclude(const std::string& fileName) {
	if ( fileName.empty() ) return false;

	std::string tmpFileName(fileName);
	// Resolve ~ for home directory
	if ( tmpFileName[0] == '~' ) {
		tmpFileName = homeDir() + tmpFileName.substr(1);
	}

	bool isRelativePath = false;
	char oldPath[PATH_MAX];

	if ( tmpFileName[0] != '/' ) {
		isRelativePath = true;
		// Change to the config file path to be able to handle relative paths
		if ( getcwd(oldPath, PATH_MAX) ) {
			std::string::size_type pos = _fileName.rfind("/");
			if ( pos != std::string::npos )
				chdir(_fileName.substr(0, pos).c_str());
		}
	}

	if ( !_symbolTable->hasFileBeenIncluded(tmpFileName) ) {
		//SEISCOMP_DEBUG("Handling include: %s", tmpFileName.c_str());
		Config conf;
		if ( !conf.readInternalConfig(tmpFileName, _symbolTable, _namespacePrefix,
		                              _stage, !_resolveReferences) ) {
			return false;
		}
	}

	if ( isRelativePath ) {
		chdir(oldPath);
	}

	return true;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Config::handleAssignment(const std::string& name,
                              const std::string& content,
                              std::vector<std::string>& values,
                              const std::string& comment) {
	_symbolTable->add(_namespacePrefix + name, _namespacePrefix, content,
	                  values, _fileName, comment, _stage, _line);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::reference(const std::string &name,
                       std::vector<std::string> &values,
                       const SymbolTable *symtab)
{
	if ( symtab ) {
		const Symbol* symbol = nullptr;
		try {
			symbol = symtab->get(name);
		}
		catch ( Exception& e ) {
			//SEISCOMP_DEBUG("%s", e.what());
		}

		if ( symbol ) {
			values = symbol->values;
			return true;
		}
	}

	char *env = getenv(name.c_str());
	if ( env ) {
		values.clear();
		values.push_back(std::string(env));
		return true;
	}

	return false;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
std::vector<std::string> Config::tokenize(const std::string& entry)
{
	std::vector<std::string> tokens;
	std::string nextToken;
	bool stringMode = false;
	bool escapeMode = false;
	std::string::const_iterator previousIt = entry.begin();

	std::string::const_iterator it = entry.begin();
	for ( ; it != entry.end(); ++it ) {
		if (it != entry.begin())
			previousIt = it - 1;

		bool isOperator = *it == '=' || *it == ',';

		if ( *it == '\\' && !escapeMode && !stringMode ) {
			escapeMode = true;
			continue;
		}

		if ( escapeMode ) {
			// The first token either defines a variable name or a command and
			// is not going to be parsed further. So the escape character must
			// be removed.
			if ( !tokens.empty() )
				nextToken.push_back(*previousIt);
			nextToken.push_back(*it);
			escapeMode = false;
		}
		else if ( stringMode ) {
			if ( *it == '"' ) {
				stringMode = !stringMode;
				nextToken.push_back(*it);
				tokens.push_back(nextToken);
				nextToken.clear();
			}
			else {
				nextToken.push_back(*it);
			}
		}
		else if ( Private::isWhitespace(*it) ) {
			if ( !nextToken.empty() ) {
				tokens.push_back(nextToken);
				nextToken.clear();
			}
		}
		else if ( isOperator ) {
			if ( !nextToken.empty() ) {
				tokens.push_back(nextToken);
				nextToken.clear();
			}
			nextToken.push_back(*it);
			tokens.push_back(nextToken);
			nextToken.clear();
		}
		else if ( *it == '"' && *previousIt != '\\' ) {
			stringMode = !stringMode;
			nextToken.push_back(*it);
		}
		else {
			nextToken.push_back(*it);
		}
	}

	return tokens;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::parseRValue(const std::string& entry,
                         std::vector<std::string>& parsedValues,
                         const SymbolTable *symtab,
                         bool resolveReferences, bool rawMode,
                         std::string *errmsg) {
	bool openCurlyBrace = false;
	bool stringMode     = false;
	bool escapeMode     = false;
	std::string parsedEntry;
	std::vector<std::string> tokens;
	std::string::const_iterator it       = entry.begin();
	std::string::const_iterator previous = entry.begin();
	std::string::const_iterator next     = entry.begin();

	if ( rawMode ) {
		resolveReferences = false;
	}

	for ( ; it != entry.end(); ++it ) {
		if ( it != entry.begin() ) previous = it - 1;
		next = it + 1;

		if ( *it == '\\' && !stringMode && !escapeMode ) {
			if ( rawMode ) {
				parsedEntry.push_back(*it);
			}
			escapeMode = true;
			continue;
		}

		if ( escapeMode ) {
			if ( !rawMode && *it == 'n' ) {
				parsedEntry.push_back('\n');
			}
			else if ( !rawMode && *it == 't' ) {
				parsedEntry.push_back('\t');
			}
			else {
				parsedEntry.push_back(*it);
			}
			escapeMode = false;
		}
		else if ( *it == '"' ) {
			stringMode = !stringMode;
			if ( rawMode ) {
				parsedEntry.push_back(*it);
			}
			else if ( next != entry.end() && *next == '"' ) {
				tokens.push_back("");
			}
		}
		else if ( *it == '$' && !stringMode && resolveReferences ) {
			std::string variable;
			if ( ++it == entry.end() ) {
				if ( errmsg ) *errmsg = "Stand-alone reference operator";
				//SEISCOMP_ERROR("[%s:%d] Standalone reference operator", _fileName.c_str(), _line);
				return false;
			}

			for ( ; it != entry.end(); ++it ) {
				if ( *it == '{' ) {
					openCurlyBrace = !openCurlyBrace;
				}
				else if ( *it == '}' ) {
					openCurlyBrace = !openCurlyBrace;
					break;
				}
				else {
					variable.push_back(*it);
				}
			}

			if ( openCurlyBrace ) {
				if ( errmsg ) *errmsg = "Missing brace in reference";
				//SEISCOMP_ERROR("[%s:%d] Missing brace in reference", _fileName.c_str(), _line);
				return false;
			}

			if ( !parsedEntry.empty() ) {
				tokens.push_back(parsedEntry);
				parsedEntry.clear();
			}

			std::vector<std::string> values;
			if ( !reference(variable, values, symtab) ) {
				/*
				SEISCOMP_DEBUG(
					"[%s:%d] Cannot reference variable: %s Assigning NULL object.",
					_fileName.c_str(),
					_line,
					variable.c_str()
				);
				*/
				if ( errmsg ) *errmsg = "Cannot resolve '" + variable + "'";
				values.push_back(CONF_NULL_OBJECT);
			}

			std::vector<std::string>::iterator valueIt = values.begin();
			for ( ; valueIt != values.end(); ++valueIt ) {
				if ( valueIt != values.begin() )
					tokens.push_back(",");
				tokens.push_back(*valueIt);
			}

			if ( it == entry.end() ) break;
		}
		else {
			if ( *it == ',' && !stringMode ) {
				if ( !parsedEntry.empty() ) {
					tokens.push_back(parsedEntry);
					parsedEntry.clear();
				}
				tokens.push_back(",");
			}
			else {
				if ( !Private::isWhitespace(*it) || stringMode )
					parsedEntry.push_back(*it);
			}
		}
	}

	if ( stringMode ) {
		if ( errmsg ) {
			*errmsg = "Missing terminating \" character in rvalue";
		}
		return false;
	}
	if ( !parsedEntry.empty() )
		tokens.push_back(parsedEntry);

	//for ( size_t i = 0; i < tokens.size(); ++i )
	//	SEISCOMP_DEBUG("token%lu: %s", i ,tokens[i].c_str());

	// Apply grammar
	auto currentIt  = tokens.begin();
	auto previousIt = tokens.begin();
	auto nextIt     = tokens.begin();
	std::string token;
	for ( ; currentIt != tokens.end(); ++currentIt ) {
		if ( currentIt != tokens.begin() ) previousIt = currentIt - 1;
		nextIt = currentIt + 1;

		if ( *currentIt == CONF_NULL_OBJECT ) {
			if ( nextIt != tokens.end() && *previousIt == "," && *nextIt == "," ) {}
			else if ( nextIt != tokens.end() && currentIt == tokens.begin() && *nextIt == "," ) {}
			else if ( nextIt == tokens.end() && *previousIt == "," ) {}
			else {
				/*
				SEISCOMP_ERROR(
					"[%s:%d] NULL object found in string concatenation: %s",
					_fileName.c_str(),
					_line,
					entry.c_str()
				);
				*/
				if ( errmsg ) {
					if ( !errmsg->empty() )
						*errmsg += "\n";
					*errmsg += "NULL object found in string concatenation";
				}
				return false;
			}
		}
		else if ( *currentIt == "," ) {
			bool invalidList = *previousIt == "," ||
			                   (nextIt != tokens.end() && *nextIt == ",") ||
			                   nextIt == tokens.end();

			if ( invalidList ) {
				/*
				SEISCOMP_ERROR(
					"[%s:%d] Invalid list found: %s",
					_fileName.c_str(),
					_line,
					entry.c_str()
				);
				*/
				if ( errmsg ) *errmsg = "Invalid list";
				return false;
			}

			if ( *previousIt != CONF_NULL_OBJECT )
				parsedValues.push_back(token);
			token.clear();

			continue;
		}
		else {
			token += *currentIt;
			if ( nextIt == tokens.end() ) {
				parsedValues.push_back(token);
			}
		}
	}

	//for ( size_t i = 0; i < parsedValues.size(); ++i )
	//	SEISCOMP_DEBUG("value%lu: %s", i, parsedValues[i].c_str());

	return true;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
bool Config::eval(const std::string &rvalue, std::vector<std::string> &result,
                  bool resolveReferences,
                  std::string *errmsg) {
	return Eval(rvalue, result, resolveReferences, _symbolTable, errmsg);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
bool Config::Eval(const std::string &rvalue, std::vector<std::string> &result,
                  bool resolveReferences, SymbolTable *symtab,
                  std::string *errmsg) {
	if ( !parseRValue(rvalue, result, symtab, resolveReferences, false, errmsg) )
		return false;

	std::vector<std::string>::iterator it;
	for ( it = result.begin(); it != result.end(); ++it )
		*it = stripEscapes(*it);

	return true;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
std::vector<std::string> Config::names() const {
	std::vector<std::string> tmpVec;

	SymbolTable::iterator it = _symbolTable->begin();
	for ( ; it != _symbolTable->end(); ++it)
		tmpVec.push_back((*it)->name);

	return tmpVec;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int Config::getInt(const std::string& name) const {
	addVariable(name, "int");
	return get<int>(name);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int Config::getInt(const std::string& name, bool* error) const {
	addVariable(name, "int");
	return get<int>(name, error);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::getInt(int& value, const std::string& name) const {
	addVariable(name, "int");
	return get<int>(value, name);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
double Config::getDouble(const std::string& name) const {
	addVariable(name, "double");
	return get<double>(name);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
double Config::getDouble(const std::string& name, bool* error) const {
	addVariable(name, "double");
	return get<double>(name, error);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::getDouble(double& value, const std::string& name) const {
	addVariable(name, "double");
	return get<double>(value, name);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
bool Config::getBool(const std::string& name) const {
	addVariable(name, "boolean");
	return get<bool>(name);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::getBool(const std::string& name, bool* error) const {
	addVariable(name, "boolean");
	return get<bool>(name, error);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::getBool(bool& value, const std::string& name) const {
	addVariable(name, "boolean");
	return get<bool>(value, name);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
std::string Config::getString(const std::string& name) const {
	addVariable(name, "string");
	return get<std::string>(name);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
std::string Config::getString(const std::string& name, bool* error) const {
	addVariable(name, "string");
	return get<std::string>(name, error);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::getString(std::string& value, const std::string& name) const {
	addVariable(name, "string");
	return get<std::string>(value, name);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
std::vector<int> Config::getInts(const std::string& name) const {
	addVariable(name, "list:int");
	return getVec<int>(name);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
std::vector<int> Config::getInts(const std::string& name, bool* error) const {
	addVariable(name, "list:int");
	return getVec<int>(name, error);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
std::vector<double> Config::getDoubles(const std::string& name) const {
	addVariable(name, "list:double");
	return getVec<double>(name);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
std::vector<double> Config::getDoubles(const std::string& name, bool* error) const {
	addVariable(name, "list:double");
	return getVec<double>(name, error);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
std::vector<bool> Config::getBools(const std::string& name) const {
	addVariable(name, "list:boolean");
	return getVec<bool>(name);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
std::vector<bool> Config::getBools(const std::string& name, bool* error) const {
	addVariable(name, "list:boolean");
	return getVec<bool>(name, error);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
std::vector<std::string> Config::getStrings(const std::string& name) const {
	addVariable(name, "list:string");
	return getVec<std::string>(name);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
std::vector<std::string> Config::getStrings(const std::string& name, bool* error) const {
	addVariable(name, "list:string");
	return getVec<std::string>(name, error);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::getStrings(std::vector<std::string>& value, const std::string& name) const {
	addVariable(name, "list:string");
	try {
		value = getStrings(name);
		return true;
	}
	catch ( ... ) {
		return false;
	}
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::setInt(const std::string& name, int value) {
	addVariable(name, "list:int");
	return set<int>(name, value);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::setDouble(const std::string& name, double value)
{
	return set<double>(name, value);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::setBool(const std::string& name, bool value)
{
	return set<bool>(name, value);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::setString(const std::string& name, const std::string& value)
{
	return set<std::string>(name, value);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::setInts(const std::string& name, const std::vector<int>& values)
{
	return set<int>(name, values);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::setDoubles(const std::string& name, const std::vector<double>& values)
{
	return set<double>(name, values);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::setBools(const std::string& name, const std::vector<bool>& values)
{
	return set<bool>(name, values);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Config::setStrings(const std::string& name, const std::vector<std::string>& values)
{
	return set<std::string>(name, values);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
SymbolTable *Config::symbolTable() const {
	return _symbolTable;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
bool Config::remove(const std::string& name)
{
	return _symbolTable->remove(name);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
inline void Config::addVariable(const std::string &name, const char *type) const {
	if ( _trackVariables ) {
		const_cast<Config*>(this)->_variables[name] = type;
	}
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void Config::releaseSymbolTable() {
	if ( _symbolTable ) {
		_symbolTable->decrementObjectCount();
		if ( _symbolTable->objectCount() <= 0 ) {
			delete _symbolTable;
			_symbolTable = nullptr;
		}
	}
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


} // namespace Config
} // namespace Seiscomp
