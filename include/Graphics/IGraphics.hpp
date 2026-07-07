#ifndef IGRAPHICS
  #define IGRAPHICS
#include "Common.hpp"
#include "Graphics/Assets/IAsset.hpp"
#include <vector>

namespace Tdsjjg {
class IGraphics {
public:
  virtual ~IGraphics() = default;
  virtual void shutdown() = 0;
  virtual void clear() = 0;
  virtual void draw(const std::vector<IAsset*>& assets) = 0;
  virtual void display() = 0;
  virtual void pollEvent(std::vector<InputKey>& keys) = 0;
  virtual bool isAlive(void) = 0;
};
}
#endif

