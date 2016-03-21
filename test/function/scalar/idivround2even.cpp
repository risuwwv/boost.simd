//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/idiv.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>

STF_CASE_TPL (" idivround2evenreal",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::idivround2even;
  using r_t = decltype(idivround2even(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t,  bd::as_integer_t<T>);

  STF_EQUAL(idiv(bs::Inf<T>(), bs::Inf<T>(), bs::round2even), bs::Zero<r_t>());
  STF_EQUAL(idiv(bs::Minf<T>(), bs::Minf<T>(), bs::round2even), bs::Zero<r_t>());
  STF_EQUAL(idiv(bs::Nan<T>(), bs::Nan<T>(), bs::round2even), bs::Zero<r_t>());
#endif
 STF_EQUAL(idiv(bs::Mone<T>(), bs::Mone<T>(), bs::round2even), bs::One<r_t>());
  STF_EQUAL(idiv(bs::Mone<T>(),bs::Zero<T>(), bs::round2even), bs::Minf<r_t>());
  STF_EQUAL(idiv(bs::One<T>(), bs::One<T>(), bs::round2even), bs::One<r_t>());
  STF_EQUAL(idiv(bs::One<T>(),bs::Zero<T>(), bs::round2even), bs::Valmax<r_t>());
  STF_EQUAL(idiv(bs::One<T>(),bs::Mzero<T>(), bs::round2even), bs::Valmin<r_t>());
  STF_EQUAL(idiv(bs::Zero<T>(),bs::Zero<T>(), bs::round2even), bs::Zero<r_t>());
  STF_EQUAL(idiv(T(4),T(3), bs::round2even), r_t(1));
  STF_EQUAL(idiv(T(-4),T(-3), bs::round2even), r_t(1));
  STF_EQUAL(idiv(T(-4),T(3), bs::round2even), r_t(-1));
  STF_EQUAL(idiv(T(4),T(-3), bs::round2even), r_t(-1));
} // end of test for floating_

STF_CASE_TPL (" idivunsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::idiv;
  using r_t = decltype(idiv(T(), T()));

  STF_EQUAL(idiv(T(4),T(3), bs::round2even), T(1));
  STF_EQUAL(idiv(bs::One<T>(), bs::One<T>(), bs::round2even), bs::One<r_t>());
  STF_EQUAL(idiv(bs::One<T>(), bs::Zero<T>(), bs::round2even), bs::Valmax<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" idivsigned_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::idiv;
  using r_t = decltype(idiv(T(), T()));

  STF_EQUAL(idiv(T(4),T(3), bs::round2even), r_t(1));
  STF_EQUAL(idiv(T(-4),T(-3), bs::round2even), r_t(1));
  STF_EQUAL(idiv(T(-4),T(3), bs::round2even), r_t(-1));
  STF_EQUAL(idiv(T(4),T(-3), bs::round2even), r_t(-1));
  STF_EQUAL(idiv(bs::Mone<T>(), bs::Mone<T>(), bs::round2even), bs::One<r_t>());
  STF_EQUAL(idiv(bs::One<T>(), bs::One<T>(), bs::round2even), bs::One<r_t>());
  STF_EQUAL(idiv(bs::One<T>(), bs::Zero<T>(), bs::round2even), bs::Valmax<r_t>());
  STF_EQUAL(idiv(bs::Mone<T>(), bs::Zero<T>(), bs::round2even), bs::Valmin<r_t>());
} // end of test for signed_int_

