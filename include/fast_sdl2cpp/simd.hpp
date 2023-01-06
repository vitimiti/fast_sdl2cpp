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

#ifndef FAST_SDL2_CPP_SIMD_HPP
#define FAST_SDL2_CPP_SIMD_HPP

#include <cstdint>
#include <functional>
#include <memory>

#include <SDL.h>

#include <advanced_types/variant.hpp>

#include <preproc_config/declaration.hpp>
#include <preproc_config/export.hpp>

#include "fast_sdl2cpp/detail/types.hpp"
#include "fast_sdl2cpp/error.hpp"

namespace fsdl2cpp {
API_EXPORT constexpr auto DECLARATION_STD_CALL simd_get_alignment()
    -> std::size_t {
  return SDL_SIMDGetAlignment();
}

API_EXPORT inline auto DECLARATION_STD_CALL simd_alloc(std::size_t const length)
    -> adv_t::object_or_error_t<std::unique_ptr<
        detail::simd_mem_buffer_t,
        std::function<void(detail::simd_mem_buffer_t*)>>> { // NOLINT
  auto result =
      std::unique_ptr<detail::simd_mem_buffer_t,
                      std::function<void(detail::simd_mem_buffer_t*)>>(
          static_cast<detail::simd_mem_buffer_t*>(SDL_SIMDAlloc(length)),
          [](detail::simd_mem_buffer_t* ptr) {
            SDL_SIMDFree(static_cast<void*>(ptr));
          });

  if (!result) {
    return adv_t::error_t(get_error());
  }

  return result;
}

API_EXPORT inline auto DECLARATION_STD_CALL simd_realloc(
    std::unique_ptr<detail::simd_mem_buffer_t,
                    std::function<void(detail::simd_mem_buffer_t*)>>& memory,
    std::size_t const                                                 length)
    -> adv_t::object_or_error_t<
        std::unique_ptr<detail::simd_mem_buffer_t,
                        std::function<void(detail::simd_mem_buffer_t*)>>> {
  auto mem_ptr = memory.release();
  auto result =
      std::unique_ptr<detail::simd_mem_buffer_t,
                      std::function<void(detail::simd_mem_buffer_t*)>>(
          static_cast<detail::simd_mem_buffer_t*>(
              SDL_SIMDRealloc(static_cast<void*>(mem_ptr), length)),
          [](detail::simd_mem_buffer_t* ptr) {
            SDL_SIMDFree(static_cast<void*>(ptr));
          });

  if (!result) {
    return adv_t::error_t(get_error());
  }

  memory =
      std::unique_ptr<detail::simd_mem_buffer_t,
                      std::function<void(detail::simd_mem_buffer_t*)>>(mem_ptr);

  return result;
}
} // namespace fsdl2cpp

#endif // FAST_SDL2_CPP_SIMD_HPP