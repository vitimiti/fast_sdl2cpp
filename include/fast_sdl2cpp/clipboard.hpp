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

#ifndef FAST_SDL2_CPP_CLIPBOARD_HPP
#define FAST_SDL2_CPP_CLIPBOARD_HPP

#include <optional>
#include <string_view>

#include <SDL.h>

#include <advanced_types/failure.hpp>

#include <preproc_config/declaration.hpp>
#include <preproc_config/export.hpp>

#include "fast_sdl2cpp/error.hpp"

namespace fsdl2cpp {
API_EXPORT constexpr auto DECLARATION_STD_CALL
set_clipboard_text(std::string_view const& text) -> adv_t::optional_error_t {
  if (auto error_code = SDL_SetClipboardText(text.data()); error_code < 0) {
    return std::make_optional<adv_t::error_t>(get_error(), error_code);
  }

  return std::nullopt;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL get_clipboard_text() {
  return std::string_view{SDL_GetClipboardText()};
}

API_EXPORT constexpr auto DECLARATION_STD_CALL has_clipboard_text() {
  return SDL_HasClipboardText() == SDL_TRUE;
}
} // namespace fsdl2cpp

#endif // FAST_SDL2_CPP_CLIPBOARD_HPP