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

#ifndef FAST_SDL2_CPP_ERROR_HPP
#define FAST_SDL2_CPP_ERROR_HPP

#include <string_view>

#include <SDL.h>

#include <advanced_types/optional.hpp>

#include <preproc_config/declaration.hpp>
#include <preproc_config/export.hpp>

namespace fsdl2cpp {
API_EXPORT constexpr auto DECLARATION_STD_CALL get_error() {
  return std::string_view{SDL_GetError()};
}

template <typename... Args>
API_EXPORT constexpr auto DECLARATION_STD_CALL
set_error(std::string_view const& fmt_str) {
  return SDL_SetError(fmt_str.data(), Args);
}

API_EXPORT constexpr auto DECLARATION_STD_CALL clear_error() {
  SDL_ClearError();
}
} // namespace fsdl2cpp

#endif // FAST_SDL2_CPP_ERROR_HPP