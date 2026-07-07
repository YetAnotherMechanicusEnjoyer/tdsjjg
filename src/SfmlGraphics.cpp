#include "Graphics/SfmlGraphics.hpp"
#include "Common.hpp"
#include "Errors.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
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

void SfmlGraphics::draw(const std::vector<IAsset>& assets) {
  (void)assets;
  if (!_window) return;

  sf::Vector2u windowSize = _window->getSize();

  sf::RectangleShape rect(sf::Vector2f(windowSize.x / 5.0, windowSize.y / 5.0));
  rect.setPosition({windowSize.x / 2.5f, windowSize.y / 2.5f});
  rect.setFillColor(sf::Color({30, 120, 186, 255}));

  _window->draw(rect);
}

void SfmlGraphics::display(void) {
  if (_window) _window->display();
}

void SfmlGraphics::pollEvent(std::vector<InputKey>& keys) {
  if (!_window) return;

  while (auto event = _window->pollEvent()) {
    if (event->is<sf::Event::Closed>()) return shutdown();
    if (event->is<sf::Event::KeyPressed>()) {
      auto result = convertKey(event->getIf<sf::Event::KeyPressed>()->code);
      if (result.has_value()) keys.push_back(result.value());
    }
    if (event->is<sf::Event::Resized>()) {
      sf::FloatRect visibleArea({0, 0}, {static_cast<float>(event->getIf<sf::Event::Resized>()->size.x), static_cast<float>(event->getIf<sf::Event::Resized>()->size.y)});
      _window->setView(sf::View(visibleArea));
    }
  }
}

bool SfmlGraphics::isAlive(void) {
  return _alive;
}
}
