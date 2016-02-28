// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ENUMERATE_HPP
#define METAL_NUMBER_ENUMERATE_HPP

#include <metal/detail/nil.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename = nil, typename = nil>
        struct enumerate;
    }

    /// \ingroup number
    /// Generates a \list of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \value `size`
    /// \code
    ///     using result = metal::enumerate<size>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `size` is a model of \number, then equivalent to
    ///     \code
    ///         struct result :
    ///             metal::enumerate<metal::number<size::value_type, 0>, size>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// ________________________________________________________________________
    ///
    /// For any \values `start` and `size`
    /// \code
    ///     using result = metal::enumerate<start, size>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     Equivalent to
    ///     \code
    ///         struct result :
    ///             metal::enumerate<start, size, metal::integer<1>>
    ///         {};
    ///     \endcode
    ///
    /// ________________________________________________________________________
    ///
    /// For any \values `start`, `size` and `stride`
    /// \code
    ///     using result = metal::enumerate<start, size, stride>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `start`, `size` and `stride` are models of \number and
    ///     `size` is null, then equivalent to
    ///     \code
    ///         struct result :
    ///             metal::list<>
    ///         {};
    ///     \endcode
    ///     otherwise, if `start`, `size` and `stride` are models of \number and
    ///     `size` is positive, then equivalent to
    ///     \code
    ///         struct result :
    ///             metal::list<
    ///                 start,
    ///                 metal::number<start::value_type, start::value + stride::value>,
    ///                 metal::number<start::value_type, start::value + 2*stride::value>,
    ///                 ...,
    ///                 metal::number<start::value_type, start::value + (size::value - 1)*stride::value>,
    ///             >
    ///         {};
    ///     \endcode
    ///     otherwise, if `start`, `size` and `stride` are models of \number and
    ///     `size` is negative, then equivalent to
    ///     \code
    ///         struct result :
    ///             metal::list<
    ///                 start,
    ///                 metal::number<start::value_type, start::value - stride::value>,
    ///                 metal::number<start::value_type, start::value - 2*stride::value>,
    ///                 ...,
    ///                 metal::number<start::value_type, start::value - (size::value - 1)*stride::value>,
    ///             >
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// Example
    /// -------
    /// \snippet number/enumerate.cpp enumerate
    ///
    /// See Also
    /// --------
    /// \see number
    template<typename... _>
    using enumerate = detail::enumerate<_...>;

    /// \ingroup number
    /// Eager adaptor for \ref enumerate.
    template<typename... _>
    using enumerate_t = typename metal::enumerate<_...>::type;
}

#include <metal/number/number.hpp>
#include <metal/list/list.hpp>
#include <metal/list/join.hpp>

namespace metal
{
    namespace detail
    {
        template<typename t, t... vs>
        struct numbers :
            list<number<t, vs>...>
        {};

        template<typename, typename, typename>
        struct stretch;

        template<typename u, u a, typename v, v b>
        struct stretch<list<>, number<u, a>, number<v, b>> :
            list<>
        {};

        template<typename t, t... ns, typename u, u a, typename v, v b>
        struct stretch<list<number<t, ns>...>, number<u, a>, number<v, b>> :
            numbers<v, b + a*ns...>
        {};

        template<typename, typename, typename>
        struct enumerate
        {};

        template<typename t, t start, typename u, u size, typename v, v stride>
        struct enumerate<number<t, start>, number<u, size>, number<v, stride>> :
            stretch<
                enumerate_t<number<long long, size>>,
                number<long long, stride>,
                number<t, start>
            >
        {};

        template<typename t, t start, typename u, u size>
        struct enumerate<number<t, start>, number<u, size>> :
            enumerate<number<t, start>, number<u, size>, integer<1>>
        {};

        template<typename t, t size>
        struct enumerate<number<t, size>> :
            join<
                enumerate_t<number<t, size/2>>,
                enumerate_t<number<t, size/2>, number<t, size - size/2>>
            >
        {};

        template<typename t>
        struct enumerate<number<t, t(1)>> :
            list<number<t, 0>>
        {};

        template<typename t>
        struct enumerate<number<t, t(-1)>> :
            list<number<t, 0>>
        {};

        template<typename t>
        struct enumerate<number<t, t(0)>> :
            list<>
        {};
    }
}

#endif
