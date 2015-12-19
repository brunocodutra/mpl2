// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal.hpp>

#include <type_traits>

#include "example.hpp"

ANONYMOUS(namespace)
{
/// [ex1]
using num = std::false_type;
/// [ex1]

static_assert(metal::is_number<num>::value, "");
}

ANONYMOUS(namespace)
{
/// [ex2]
using num = std::integral_constant<int, -1>;
/// [ex2]

static_assert(metal::is_number<num>::value, "");
}

ANONYMOUS(namespace)
{
/// [nex1]
struct num :
    std::true_type
{};
/// [nex1]

static_assert(!metal::is_number<num>::value, "");
}

