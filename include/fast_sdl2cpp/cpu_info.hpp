//================================================================================================//
// The MIT License (MIT)
//
// Copyright (c) 2023 Victor Matia <vmatir@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the “Software”), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//================================================================================================//

#ifndef FAST_SDL2_CPP_CPU_INFO_HPP
#define FAST_SDL2_CPP_CPU_INFO_HPP

#include <cstdint>

#include <SDL.h>

#include <preproc_config/declaration.hpp>
#include <preproc_config/export.hpp>

namespace fsdl2cpp {
constexpr std::int32_t cache_line_size = SDL_CACHELINE_SIZE;

API_EXPORT constexpr auto DECLARATION_STD_CALL get_cpu_count() -> std::int32_t {
  return SDL_GetCPUCount();
}

API_EXPORT constexpr auto DECLARATION_STD_CALL get_cpu_cache_line_size()
    -> std::int32_t {
  return SDL_GetCPUCacheLineSize();
}

API_EXPORT constexpr auto DECLARATION_STD_CALL has_rdtsc() {
  return SDL_HasRDTSC() == SDL_TRUE;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL has_altivec() {
  return SDL_HasAltiVec() == SDL_TRUE;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL has_mmx() {
  return SDL_HasMMX() == SDL_TRUE;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL has_3dnow() {
  return SDL_Has3DNow() == SDL_TRUE;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL has_sse() {
  return SDL_HasSSE() == SDL_TRUE;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL has_sse2() {
  return SDL_HasSSE2() == SDL_TRUE;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL has_sse3() {
  return SDL_HasSSE3() == SDL_TRUE;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL has_sse41() {
  return SDL_HasSSE41() == SDL_TRUE;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL has_sse42() {
  return SDL_HasSSE42() == SDL_TRUE;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL has_avx() {
  return SDL_HasAVX() == SDL_TRUE;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL has_avx2() {
  return SDL_HasAVX2() == SDL_TRUE;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL has_avx512f() {
  return SDL_HasAVX512F() == SDL_TRUE;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL has_arm_simd() {
  return SDL_HasARMSIMD() == SDL_TRUE;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL has_neon() {
  return SDL_HasNEON() == SDL_TRUE;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL get_system_ram()
    -> std::int32_t {
  return SDL_GetSystemRAM();
}
} // namespace fsdl2cpp

#endif // FAST_SDL2_CPP_CPU_INFO_HPP