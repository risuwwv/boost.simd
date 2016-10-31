//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_MASKED_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_MASKED_HPP_INCLUDED

#include <boost/simd/function/if_else_zero.hpp>

namespace boost { namespace simd
{
  template<typename Pack, typename Mask>
  struct masked
  {
    BOOST_FORCEINLINE masked() {}
    BOOST_FORCEINLINE masked(Pack const& p, Mask const& m) : value_(p), mask_(m) {}

    BOOST_FORCEINLINE operator Pack() const
    {
      return if_else_zero(mask_, value_);
    }

    private:
    Pack value_;
    Mask mask_;
  };
} }

/*
namespace boost { namespace simd
{
  template<typename T> struct logical_ : boost::dispatch::fundamental_<T>
  {
    using parent = boost::dispatch::fundamental_<T>;
  };
} }

namespace boost { namespace dispatch
{
  namespace ext
  {
    template<typename T> struct model_of<boost::simd::masked<P,C>>
    {
      template<typename X> struct apply { using type = boost::simd::masked<P,C>; };
    };

    template<typename T> struct value_of<boost::simd::masked<P,C>> : value_of<P> {};

    template<typename T, typename Origin>
    struct property_of<boost::simd::logical<T>,Origin>
    {
      using type = boost::simd::logical_<Origin>;
    };

    template<typename T>
    struct scalar_of< simd::logical<T> >
    {
      using type = boost::simd::logical<T>;
    };
} } }
*/
#endif
