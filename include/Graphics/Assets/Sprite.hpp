#ifndef SPRITEHPP
  #define SPRITEHPP
#include "Common.hpp"
#include "Graphics/Assets/AAsset.hpp"
#include <filesystem>
#include <string>

namespace Tdsjjg {
class Sprite : public AAsset {
private:
  Vec2f _position;
  float _rotation;
  Vec2f _scale;
  Color _color;
  std::string _texturePath;

public:
  Sprite(std::size_t id, Vec2f position, float rotation, Vec2f scale, Color color, std::filesystem::path texturePath) : AAsset(id), _position(position), _rotation(rotation), _scale(scale), _color(color), _texturePath(texturePath) {}
  virtual ~Sprite() = default;
  Sprite(const Sprite&) = delete;
  Sprite& operator=(const Sprite&) = delete;
  Sprite(Sprite&&) noexcept = default;
  Sprite& operator=(Sprite&&) noexcept = default;

  Vec2f getPosition(void);
  void setPosition(Vec2f pos);

  float getRotation(void);
  void setRotation(float rot);

  Vec2f getScale(void);
  void setScale(Vec2f);

  Color getColor(void);
  void setColor(Color color);

  std::string getTexturePath(void);
  void setTexturePath(std::string texturePath);

  void move(Vec2f offset);
  void rotate(float angle);
  void scale(Vec2f factor);
};
}

#endif
