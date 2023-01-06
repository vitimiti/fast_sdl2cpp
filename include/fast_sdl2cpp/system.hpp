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

#ifndef FAST_SDL2_CPP_SYSTEM_HPP
#define FAST_SDL2_CPP_SYSTEM_HPP

#include <SDL.h>

#include <advanced_types/optional.hpp>

#include <preproc_config/declaration.hpp>
#include <preproc_config/export.hpp>

#include "fast_sdl2cpp/error.hpp"
#include "fast_sdl2cpp/subsystems.hpp"

namespace fsdl2cpp {
API_EXPORT constexpr auto DECLARATION_STD_CALL
initialize(subsystems const& flags) -> adv_t::optional_error_t {
  if (auto error_code = SDL_Init(static_cast<std::uint32_t>(flags));
      error_code < 0) {
    return adv_t::error_t(get_error(), error_code);
  }

  return std::nullopt;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL
initialize_subsystem(subsystems const& flags) -> adv_t::optional_error_t {
  if (auto error_code = SDL_InitSubSystem(static_cast<std::uint32_t>(flags));
      error_code < 0) {
    return adv_t::error_t(get_error(), error_code);
  }

  return std::nullopt;
}

API_EXPORT constexpr auto DECLARATION_STD_CALL
quit_subsystem(subsystems const& flags) {
  SDL_QuitSubSystem(static_cast<std::uint32_t>(flags));
}

API_EXPORT constexpr auto DECLARATION_STD_CALL
was_init(subsystems const& flags) {
  return static_cast<subsystems>(
      SDL_WasInit(static_cast<std::uint32_t>(flags)));
}

API_EXPORT constexpr auto DECLARATION_STD_CALL quit() { SDL_Quit(); }
} // namespace fsdl2cpp

#endif // FAST_SDL2_CPP_SYSTEM_HPP