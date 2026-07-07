#ifndef ISCENE
  #define ISCENE

#include "Common.hpp"
#include <optional>
#include <vector>

namespace Tdsjjg {
class IScene {
public:
  virtual ~IScene() = default;
  virtual void shutdown() = 0;
  virtual void update() = 0;
  virtual std::optional<InputAction> onInput(std::vector<InputAction>& actions) = 0;
};
}
#endif
