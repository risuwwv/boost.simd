//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_MASKED_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_MASKED_HPP_INCLUDED

#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/function/if_inc.hpp>
#include <boost/simd/function/if_dec.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <type_traits>

namespace boost { namespace simd
{
  template<typename Pack, typename Mask>
  struct masked
  {
    using traits          = typename Pack::traits;
    using storage_type    = typename Pack::storage_type;
    using substorage_type = typename Pack::substorage_type;
    using storage_kind    = typename Pack::storage_kind;
    using value_type      = typename Pack::value_type;
    using size_type       = typename Pack::size_type;

    enum { static_size = Pack::static_size };
    enum { alignment = Pack::alignment };

    BOOST_FORCEINLINE masked() {}
    BOOST_FORCEINLINE masked(Pack& p, Mask const& m) : value_(p), mask_(m) {}

    BOOST_FORCEINLINE Pack value() const { return value_; }
    BOOST_FORCEINLINE Mask mask()  const { return mask_;  }

    /// @brief Assignment operator perform a conditional MOV
    template<typename U> Pack& operator=(U&& src)
    {
      value_ = if_else(mask_, std::forward<U>(src), value_);
      return value_;
    }

    /// @brief Conversion to underlying storage data
    BOOST_FORCEINLINE operator storage_type() const BOOST_NOEXCEPT
    {
      return storage();
    }

    BOOST_FORCEINLINE storage_type const& storage() const BOOST_NOEXCEPT { return value().storage(); }

    template<typename Cond>
    BOOST_FORCEINLINE masked<pack const,pack<Cond,N>> operator()(pack<Cond,N> const& c) const
    {
      return {value_, mask_ && c};
    }

    template<typename Cond>
    BOOST_FORCEINLINE masked<pack,pack<Cond,N>> operator()(pack<Cond,N> const& c)
    {
      return {value_, mask_ && c};
    }

    BOOST_FORCEINLINE Pack& operator++()
    {
      value_ = if_inc(mask_, value_);
      return value_;
    }

    BOOST_FORCEINLINE Pack& operator--()
    {
      value_ = if_dec(mask_, value_);
      return value_;
    }

    BOOST_FORCEINLINE Pack operator++(int) BOOST_NOEXCEPT
    {
      auto that = value_;
      ++(*this);
      return that;
    }

    BOOST_FORCEINLINE Pack operator--(int) BOOST_NOEXCEPT
    {
      auto that = value_;
      --(*this);
      return that;
    }

#if 0
    template <typename Other>
    BOOST_FORCEINLINE pack& operator+=(Other const& other) BOOST_NOEXCEPT
    {
      *this = *this + other;
      return *this;
    }

    template <typename Other>
    BOOST_FORCEINLINE pack& operator-=(Other const& other) BOOST_NOEXCEPT
    {
      *this = *this - other;
      return *this;
    }

    template <typename Other>
    BOOST_FORCEINLINE pack& operator*=(Other const& other) BOOST_NOEXCEPT
    {
      *this = *this * other;
      return *this;
    }

    template <typename Other>
    BOOST_FORCEINLINE pack& operator/=(Other const& other) BOOST_NOEXCEPT
    {
      *this = *this / other;
      return *this;
    }

    template <typename Other>
    BOOST_FORCEINLINE pack& operator%=(Other const& other) BOOST_NOEXCEPT
    {
      *this = *this % other;
      return *this;
    }

    template <typename Other>
    BOOST_FORCEINLINE pack& operator&=(Other const& other) BOOST_NOEXCEPT
    {
      *this = *this & other;
      return *this;
    }

    template <typename Other>
    BOOST_FORCEINLINE pack& operator|=(Other const& other) BOOST_NOEXCEPT
    {
      *this = *this | other;
      return *this;
    }

    template <typename Other>
    BOOST_FORCEINLINE pack& operator^=(Other const& other) BOOST_NOEXCEPT
    {
      *this = *this ^ other;
      return *this;
    }

#endif
    /// @brief Retrieve the pack's cardinal, i.e the number of element in the pack.
    static BOOST_FORCEINLINE size_type size()     BOOST_NOEXCEPT { return static_size; }

    /// @brief Retrieve the pack's maximum size, i.e the number of element in the pack.
    static BOOST_FORCEINLINE size_type max_size() BOOST_NOEXCEPT { return static_size; }

    /// @brief Empty status for pack
    BOOST_FORCEINLINE bool empty() const BOOST_NOEXCEPT { return false; }

    /// @brief Swap data between two packs
    BOOST_FORCEINLINE void swap(masked& rhs) BOOST_NOEXCEPT
    {
      value_.swap(rhs.value_);
      mask_.swap(rhs.mask_);
    }

    private:
    Pack&  value_;
    Mask   mask_;
  };

  template<typename P, typename M>
  std::ostream& operator<<(std::ostream& os, masked<P,M> const& m)
  {
    return os << "{ " << m.value() << " # " << m.mask() << " }";
  }
} }

namespace boost { namespace simd
{
  // Overload for cardinal_of
  template<typename P, typename M>
  struct cardinal_of<masked<P,M>> : cardinal_of<P>
  {};
} }

#endif
