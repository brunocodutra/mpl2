// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/back.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::back>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::back>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::back>, PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::back>, VECT(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::back>, LIST(M)>), (BOOL(M > 0))); \
    ASSERT((metal::is_invocable<test::lambda<metal::back>, MAP(M)>), (BOOL(M > 0))); \
    ASSERT((metal::is_invocable<test::lambda<metal::back>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::back>, LBD(_)>), (FALSE)); \
    ASSERT((metal::back<PAIR(M)>), (VAL(M))); \
    ASSERT((metal::back<VECT(M)>), (NA())); \
    ASSERT((metal::back<LIST(INC(M))>), (VAL(M))); \
    ASSERT((metal::back<MAP(INC(M))>), (PAIR(M))); \
/**/

GEN(MATRIX)

