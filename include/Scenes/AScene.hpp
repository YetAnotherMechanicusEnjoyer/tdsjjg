#ifndef ASCENEHPP
  #define ASCENEHPP

#include "Graphics/Assets/IAsset.hpp"
#include "IScene.hpp"

namespace Tdsjjg {
class AScene : IScene {
private:
  bool _isRunning;
  std::vector<IAsset> _assets;

public:
  AScene(void) : _isRunning(true) {}
  virtual ~AScene() = default;
};
}

#endif // !ASCENEHPP

