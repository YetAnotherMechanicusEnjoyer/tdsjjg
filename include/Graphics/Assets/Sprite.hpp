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
  Sprite(std::size_t id, Vec2f position, float rotation, Vec2f scale, Color color, std::filesystem::path texturePath) 
    : AAsset(id), _position(position), _rotation(rotation), _scale(scale), _color(color), _texturePath(texturePath.string()) {}
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
  void setScale(Vec2f scale);
  Color getColor(void);
  void setColor(Color color);
  std::string getTexturePath(void);
  void setTexturePath(std::string texturePath);

  void move(Vec2f offset);
  void rotate(float angle);
  void scale(Vec2f factor);

  Vec2f getSize(void) { return {40, 60}; } 
};

inline Vec2f Sprite::getPosition(void) { return _position; }
inline void Sprite::setPosition(Vec2f pos) { _position = pos; }
inline float Sprite::getRotation(void) { return _rotation; }
inline void Sprite::setRotation(float rot) { _rotation = rot; }
inline Vec2f Sprite::getScale(void) { return _scale; }
inline void Sprite::setScale(Vec2f scale) { _scale = scale; }
inline Color Sprite::getColor(void) { return _color; }
inline void Sprite::setColor(Color color) { _color = color; }
inline std::string Sprite::getTexturePath(void) { return _texturePath; }
inline void Sprite::setTexturePath(std::string texturePath) { _texturePath = texturePath; }
inline void Sprite::move(Vec2f offset) { _position.x += offset.x; _position.y += offset.y; }
inline void Sprite::rotate(float angle) { _rotation += angle; }
inline void Sprite::scale(Vec2f factor) { _scale.x *= factor.x; _scale.y *= factor.y; }
}

#endif
