// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/lambda.hpp>
#include <boost/metal/functional/placeholders.hpp>
#include <boost/metal/functional/call.hpp>
#include <boost/metal/functional/verbatim.hpp>
#include <boost/metal/functional/function.hpp>
#include <boost/metal/functional/traits.hpp>

#include "test/types.hpp"
#include "test/wrap.hpp"
#include "test/main.hpp"

using namespace boost::metal;
using namespace boost::metal::placeholders;

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::a>>, test::a>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::b>>, test::b>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::c>>, test::c>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::d>>, test::d>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::e>>, test::e>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::f>>, test::f>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::g>>, test::g>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::h>>, test::h>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::i>>, test::i>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::j>>, test::j>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::a>>>, test::a>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::b>>>, test::b>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::c>>>, test::c>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::d>>>, test::d>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::e>>>, test::e>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::f>>>, test::f>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::g>>>, test::g>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::h>>>, test::h>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::i>>>, test::i>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::j>>>, test::j>));

BOOST_METAL_ASSERT((not_<is_callable_t<lambda<test::call<>>>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::evaluable<>>>, test::evaluable<>::type>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::call<>>>>, test::call<>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::evaluable<>>>>, test::evaluable<>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrapper>, void>, test::wrapper>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::wrapper>>, void>, test::wrapper>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<function<test::wrapper>>, void>, function<test::wrapper>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<lambda<std::add_pointer<_1>>>, void>, lambda<void*>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<lambda<std::add_pointer<_1>>>>, void>, lambda<std::add_pointer<_1>>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<function<lambda<std::add_pointer<_1>>>>, void>, function<lambda<std::add_pointer<_1>>>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<lambda<std::add_pointer<_1>>, void>>, void*>, void**>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<verbatim<lambda<std::add_pointer<_1>>>, void>>, void*>, void*>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<function<lambda<std::add_pointer<_1>>>, void>>, void*>, void*>));

BOOST_METAL_ASSERT((not_<is_callable_t<lambda<_0>>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<_1>, short, int, long, long long>, short>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<_2>, short, int, long, long long>, int>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<_3>, short, int, long, long long>, long>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<_4>, short, int, long, long long>, long long>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<_0>>, short, int, long, long long>, _0>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<_1>>, short, int, long, long long>, _1>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<_2>>, short, int, long, long long>, _2>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<_3>>, short, int, long, long long>, _3>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<_4>>, short, int, long, long long>, _4>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<function<_0>>, short, int, long, long long>, function<_0>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<function<_1>>, short, int, long, long long>, function<_1>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<function<_2>>, short, int, long, long long>, function<_2>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<function<_3>>, short, int, long, long long>, function<_3>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<function<_4>>, short, int, long, long long>, function<_4>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_0>>, short, int, long, long long>, test::wrap<short, int, long, long long>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_1>>, short, int, long, long long>, test::wrap<short>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_1, _2>>, short, int, long, long long>, test::wrap<short, int>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_1, _2, _3>>, short, int, long, long long>, test::wrap<short, int, long>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_1, _2, _3, _4>>, short, int, long, long long>, test::wrap<short, int, long, long long>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::wrap<_0>>>, short, int, long, long long>, test::wrap<_0>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::wrap<_1>>>, short, int, long, long long>, test::wrap<_1>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::wrap<_1, _2>>>, short, int, long, long long>, test::wrap<_1, _2>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::wrap<_1, _2, _3>>>, short, int, long, long long>, test::wrap<_1, _2, _3>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::wrap<_1, _2, _3, _4>>>, short, int, long, long long>, test::wrap<_1, _2, _3, _4>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<_0>>, test::wrapper, void>, test::wrap<void>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<_0, _0>>, test::wrapper, void>, test::wrap<void, test::wrapper, void>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<_0, _0, _0>>, test::wrapper, void>, test::wrap<void, test::wrapper, void, test::wrapper, void>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<_0, verbatim<_0>>>, test::wrapper, void>, test::wrap<void, _0>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<_0, verbatim<_0>, _0>>, test::wrapper, void>, test::wrap<void, _0, test::wrapper, void>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<_0, function<_0>>>, test::wrapper, void>, test::wrap<void, function<_0>>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<_0, function<_0>, _0>>, test::wrapper, void>, test::wrap<void, function<_0>, test::wrapper, void>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<lambda<_1>>, void>, lambda<void>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<lambda<_1>>>, void>, lambda<_1>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<lambda<_1>>, verbatim<_1>>, lambda<verbatim<_1>>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<lambda<_1>>, void>, lambda<void>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<function<lambda<_1>>>, void>, function<lambda<_1>>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<lambda<_1>>, function<_1>>, lambda<function<_1>>>));

using chain = function<lambda<call<lambda<_1>, call<lambda<_2>, _3>>>>;
BOOST_METAL_ASSERT((is_function<chain>));
BOOST_METAL_ASSERT((std::is_same<call_t<chain, std::add_pointer<_1>, std::add_const<_1>, void>, void const*>));
BOOST_METAL_ASSERT((std::is_same<call_t<chain, std::add_const<_1>, std::add_pointer<_1>, void>, void* const>));

using once = function<lambda<call<chain, verbatim<_1>, _1, _2>>>;
BOOST_METAL_ASSERT((is_function<once>));
BOOST_METAL_ASSERT((std::is_same<call_t<once, std::add_pointer<_1>, void>, void*>));

using twice = function<lambda<call<chain, _1, _1, _2>>>;
BOOST_METAL_ASSERT((is_function<twice>));
BOOST_METAL_ASSERT((std::is_same<call_t<twice, std::add_pointer<_1>, void>, void**>));

using thrice = function<lambda<call<once, _1, call<twice, _1, _2>>>>;
BOOST_METAL_ASSERT((is_function<thrice>));
BOOST_METAL_ASSERT((std::is_same<call_t<thrice, std::add_pointer<_1>, void>, void***>));

using ptr2ptr2ptr = function<lambda<call<thrice, verbatim<std::add_pointer<_1>>, _1>>>;
BOOST_METAL_ASSERT((is_function<ptr2ptr2ptr>));
BOOST_METAL_ASSERT((std::is_same<call_t<ptr2ptr2ptr, void>, void***>));
