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

#ifndef FAST_SDL2_CPP_CUSTOM_BLEND_MODE_HPP
#define FAST_SDL2_CPP_CUSTOM_BLEND_MODE_HPP

#include <SDL.h>

#include <preproc_config/declaration.hpp>
#include <preproc_config/export.hpp>

#include "fast_sdl2cpp/blend_factor.hpp"
#include "fast_sdl2cpp/blend_mode.hpp"
#include "fast_sdl2cpp/blend_operation.hpp"

namespace fsdl2cpp {
API_EXPORT constexpr auto DECLARATION_STD_CALL compose_custom_blend_mode(
    blend_factor const& src_color_factor, blend_factor const& dst_color_factor,
    blend_operation const& color_operation,
    blend_factor const& src_alpha_factor, blend_factor const& dst_alpha_factor,
    blend_operation const& alpha_operation) {
  return static_cast<blend_mode>(SDL_ComposeCustomBlendMode(
      static_cast<SDL_BlendFactor>(src_color_factor),
      static_cast<SDL_BlendFactor>(dst_color_factor),
      static_cast<SDL_BlendOperation>(color_operation),
      static_cast<SDL_BlendFactor>(src_alpha_factor),
      static_cast<SDL_BlendFactor>(dst_alpha_factor),
      static_cast<SDL_BlendOperation>(alpha_operation)));
}
} // namespace fsdl2cpp

#endif // FAST_SDL2_CPP_CUSTOM_BLEND_MODE_HPP