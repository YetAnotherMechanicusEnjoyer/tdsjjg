#include "Graphics/SfmlGraphics.hpp"
#include "Graphics/Assets/Shapes/CircleShape.hpp"
#include "Graphics/Assets/Shapes/RectangleShape.hpp"
#include "Graphics/Assets/Sprite.hpp"
#include "Graphics/Assets/Text.hpp"
#include "Common.hpp"
#include "Errors.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <optional>

namespace Tdsjjg {
std::optional<InputKey> SfmlGraphics::convertKey(sf::Keyboard::Key code) {
  for (const auto& [key, mappedKey] : _keyMapping) {
    if (mappedKey == code) return key;
  }
  return std::nullopt;
}

SfmlGraphics::SfmlGraphics(Vec2u resolution) : _resolution(resolution) {
  _window = new sf::RenderWindow(sf::VideoMode({_resolution.x, _resolution.y}, 24), "TDSJJG", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);

  if (!_window) throw TDSJJGError("Creating SFML Window.");

  _window->setFramerateLimit(60);

  _keyMapping[InputKey::Left] = sf::Keyboard::Key::Left;
  _keyMapping[InputKey::Right] = sf::Keyboard::Key::Right;
  _keyMapping[InputKey::Up] = sf::Keyboard::Key::Up;
  _keyMapping[InputKey::Down] = sf::Keyboard::Key::Down;
  _keyMapping[InputKey::Escape] = sf::Keyboard::Key::Escape;
  _keyMapping[InputKey::Return] = sf::Keyboard::Key::Enter;
  _keyMapping[InputKey::Space] = sf::Keyboard::Key::Space;

  _alive = true;
}

SfmlGraphics::~SfmlGraphics() {
  if (_window)
    _window->close();
}

void SfmlGraphics::shutdown(void) {
  _alive = false;
}

void SfmlGraphics::clear(void) {
  if (_window) _window->clear(sf::Color::Black);
}

void SfmlGraphics::draw(const std::vector<IAsset*>& assets) {
  if (!_window) return;

  for (auto* asset : assets) {
    if (!asset) continue;

    if (auto* rectShape = dynamic_cast<RectangleShape*>(asset)) {
      sf::RectangleShape rect(sf::Vector2f(rectShape->getSize().x, rectShape->getSize().y));
      rect.setPosition({rectShape->getPosition().x, rectShape->getPosition().y});
      rect.setFillColor(sf::Color(rectShape->getFillColor().r, rectShape->getFillColor().g, rectShape->getFillColor().b));
      _window->draw(rect);
    }
    else if (auto* circleShape = dynamic_cast<CircleShape*>(asset)) {
      sf::CircleShape circle(circleShape->getRadius());
      circle.setPosition({circleShape->getPosition().x, circleShape->getPosition().y});
      circle.setFillColor(sf::Color(circleShape->getFillColor().r, circleShape->getFillColor().g, circleShape->getFillColor().b));
      _window->draw(circle);
    }
    else if (auto* spriteAsset = dynamic_cast<Sprite*>(asset)) {
      std::string path = spriteAsset->getTexturePath();

      if (_textures.find(path) == _textures.end()) {
        sf::Texture tex;
        if (tex.loadFromFile(path)) {
          _textures[path] = tex;
        }
      }

      sf::Sprite sfSprite(_textures[path]);
      sfSprite.setPosition({spriteAsset->getPosition().x, spriteAsset->getPosition().y});
      sfSprite.setRotation(sf::degrees(spriteAsset->getRotation()));
      sfSprite.setScale({spriteAsset->getScale().x, spriteAsset->getScale().y});
      sfSprite.setColor(sf::Color(spriteAsset->getColor().r, spriteAsset->getColor().g, spriteAsset->getColor().b));

      _window->draw(sfSprite);
    }
    else if (auto* textAsset = dynamic_cast<Text*>(asset)) {
      std::string path = textAsset->getFont().getFilePath().string();

      if (_fonts.find(path) == _fonts.end()) {
        sf::Font font;
        if (!font.openFromFile(path)) {
          std::cerr << "SFML error: Cannot load font from file: " << path << std::endl;
          continue;
        }
        _fonts[path] = font;
      }

      sf::Text sfText(_fonts[path], textAsset->getString(), textAsset->getCharacterSize());
      sfText.setPosition({textAsset->getPosition().x, textAsset->getPosition().y});
      sfText.setFillColor({textAsset->getColor().r, textAsset->getColor().g, textAsset->getColor().b});
      sfText.setStyle((sf::Text::Style)textAsset->getStyle());
      sfText.setLineAlignment((sf::Text::LineAlignment)textAsset->getLineAlignment());

      _window->draw(sfText);
    }
  }
}

void SfmlGraphics::display(void) {
  if (_window) _window->display();
}

void SfmlGraphics::pollEvent(std::vector<InputKey>& keys) {
  if (!_window) return;

  while (auto event = _window->pollEvent()) {
    if (event->is<sf::Event::Closed>()) return shutdown();
    if (event->is<sf::Event::Resized>()) {
      sf::FloatRect visibleArea({0, 0}, {static_cast<float>(event->getIf<sf::Event::Resized>()->size.x), static_cast<float>(event->getIf<sf::Event::Resized>()->size.y)});
      _window->setView(sf::View(visibleArea));
    }
  }

  for (const auto& [inputKey, sfKey] : _keyMapping) {
    if (sf::Keyboard::isKeyPressed(sfKey)) {
      keys.push_back(inputKey);
    }
  }
}

bool SfmlGraphics::isAlive(void) {
  return _alive;
}
}
