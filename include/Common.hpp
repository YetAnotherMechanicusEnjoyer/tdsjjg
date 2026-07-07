#ifndef COMMON
  #define COMMON
#include <cstdint>

namespace Tdsjjg {
  enum class InputKey {
    Left,
    Right,
    Up,
    Down,
    Return,
    Escape,
    Space,
  };

  enum class InputAction {
    None,
    Quit,
    Menu,
    Select,
    Up,
    Down,
    Left,
    Right,
    Action
  };

  struct KeyEvent {
    InputAction action {InputAction::None};
    char text {'\0'};
  };

  struct Vec2i {
    int x {0};
    int y {0};
  };

  struct Vec2u {
    unsigned int x {0};
    unsigned int y {0};
  };

  struct Vec2f {
    float x {0};
    float y {0};
  };

  struct Color {
    std::uint8_t r;
    std::uint8_t g;
    std::uint8_t b;
  };
}
#endif
