// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_INVOKE_HPP
#define METAL_LAMBDA_INVOKE_HPP

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename...>
    struct invoke
    {};

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref invoke.
    template<typename... args>
    using invoke_t = typename invoke<args...>::type;
}

#include <metal/lambda/defer.hpp>
#include <metal/optional/eval.hpp>
#include <metal/optional/optional.hpp>
#include <metal/optional/nothing.hpp>

namespace metal
{
    template<typename lbd, typename... args>
    struct invoke<lbd, args...> :
        optional<eval<defer<lbd, args...>, nothing>>
    {};
}

#endif
