#ifndef ISCENE
  #define ISCENE
#include "Common.hpp"
#include <vector>

namespace Tdsjjg {
class IScene {
public:
  virtual ~IScene() = default;
  virtual void shutdown() = 0;
  virtual void update(void);
  virtual void onInput(std::vector<InputAction>& action);
};
}
#endif
