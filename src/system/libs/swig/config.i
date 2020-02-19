/***************************************************************************
 *   Copyright (C) by GFZ Potsdam, gempa GmbH                              *
 *                                                                         *
 *   You can redistribute and/or modify this program under the             *
 *   terms of the SeisComP Public License.                                 *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   SeisComP Public License for more details.                             *
 ***************************************************************************/

%module(package="seiscomp", directors="1") config

//
// includes
//
%{
#include "seiscomp/config/config.h"
#include "seiscomp/config/symboltable.h"
%}


%feature("director") Seiscomp::Config::Logger;


// 
// typemaps
//
%include <typemaps.i>
%include <std_string.i>
%include <std_vector.i>

%include "seiscomp/config/api.h"
%include "seiscomp/config/log.h"
%include "seiscomp/config/exceptions.h"

%exception {
  try {
    $action
  }
  catch ( const Seiscomp::Config::OptionNotFoundException &e) {
    SWIG_exception(SWIG_ValueError, e.what());
  }
  catch ( const std::exception &e) {
    SWIG_exception(SWIG_RuntimeError, e.what());
  }
  catch ( ... ) {
    SWIG_exception(SWIG_UnknownError, "C++ anonymous exception");
  }
}

%include "seiscomp/config/symboltable.h"
%include "seiscomp/config/config.h"

%template(VectorStr) std::vector<std::string>;
%template(VectorInt) std::vector<int>;
%template(VectorDouble) std::vector<double>;
%template(VectorBool) std::vector<bool>;
