// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_REPLACE_IF_HPP
#define METAL_LIST_REPLACE_IF_HPP

#include <metal/list/transform.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq, typename lbd, typename val>
    using replace_if = transform<bind<lambda<if_>, lbd, quote<val>, _1>, seq>;
}

#endif
