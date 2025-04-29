// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// SugarBlock.h: Rcpp R/C++ interface class library -- sugar functions
//
// Copyright (C) 2010 - 2011 Dirk Eddelbuettel and Romain Francois
//
// This file is part of Rcpp.
//
// Rcpp is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

#ifndef RCPP_SUGAR_MATH_H
#define RCPP_SUGAR_MATH_H

inline double rcpp_log(double x) { return ::log(x); }
inline double rcpp_log10(double x) { return ::log10(x); }
inline double rcpp_sqrt(double x) { return ::sqrt(x); }
inline double rcpp_sin(double x) { return ::sin(x); }
inline double rcpp_sinh(double x) { return ::sinh(x); }
inline double rcpp_tan(double x) { return ::tan(x); }
inline double rcpp_tanh(double x) { return ::tanh(x); }
inline double rcpp_fabs(double x) { return ::fabs(x); }
inline double rcpp_expm1(double x) { return ::expm1(x); }
inline double rcpp_log1p(double x) { return ::log1p(x); }
inline double rcpp_cos(double x) { return ::cos(x); }
inline double rcpp_cosh(double x) { return ::cosh(x); }
inline double rcpp_floor(double x) { return ::floor(x); }
inline double rcpp_ceil(double x) { return ::ceil(x); }
inline double rcpp_exp(double x) { return ::exp(x); }
inline double rcpp_acos(double x) { return ::acos(x); }
inline double rcpp_asin(double x) { return ::asin(x); }
inline double rcpp_atan(double x) { return ::atan(x); }

VECTORIZED_MATH_1(exp,rcpp_exp)
VECTORIZED_MATH_1(acos,rcpp_acos)
VECTORIZED_MATH_1(asin,rcpp_asin)
VECTORIZED_MATH_1(atan,rcpp_atan)
VECTORIZED_MATH_1(ceil,rcpp_ceil)
VECTORIZED_MATH_1(ceiling,rcpp_ceil)
VECTORIZED_MATH_1(cos,rcpp_cos)
VECTORIZED_MATH_1(cosh,rcpp_cosh)
VECTORIZED_MATH_1(floor,rcpp_floor)
VECTORIZED_MATH_1(log,rcpp_log)
VECTORIZED_MATH_1(log10,rcpp_log10)
VECTORIZED_MATH_1(sqrt,rcpp_sqrt)
VECTORIZED_MATH_1(sin,rcpp_sin)
VECTORIZED_MATH_1(sinh,rcpp_sinh)
VECTORIZED_MATH_1(tan,rcpp_tan)
VECTORIZED_MATH_1(tanh,rcpp_tanh)

VECTORIZED_MATH_1(abs,rcpp_fabs)

VECTORIZED_MATH_1(gamma      , ::Rf_gammafn     )
VECTORIZED_MATH_1(lgamma     , ::Rf_lgammafn    )
VECTORIZED_MATH_1(digamma    , ::Rf_digamma     )
VECTORIZED_MATH_1(trigamma   , ::Rf_trigamma    )
VECTORIZED_MATH_1(tetragamma , ::Rf_tetragamma  )
VECTORIZED_MATH_1(pentagamma , ::Rf_pentagamma  )
VECTORIZED_MATH_1(expm1      , rcpp_expm1          )
VECTORIZED_MATH_1(log1p      , rcpp_log1p          )

namespace Rcpp{
    namespace internal{
        extern "C" inline double factorial( double x ){ return ::Rf_gammafn( x + 1.0 ) ; }
        extern "C" inline double lfactorial( double x ){ return ::Rf_lgammafn( x + 1.0 ) ; }
    }
}
VECTORIZED_MATH_1(factorial  , ::Rcpp::internal::factorial   )
VECTORIZED_MATH_1(lfactorial , ::Rcpp::internal::lfactorial  )

SUGAR_BLOCK_2(choose    , ::Rf_choose   )
SUGAR_BLOCK_2(lchoose   , ::Rf_lchoose  )
SUGAR_BLOCK_2(beta      , ::Rf_beta     )
SUGAR_BLOCK_2(lbeta     , ::Rf_lbeta    )
SUGAR_BLOCK_2(psigamma  , ::Rf_psigamma )

VECTORIZED_MATH_1(trunc, ::Rf_ftrunc) 		// truncates to zero (cf Writing R Extension, 6.7.3 Numerical Utilities)
SUGAR_BLOCK_2(round,     ::Rf_fround)           // rounds 'x' to 'digits' decimals digits (used by R's round())
SUGAR_BLOCK_2(signif,    ::Rf_fprec)            // rounds 'x' to 'digits' significant digits (used by R's signif())

#endif
