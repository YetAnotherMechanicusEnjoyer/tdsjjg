#ifndef ASCENEHPP
  #define ASCENEHPP

#include "Common.hpp"
#include "Graphics/Assets/IAsset.hpp"
#include "IScene.hpp"
#include <optional>
#include <vector>
#include <memory>

namespace Tdsjjg {
class AScene : public IScene {
protected:
  bool _isRunning;
  std::vector<std::shared_ptr<IAsset>> _assets;

public:
  AScene(void) : _isRunning(true) {}
  virtual ~AScene() = default;

  void shutdown() override { _isRunning = false; }
  void update() override {}
  std::optional<InputAction> onInput(std::vector<InputAction>& actions) override { (void)actions; return std::nullopt; }

  const std::vector<std::shared_ptr<IAsset>>& getAssets() const { return _assets; }
};
}
#endif
