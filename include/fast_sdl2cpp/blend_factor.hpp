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

#ifndef FAST_SDL2_CPP_BLEND_FACTOR_HPP
#define FAST_SDL2_CPP_BLEND_FACTOR_HPP

#include <SDL.h>

namespace fsdl2cpp {
enum class blend_factor {
  zero                = SDL_BLENDFACTOR_ZERO,
  one                 = SDL_BLENDFACTOR_ONE,
  src_color           = SDL_BLENDFACTOR_SRC_COLOR,
  one_minus_src_color = SDL_BLENDFACTOR_ONE_MINUS_SRC_COLOR,
  src_alpha           = SDL_BLENDFACTOR_SRC_ALPHA,
  one_minus_src_alpha = SDL_BLENDFACTOR_ONE_MINUS_SRC_ALPHA,
  dst_color           = SDL_BLENDFACTOR_DST_COLOR,
  one_minus_dst_color = SDL_BLENDFACTOR_ONE_MINUS_DST_COLOR,
  dst_alpha           = SDL_BLENDFACTOR_DST_ALPHA,
  one_minus_dst_alpha = SDL_BLENDFACTOR_ONE_MINUS_DST_ALPHA
};
}

#endif // FAST_SDL2_CPP_BLEND_FACTOR_HPP