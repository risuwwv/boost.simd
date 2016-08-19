//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/atan2d.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/mhalf.hpp>

STF_CASE_TPL (" atan2d",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::atan2d;

  using r_t = decltype(atan2d(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(atan2d(bs::Inf<T>(), bs::Inf<T>()), T(45), 0.5);
  STF_ULP_EQUAL(atan2d(bs::Inf<T>(),bs::One<T>()), T(90), 0.5);
  STF_ULP_EQUAL(atan2d(bs::Minf<T>(), bs::Minf<T>()), -T(135), 0.5);
  STF_ULP_EQUAL(atan2d(bs::Minf<T>(),bs::One<T>()), -T(90), 0.5);
  STF_ULP_EQUAL(atan2d(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2d(bs::Nan<T>(), bs::Zero<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2d(bs::Zero<T>(), bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2d(bs::One<T>(),bs::Inf<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2d(bs::One<T>(),bs::Minf<T>()), T(180), 0.5);
#endif
  STF_ULP_EQUAL(atan2d(bs::Half<T>(), bs::Half<T>()), T(45), 0.5);
  STF_ULP_EQUAL(atan2d(bs::Mhalf<T>(), bs::Mhalf<T>()), -T(135), 0.5);
  STF_ULP_EQUAL(atan2d(bs::Mone<T>(), bs::Mone<T>()), -T(135), 0.5);
  STF_ULP_EQUAL(atan2d(bs::One<T>(), bs::One<T>()), T(45), 0.5);
  STF_ULP_EQUAL(atan2d(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>(), 0.5);
}
