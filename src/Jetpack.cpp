#include "Scenes/Jetpack.hpp"
#include "Common.hpp"
#include "Graphics/Assets/Sprite.hpp"
#include "Graphics/Assets/Text.hpp"
#include "Jetpack/Player.hpp"
#include <optional>

namespace Tdsjjg {
  static Font gameFont("assets/font.ttf");

  Jetpack::Jetpack(Player& player) : AScene(), _score(0), _player(player), _velocity(0.0f), _isThrusting(false) {
    _coin = std::make_shared<CircleShape>(2, Vec2f{1300, 300}, 0, Vec2f{1, 1}, Color{255, 255, 0}, Color{255, 255, 255}, ".", 15.0f);
    auto scoreText = std::make_shared<Text>(12, gameFont, "Score: 0", 24, Vec2f{10, 10}, Color{255, 255, 255});

    _assets.push_back(_coin);
    _assets.push_back(scoreText);
  }

  std::optional<InputAction> Jetpack::onInput(std::vector<InputAction>& actions) {
    _isThrusting = false;
    for (auto action : actions) {
      if (action == InputAction::Action || action == InputAction::Up) _isThrusting = true;
      if (action == InputAction::Quit) return InputAction::Quit;
    }
    actions.clear();
    return std::nullopt;
  }

void Jetpack::update(void) {
  auto& playerAsset = _player.getAsset();
  auto* sprite = dynamic_cast<Sprite*>(&playerAsset);

  if (sprite) {
    if (_isThrusting) {
      _velocity -= 0.6f;
    } else {
      _velocity += 0.4f;
    }

    if (_velocity > 8.0f) _velocity = 8.0f;
    if (_velocity < -8.0f) _velocity = -8.0f;

    sprite->move({0, _velocity});

    Vec2f pos = sprite->getPosition();
    if (pos.y > 600) { pos.y = 600; _velocity = 0; }
    if (pos.y < 50) { pos.y = 50; _velocity = 0; }
    sprite->setPosition(pos);

    if (_coin) {
      _coin->move({-6.0f, 0.0f});

      if (_coin->getPosition().x < -50) {
        _coin->setPosition({1300, static_cast<float>(100 + rand() % 500)});
      }

      Vec2f coinPos = _coin->getPosition();

      float playerWidth = 500.0f * sprite->getScale().x;
      float playerHeight = 500.0f * sprite->getScale().y;

      if (coinPos.x >= pos.x && coinPos.x <= pos.x + playerWidth + 20 &&
          coinPos.y >= pos.y && coinPos.y <= pos.y + playerHeight + 20) {
        _score += 1;
        auto* scoreText = dynamic_cast<Text*>(_assets[1].get());
        if (scoreText) {
          scoreText->setString("Score: " + std::to_string(_score));
        }
        _coin->setPosition({1300, static_cast<float>(100 + rand() % 500)});
      }
    }
  }
}
}
