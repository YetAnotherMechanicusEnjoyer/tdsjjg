#ifndef CORE
  #define CORE
  #define SUCCESS 0
  #define HELP 2026
  #define ERROR 84
  #define FAIL 1

#include "Common.hpp"
#include <memory>
#include <vector>
#include "Scenes/IScene.hpp"
#include "Graphics/IGraphics.hpp"
#include "Jetpack/Player.hpp"

namespace Tdsjjg {
class Core {
private:
  std::unique_ptr<Player> _player;
  std::vector<std::unique_ptr<IScene>> _scenes;
  std::unique_ptr<IGraphics> _graphics;
  std::vector<InputKey> _keys;
  std::vector<InputAction> _actions;
  size_t _currentSceneIdx;

  std::unique_ptr<IGraphics> loadGraphics(void);
  std::vector<std::unique_ptr<IScene>> loadScenes(void);
  void handleGlobalInput(void);

public:
  explicit Core(void);
  ~Core(void) = default;

  Core(const Core&) = delete;
  Core& operator=(const Core&) = delete;
  Core(Core&&) noexcept = default;
  Core& operator=(Core&&) noexcept = default;

  void run(void);
};
}

#endif
