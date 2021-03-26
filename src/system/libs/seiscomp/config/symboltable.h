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

#ifndef __SEISCOMP_CONFIG_SYMBOLTABLE__
#define __SEISCOMP_CONFIG_SYMBOLTABLE__

#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

#include <seiscomp/config/log.h>

namespace Seiscomp {
namespace Config {


struct SC_CONFIG_API Symbol {
	typedef std::vector<std::string> Values;

	Symbol(const std::string& name, const std::string& ns,
	       const std::vector<std::string>& values,
	       const std::string& uri,
	       const std::string& comment,
	       int stage = -1);
	Symbol();

	void set(const std::string& name, const std::string& ns,
	         const std::vector<std::string>& values,
	         const std::string& uri,
	         const std::string& comment,
	         int stage = -1);

	bool operator ==(const Symbol& symbol) const;

	std::string toString() const;

	std::string name;
	std::string ns;
	std::string content;
	Values      values;
	std::string uri;
	std::string comment;
	int         stage;
	int         line;
};



class SC_CONFIG_API SymbolTable {

	private:
		typedef std::map<std::string, Symbol> Symbols;
		typedef std::vector<Symbol*> SymbolOrder;
		typedef std::map<std::string, Symbols::iterator> CISymbols;

	public:
		typedef SymbolOrder::const_iterator iterator;
		typedef std::set<std::string> IncludedFiles;
		typedef IncludedFiles::iterator file_iterator;

	public:
		SymbolTable();


	public:
		void setCaseSensitivityCheck(bool);
		void setLogger(Logger *);
		Logger *logger();

		void add(const std::string& name, const std::string &ns,
		         const std::string& content,
		         const std::vector<std::string>& values,
		         const std::string& uri,
		         const std::string& comment = "",
		         int stage=-1, int line=-1);

		void add(const Symbol& symbol);

		Symbol* get(const std::string& name);
		const Symbol* get(const std::string& name) const;

		bool remove(const std::string& name);

		int incrementObjectCount();
		int decrementObjectCount();
		int objectCount() const;

		std::string toString() const;

		bool hasFileBeenIncluded(const std::string& fileName);
		void addToIncludedFiles(const std::string& fileName);

		file_iterator includesBegin();
		file_iterator includesEnd();

		iterator begin();
		iterator end();

	private:
		//! Returns true if an inconsistent definition has been found
		bool checkCI(const std::string &name, const Symbol *) const;

	private:
		bool          _csCheck;
		Symbols       _symbols;
		CISymbols     _cisymbols;
		SymbolOrder   _symbolOrder;
		IncludedFiles _includedFiles;
		int           _objectCount;
		Logger        *_logger;
};


} // namespace Config
} // namespace Seiscomp

#endif
