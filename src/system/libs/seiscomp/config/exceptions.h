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


#ifndef __SEISCOMP_CONFIG_EXCEPTIONS_H__
#define __SEISCOMP_CONFIG_EXCEPTIONS_H__


#include <exception>
#include <string>
#include <seiscomp/config/api.h>


namespace Seiscomp {
namespace Config {


class SC_CONFIG_API Exception : public std::exception {
	public:
		Exception() : _what("Configuration exception") {}
		Exception(const std::string &str) : _what(str) {}
		Exception(const char *str) : _what(str) {}
		virtual ~Exception() throw() {}

		const char *what() const throw() { return _what.c_str(); }

	private:
		std::string _what;
};


class SC_CONFIG_API OptionNotFoundException : public Exception {
	public:
		OptionNotFoundException() : Exception("Option not found") { }
		OptionNotFoundException(const std::string& str) : Exception("Option not found for: " + str) { }
};


class SC_CONFIG_API TypeConversionException : public Exception {
	public:
		TypeConversionException() : Exception("Type conversion error") { }
		TypeConversionException(const std::string& str) : Exception("Type conversion error: " + str) { }
};


class SC_CONFIG_API SyntaxException : public Exception {
	public:
		SyntaxException() : Exception("Syntax error") { }
		SyntaxException(const std::string& str) : Exception("Syntax error: " + str) { }
};


class SC_CONFIG_API CaseSensitivityException : public Exception {
	public:
		CaseSensitivityException() : Exception("Case-insensitiv names are ambiguous") { }
		CaseSensitivityException(const std::string &str) : Exception("Case-insensitiv names are ambiguous: " + str) { }
};


} // namespace Config
} // namespace Seiscomp


#endif
