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

#ifndef FAST_SDL2_CPP_SUBSYSTEMS_HPP
#define FAST_SDL2_CPP_SUBSYSTEMS_HPP

#include <cstdint>
#include <ostream>
#include <string>

#include <SDL.h>

namespace fsdl2cpp {
enum class subsystems : std::uint32_t {
  none            = 0x00000000U,
  timer           = SDL_INIT_TIMER,
  audio           = SDL_INIT_AUDIO,
  video           = SDL_INIT_AUDIO,
  joystick        = SDL_INIT_JOYSTICK,
  haptic          = SDL_INIT_HAPTIC,
  game_controller = SDL_INIT_GAMECONTROLLER,
  events          = SDL_INIT_EVENTS,
  sensor          = SDL_INIT_SENSOR,

  no_parachute [[deprecated("For compatibility, this flags will be ignored")]] =
      SDL_INIT_NOPARACHUTE,

  everything = SDL_INIT_EVERYTHING
};

constexpr auto operator|(subsystems const& lhs, subsystems const& rhs) {
  return static_cast<subsystems>(static_cast<std::uint32_t>(lhs) |
                                 static_cast<std::uint32_t>(rhs));
}

constexpr auto operator&(subsystems const& lhs, subsystems const& rhs) {
  return static_cast<subsystems>(static_cast<std::uint32_t>(lhs) &
                                 static_cast<std::uint32_t>(rhs));
}

constexpr auto operator^(subsystems const& lhs, subsystems const& rhs) {
  return static_cast<subsystems>(static_cast<std::uint32_t>(lhs) ^
                                 static_cast<std::uint32_t>(rhs));
}

constexpr auto operator|=(subsystems& lhs, subsystems const& rhs) {
  lhs = lhs | rhs;
  return lhs;
}

constexpr auto operator&=(subsystems& lhs, subsystems const& rhs) {
  lhs = lhs & rhs;
  return lhs;
}

constexpr auto operator^=(subsystems& lhs, subsystems const& rhs) {
  lhs = lhs ^ rhs;
  return lhs;
}

constexpr auto operator~(subsystems const& lhs) {
  return static_cast<subsystems>(~static_cast<std::uint32_t>(lhs));
}

inline auto operator<<(std::ostream& stream, subsystems const& obj)
    -> std::ostream& {
  stream << "[";
  std::string final_str{};
  if (obj == subsystems::none) {
    stream << "None";
  } else if (obj == subsystems::everything) {
    stream << "Everything";
  } else {
    auto concat = [&final_str]() {
      if (!final_str.empty()) {
        final_str += ", ";
      }
    };

    if ((obj & subsystems::timer) != subsystems::none) {
      concat();
      final_str += "Timer";
    }

    if ((obj & subsystems::audio) != subsystems::none) {
      concat();
      final_str += "Audio";
    }

    if ((obj & subsystems::video) != subsystems::none) {
      concat();
      final_str += "Video";
    }

    if ((obj & subsystems::joystick) != subsystems::none) {
      concat();
      final_str += "Joystick";
    }

    if ((obj & subsystems::haptic) != subsystems::none) {
      concat();
      final_str += "Haptic";
    }

    if ((obj & subsystems::game_controller) != subsystems::none) {
      concat();
      final_str += "Game Controller";
    }

    if ((obj & subsystems::events) != subsystems::none) {
      concat();
      final_str += "Events";
    }

    if ((obj & subsystems::sensor) != subsystems::none) {
      concat();
      final_str += "Sensor";
    }
  }

  stream << final_str << "]";
  return stream;
}
} // namespace fsdl2cpp

#endif // FAST_SDL2_CPP_SUBSYSTEMS_HPP