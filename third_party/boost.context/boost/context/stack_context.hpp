
//          Copyright Oliver Kowalke 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONTEXT_STACK_CONTEXT_H
#define BOOST_CONTEXT_STACK_CONTEXT_H

#include <cstddef>

#include <boost/config.hpp>

#include <boost/context/detail/config.hpp>

#ifdef BOOST_HAS_ABI_HEADERS
#  include BOOST_ABI_PREFIX
#endif

namespace boost {
namespace context {

#if defined(BOOST_USE_SEGMENTED_STACKS)
struct stack_context {
    typedef void *  segments_context[BOOST_CONTEXT_SEGMENTS];

    std::size_t             size;
    void                *   sp;
    segments_context        segments_ctx;
#if defined(BOOST_USE_VALGRIND)
    unsigned                valgrind_stack_id;
#endif

#if defined(BOOST_NO_CXX11_CONSTEXPR)
    stack_context() :
#else
    constexpr stack_context() :
#endif
        size( 0),
        sp( 0),
        segments_ctx()
#if defined(BOOST_USE_VALGRIND)
        , valgrind_stack_id( 0)
#endif
        {}
};
#else
struct stack_context {
    std::size_t             size;
    void                *   sp;
#if defined(BOOST_USE_VALGRIND)
    unsigned                valgrind_stack_id;
#endif

#if defined(BOOST_NO_CXX11_CONSTEXPR)
    stack_context() :
#else
    constexpr stack_context() :
#endif
        size( 0),
        sp( 0)
#if defined(BOOST_USE_VALGRIND)
        , valgrind_stack_id( 0)
#endif
    {}
};
#endif

}}

#ifdef BOOST_HAS_ABI_HEADERS
#  include BOOST_ABI_SUFFIX
#endif

#endif // BOOST_CONTEXT_STACK_CONTEXT_H
