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


#ifndef __SEISCOMP_CONFIG_LOG_H__
#define __SEISCOMP_CONFIG_LOG_H__


#include <seiscomp/config/api.h>
#include <cstdio>


namespace Seiscomp {
namespace Config {


enum LogLevel {
	ERROR,
	WARNING,
	INFO,
	DEBUG
};


struct SC_CONFIG_API Logger {
	virtual ~Logger();
	virtual void log(LogLevel, const char *filename, int line, const char *msg);
};


extern char log_msg_buffer[1024];


#define CONFIG_LOG_CHANNEL(chan, msg, ...) \
	if ( _logger ) {\
		snprintf(log_msg_buffer, 1023, msg, __VA_ARGS__);\
		_logger->log(chan, _fileName.c_str(), _line, log_msg_buffer);\
	}


#define CONFIG_ERROR(msg, ...) CONFIG_LOG_CHANNEL(ERROR, msg, __VA_ARGS__)
#define CONFIG_WARNING(msg, ...) CONFIG_LOG_CHANNEL(WARNING, msg, __VA_ARGS__)
#define CONFIG_INFO(msg, ...) CONFIG_LOG_CHANNEL(INFO, msg, __VA_ARGS__)
#define CONFIG_DEBUG(msg, ...) CONFIG_LOG_CHANNEL(DEBUG, msg, __VA_ARGS__)


}
}


#endif
