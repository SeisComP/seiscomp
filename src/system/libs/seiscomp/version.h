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


#ifndef SEISCOMP_VERSION_H
#define SEISCOMP_VERSION_H


#define SEISCOMP_RELEASE_BRANCH "Release"

#define SEISCOMP_VERSION_MAJOR  5
#define SEISCOMP_VERSION_MINOR  5
#define SEISCOMP_VERSION_PATCH  14

#define SEISCOMP_VERSION ((SEISCOMP_VERSION_MAJOR << 0x10) |\
                          (SEISCOMP_VERSION_MINOR << 0x08) |\
                          (SEISCOMP_VERSION_PATCH))


#endif
