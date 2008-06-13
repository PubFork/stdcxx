/***************************************************************************
 *
 * This is an internal header file used to implement the C++ Standard
 * Library. It should never be #included directly by a program.
 *
 * $Id$
 *
 ***************************************************************************
 *
 * Licensed to the Apache Software  Foundation (ASF) under one or more
 * contributor  license agreements.  See  the NOTICE  file distributed
 * with  this  work  for  additional information  regarding  copyright
 * ownership.   The ASF  licenses this  file to  you under  the Apache
 * License, Version  2.0 (the  "License"); you may  not use  this file
 * except in  compliance with the License.   You may obtain  a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the  License is distributed on an  "AS IS" BASIS,
 * WITHOUT  WARRANTIES OR CONDITIONS  OF ANY  KIND, either  express or
 * implied.   See  the License  for  the  specific language  governing
 * permissions and limitations under the License.
 *
 * Copyright 2008 Rogue Wave Software, Inc.
 *
 **************************************************************************/

#ifndef _RWSTD_META_TRANS_ARR_H_INCLUDED
#define _RWSTD_META_TRANS_ARR_H_INCLUDED

#include <rw/_defs.h>

_RWSTD_NAMESPACE (__rw) {

/**
 * TransformationTrait strips one dimension from an array type, leaving
 * other types as-is. The primary template is for non-array types.
 */
template <class _TypeT>
struct __rw_remove_extent
{
    typedef _TypeT type;
};

/**
 * TransformationTrait strips one dimension from an array type, leaving
 * other types as-is. This specialization is for array types of bounded
 * size.
 */
template <class _TypeT, size_t _Size>
struct __rw_remove_extent<_TypeT [_Size]>
{
    typedef _TypeT type;
};

/**
 * TransformationTrait strips one dimension from an array type, leaving
 * other types as-is. This specialization is for array types of unbounded
 * size.
 */
template <class _TypeT>
struct __rw_remove_extent<_TypeT []>
{
    typedef _TypeT type;
};

//#define _RWSTD_REMOVE_EXTENT(T) _RW::__rw_remove_extent<T>::type

/**
 * TransformationTrait strips one dimension from an array type, leaving
 * other types as-is. The primary template is for non-array types. The
 * member typedef type will be the same as _TypeT.
 */
template <class _TypeT>
struct __rw_remove_all_extents
{
    typedef _TypeT type;
};

/**
 * TransformationTrait strips all dimensions from an array type, leaving
 * other types as-is. This specialization is for array types of bounded
 * size.
 */
template <class _TypeT, size_t _Size>
struct __rw_remove_all_extents<_TypeT [_Size]>
{
    typedef typename __rw_remove_all_extents<_TypeT>::type type;
};

/**
 * TransformationTrait strips one dimension from an array type, leaving
 * other types as-is. This specialization is for array types of unbounded
 * size.
 */
template <class _TypeT>
struct __rw_remove_all_extents<_TypeT []>
{
    typedef typename __rw_remove_all_extents<_TypeT>::type type;
};

//#define _RWSTD_REMOVE_ALL_EXTENTS(T) _RW::__rw_remove_all_extents<T>::type

} // namespace __rw


#endif   // _RWSTD_META_TRANS_ARR_H_INCLUDED