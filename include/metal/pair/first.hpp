// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_PAIR_FIRST_HPP
#define METAL_PAIR_FIRST_HPP

#include <metal/pair/pair.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    /// \ingroup pair
    /// Returns the first element of a \pair.
    ///
    /// Usage
    /// -----
    /// For any \pair `pair`
    /// \code
    ///     using result = metal::first<pair>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     If `pair` contains \values `x` and `y` in that order, then
    ///     \code
    ///         using result = x;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet pair.cpp first
    ///
    /// See Also
    /// --------
    /// \see pair, second, at
    template<typename seq>
    using first = if_<is_pair<seq>, apply<_1, seq>>;
}

#endif
