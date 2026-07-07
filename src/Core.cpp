#include "Core.hpp"
#include "Errors.hpp"
#include "Graphics/IGraphics.hpp"
#include "Graphics/SfmlGraphics.hpp"
#include <memory>

namespace Tdsjjg {
Core::Core(void) {
  _graphics = loadGraphics();
  _scenes = loadScenes();
  _keys = std::vector<InputKey>();
  _actions = std::vector<InputAction>();
}

std::unique_ptr<IGraphics> Core::loadGraphics() {
  return std::make_unique<SfmlGraphics>(Vec2u { 1280, 720 });
}

std::vector<IScene> Core::loadScenes() {
  return std::vector<IScene>();
}

void Core::run(void) {
  std::vector<IAsset> assets;
  if (!_graphics) throw TDSJJGError("Graphics not graphicsying");
  while (_graphics->isAlive()) {
    _graphics->clear();
    _graphics->draw(assets);
    _graphics->display();
    _graphics->pollEvent(_keys);
  }
}
}
