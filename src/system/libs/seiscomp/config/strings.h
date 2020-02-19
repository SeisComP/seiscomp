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


#ifndef __SEISCOMP_CONFIG_STRINGS_H__
#define __SEISCOMP_CONFIG_STRINGS_H__

#include <string>
#include <vector>


namespace Seiscomp {
namespace Config {
namespace Private {


/** Array of whitespace characters */
const std::string WHITESPACE = "\t\n\v\f\r ";


/**
 * Converts a value into a string. Conversions are supported
 * for following types:
 *   char
 *   int, long, time_t
 *   float, double
 *   Core::Time, std::complex
 *   and any other type that is supported by std::ostream
 *   std::vector and OPT() of all above types
 *
 * @param value The value
 * @return The value as string
 */
template <typename T>
std::string toString(const T &value);
std::string toString(const std::string &value);
std::string toString(bool value);

template <typename T>
std::string toString(const std::vector<T> &v);


/**
 * Converts a string into a value. Conversions are supported
 * for following types:
 *   char
 *   int, long, time_t
 *   float, double
 *   std::vector of all above types
 *
 * @param value The target value
 * @param str The source string
 */
template <typename T>
bool fromString(T &value, const std::string &str);

/**
 * A case-insensitive comparison.
 * @return Result as defined by strcmp
 */
int compareNoCase(const std::string &a, const std::string &b);

/** Removes whitespace at the beginning and end of the string.
 * @param string to be trimmed (in/out parameter)
 * @return returns the trimmed string
 */
std::string &trim(std::string &str);

/** Checks if given character is whitespace */
bool isWhitespace(const char c);

/** Checks if the given string solely contains whitespace */
bool isWhitespace(const std::string &str);


}
}
}

#include "strings.ipp"

#endif
