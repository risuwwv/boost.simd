//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/detail/mask.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{

}

template<typename P>
P f(P const& p)
{
  return p + 3;
}

STF_CASE("Foo")
{
  pack<float,4> x{1,2,3,4};
  pack<int,4> i{1,5,-7,12};

  std::cout << x << "\n";
  std::cout << x(i >3) << "\n";

  x(i > 3)  = 9;
  std::cout << x << "\n";

  ++x(i == 12);
  std::cout << x << "\n";

  --x(i == 1);
  std::cout << x << "\n";

  x(i < 0)----;
  std::cout << x << "\n";

  x(i % 3)++;
  std::cout << x << "\n";

 // auto u = f( x(i>4) );
  //std::cout << u << "\n";
}
