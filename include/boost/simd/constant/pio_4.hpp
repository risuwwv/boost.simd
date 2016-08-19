//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_PIO_4_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_PIO_4_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    Constant \f$\frac\pi{4}\f$.

    @par Semantic:

    For type T:

    @code
    T r = Pio_4<T>();
    @endcode

    is similar to:

    @code
    T r = Pi<T>()/Four<T>();
    @endcode

    @return a value of type T

**/
  template<typename T> T Pio_4();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      Constant \f$\frac\pi{4}\f$.

      Generate the  constant pio_4.

      @return The Pio_4 constant for the proper type
    **/
    const boost::dispatch::functor<tag::pio_4_> pio_4 = {};
  }
} }
#endif

#include <boost/simd/constant/definition/pio_4.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>
#include <boost/simd/arch/common/simd/constant/constant_value.hpp>

#endif
