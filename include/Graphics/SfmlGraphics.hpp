#ifndef SFMLGRAPHICS
  #define SFMLGRAPHICS

#include "Common.hpp"
#include "Graphics/Assets/IAsset.hpp"
#include "Graphics/IGraphics.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <map>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace Tdsjjg {
class SfmlGraphics : public IGraphics {
private:
  sf::RenderWindow* _window;
  Vec2u _resolution;
  bool _alive;

  std::map<std::string, sf::Texture> _textures;
  std::map<std::string, sf::Font> _fonts;
  std::map<InputKey, sf::Keyboard::Key> _keyMapping;

public:
  SfmlGraphics(Vec2u resolution);
  ~SfmlGraphics(void);
  void shutdown();
  void clear();
  void draw(const std::vector<IAsset*>& assets);
  void display();
  std::optional<InputKey> convertKey(sf::Keyboard::Key code);
  void pollEvent(std::vector<InputKey>& keys);
  bool isAlive(void);
};
}

#endif // !SFMLGRAPHICS

