/*
 *  Copyright 2020 Patrick Stotko
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef STDGPU_COMPILER_H
#define STDGPU_COMPILER_H

/**
 * \file stdgpu/compiler.h
 */



namespace stdgpu
{

/**
 * \hideinitializer
 * \brief Host compiler: Unknown
 */
#define STDGPU_HOST_COMPILER_UNKNOWN -1
/**
 * \hideinitializer
 * \brief Host compiler: GCC
 */
#define STDGPU_HOST_COMPILER_GCC      0
/**
 * \hideinitializer
 * \brief Host compiler: Clang
 */
#define STDGPU_HOST_COMPILER_CLANG    1
/**
 * \hideinitializer
 * \brief Host compiler: Microsoft Visual C++
 */
#define STDGPU_HOST_COMPILER_MSVC     2

/**
 * \hideinitializer
 * \brief Device compiler: Unknown
 */
#define STDGPU_DEVICE_COMPILER_UNKNOWN -1
/**
 * \hideinitializer
 * \brief Device compiler: NVCC
 */
#define STDGPU_DEVICE_COMPILER_NVCC     0

/**
 * \def STDGPU_HOST_COMPILER
 * \hideinitializer
 * \brief The detected host compiler
 */
#if defined(__GNUC__) && !defined(__clang__)
    #define STDGPU_HOST_COMPILER STDGPU_HOST_COMPILER_GCC
#elif defined(__clang__)
    #define STDGPU_HOST_COMPILER STDGPU_HOST_COMPILER_CLANG
#elif defined(_MSC_VER)
    #define STDGPU_HOST_COMPILER STDGPU_HOST_COMPILER_MSVC
#else
    #define STDGPU_HOST_COMPILER STDGPU_HOST_COMPILER_UNKNOWN
#endif

/**
 * \def STDGPU_DEVICE_COMPILER
 * \hideinitializer
 * \brief The detected device compiler
 */
#if defined(__CUDACC__)
    #define STDGPU_DEVICE_COMPILER STDGPU_DEVICE_COMPILER_NVCC
#else
    #define STDGPU_DEVICE_COMPILER STDGPU_DEVICE_COMPILER_UNKNOWN
#endif


} // namespace stdgpu



#endif // STDGPU_COMPILER_H