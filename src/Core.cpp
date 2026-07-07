#include "Core.hpp"
#include "Common.hpp"
#include "Errors.hpp"
#include "Graphics/Assets/IAsset.hpp"
#include "Graphics/Assets/Sprite.hpp"
#include "Graphics/IGraphics.hpp"
#include "Graphics/SfmlGraphics.hpp"
#include "Scenes/MenuSelector.hpp"
#include "Scenes/Jetpack.hpp"

namespace Tdsjjg {
Core::Core(void) : _currentSceneIdx(0) {
  _graphics = loadGraphics();
  _scenes = loadScenes();
}

std::unique_ptr<IGraphics> Core::loadGraphics() {
  return std::make_unique<SfmlGraphics>(Vec2u { 1280, 720 });
}

std::unique_ptr<IAsset> createPlayerAsset() {
  return std::make_unique<Sprite>(1, Vec2f{50, 400}, 0.0f, Vec2f{0.2, 0.2}, Color{255, 255, 255}, "assets/player.png");
}

std::unique_ptr<IAsset> createBackgroundAsset() {
  return std::make_unique<Sprite>(0, Vec2f{0, 0}, 0.0f, Vec2f{1.6, 1.6}, Color{255, 255, 255}, "assets/background.jpg");
}

std::vector<std::unique_ptr<IScene>> Core::loadScenes() {
  std::vector<std::unique_ptr<IScene>> scenes;

  _player = std::make_unique<Player>(createPlayerAsset());

  scenes.push_back(std::make_unique<MenuSelector>());
  scenes.push_back(std::make_unique<Jetpack>(*_player));

  return scenes;
}

void Core::handleGlobalInput(void) {
  for (auto key : _keys) {
    if (key == InputKey::Escape && _currentSceneIdx == 1) _actions.push_back(InputAction::Quit);
    if (key == InputKey::Space) _actions.push_back(InputAction::Action);
    if (key == InputKey::Up) _actions.push_back(InputAction::Up);
    if (key == InputKey::Down) _actions.push_back(InputAction::Down);
    if (key == InputKey::Return) _actions.push_back(InputAction::Select);
  }
}

void Core::run(void) {
  if (!_graphics) throw TDSJJGError("Graphics not graphicsying");

  std::unique_ptr<IAsset> backgroundAsset = createBackgroundAsset();
  std::unique_ptr<IAsset> playerAsset = createPlayerAsset();

  while (_graphics->isAlive()) {
    _keys.clear();
    _graphics->pollEvent(_keys);
    handleGlobalInput();

    if (_currentSceneIdx < _scenes.size()) {
      auto& currentScene = _scenes[_currentSceneIdx];
      auto result = currentScene->onInput(_actions);

      if (result.has_value()) {
        if (result.value() == InputAction::Quit) {
          if (_currentSceneIdx == 1) { _currentSceneIdx = 0; _actions.clear(); }
          else _graphics->shutdown();
        }
        else if (result.value() == InputAction::Select) _currentSceneIdx = 1;
      }

      currentScene->update();

      std::vector<IAsset*> assetsToDraw;
      assetsToDraw.push_back(backgroundAsset.get());

      if (auto* customScene = dynamic_cast<AScene*>(currentScene.get())) {
        for (auto& asset : customScene->getAssets()) {
          assetsToDraw.push_back(asset.get());
        }
      }

      if (_player && _currentSceneIdx > 0) {
        assetsToDraw.push_back(&_player->getAsset());
      }

      _graphics->clear();
      _graphics->draw(assetsToDraw);
      _graphics->display();
    }
  }
}
}
