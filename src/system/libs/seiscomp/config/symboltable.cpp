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

#include <seiscomp/config/symboltable.h>

#include <sstream>
#include <ctype.h>
#include <algorithm>
#include <iostream>


namespace Seiscomp {
namespace Config {


Symbol::Symbol(const std::string& name, const std::string &ns,
               const std::vector<std::string>& values,
               const std::string& uri,
               const std::string& comment,
               int s)
: name(name)
, ns(ns)
, values(values)
, uri(uri)
, comment(comment)
, stage(s)
, line(-1) {}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Symbol::Symbol() : stage(-1), line(-1) {}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Symbol::set(const std::string& name, const std::string &ns,
                 const std::vector<std::string>& values,
                 const std::string& uri,
                 const std::string& comment,
                 int stage) {
	this->name    = name;
	this->ns      = ns;
	this->values  = values;
	this->uri     = uri;
	this->comment = comment;
	this->stage   = stage;
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Symbol::operator ==(const Symbol& symbol) const {
	if (name == symbol.name)
		return true;
	return false;
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
std::string Symbol::toString() const {
	std::stringstream ss;
	if (!comment.empty())
		ss << comment;
	ss << name << " = ";
	Values::const_iterator valueIt = values.begin();
	for ( ; valueIt != values.end(); ++valueIt ) {
		if ( valueIt != values.begin() )
			ss << ", ";
		ss << *valueIt;
	}
	ss << " in " << uri;
	return ss.str();
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void SymbolTable::setLogger(Logger *l) {
	_logger = l;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Logger *SymbolTable::logger() {
	return _logger;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void SymbolTable::add(const std::string& name,
                      const std::string& ns,
                      const std::string& content,
                      const std::vector<std::string>& values,
                      const std::string& uri,
                      const std::string& comment,
                      int stage, int line) {
	std::pair<Symbols::iterator, bool> itp;
	itp = _symbols.insert(Symbols::value_type(name, Symbol()));
	if ( itp.second ) {
		Symbol &newSymbol = itp.first->second;
		newSymbol = Symbol(name, ns, values, uri, comment, stage);
		newSymbol.content = content;
		_symbolOrder.push_back(&newSymbol);
	}
	else {
		itp.first->second.set(name, ns, values, uri, comment, stage);
		itp.first->second.content = content;
	}

	// Update the last line in the parsed content
	itp.first->second.line = line;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void SymbolTable::add(const Symbol &symbol) {
	auto itp = _symbols.insert(Symbols::value_type(symbol.name, Symbol()));

	if ( itp.second ) {
		Symbol &newSymbol = itp.first->second;
		newSymbol = symbol;
		_symbolOrder.push_back(&newSymbol);
	}
	else {
		itp.first->second = symbol;
	}
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool SymbolTable::remove(const std::string& name) {
	auto it = _symbols.find(name);
	if ( it != _symbols.end() ) {
		SymbolOrder::iterator ito = std::find(_symbolOrder.begin(), _symbolOrder.end(), &it->second);
		if ( ito != _symbolOrder.end() )
			_symbolOrder.erase(ito);
		_symbols.erase(it);
		return true;
	}

	return false;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Symbol* SymbolTable::get(const std::string& name) {
	auto it = _symbols.find(name);
	if ( it != _symbols.end() ) {
		return &it->second;
	}

	return nullptr;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
const Symbol* SymbolTable::get(const std::string& name) const {
	Symbols::const_iterator it = _symbols.find(name);
	if ( it != _symbols.end() ) {
		return &it->second;
	}

	return nullptr;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int SymbolTable::incrementObjectCount() {
	return ++_objectCount;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int SymbolTable::decrementObjectCount() {
	return --_objectCount;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int SymbolTable::objectCount() const {
	return _objectCount;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
std::string SymbolTable::toString() const {
	std::stringstream ss;
	SymbolOrder::const_iterator symbolIt = _symbolOrder.begin();
	for ( ; symbolIt != _symbolOrder.end(); ++symbolIt)
		ss << (*symbolIt)->toString() << std::endl;

	return ss.str();
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool SymbolTable::hasFileBeenIncluded(const std::string& fileName) {
	IncludedFiles::iterator it = _includedFiles.find(fileName);
	if (it != _includedFiles.end())
		return true;
	return false;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void SymbolTable::addToIncludedFiles(const std::string& fileName) {
	_includedFiles.insert(fileName);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
SymbolTable::file_iterator SymbolTable::includesBegin() {
	return _includedFiles.begin();
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
SymbolTable::file_iterator SymbolTable::includesEnd() {
	return _includedFiles.end();
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
SymbolTable::iterator SymbolTable::begin() {
	return _symbolOrder.begin();
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
SymbolTable::iterator SymbolTable::end() {
	return _symbolOrder.end();
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



} // namespace Config
} // namespace Seiscomp
