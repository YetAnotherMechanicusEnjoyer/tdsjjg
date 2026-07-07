#ifndef SHAPEHPP
  #define SHAPEHPP
#include "Common.hpp"
#include "Graphics/Assets/Shapes/IShape.hpp"
#include <string>

namespace Tdsjjg {
class AShape : public IShape {
private:
  Vec2f _position;
  float _rotation;
  Vec2f _scale;
  
  Color _fillColor;
  Color _outlineColor;

  std::string _texturePath;

public:
  AShape(std::size_t id, Vec2f position={0, 0}, float rotation=0, Vec2f scale={0, 0}, Color fillColor={0, 0, 0}, Color outlineColor={0, 0, 0}, std::string texturePath=".") : IShape(id), _position(position), _rotation(rotation), _scale(scale), _fillColor(fillColor), _outlineColor(outlineColor), _texturePath(texturePath) {}
  virtual ~AShape() = default;
  AShape(const AShape&) = delete;
  AShape& operator=(const IShape&) = delete;
  AShape(AShape&&) noexcept = default;
  AShape& operator=(AShape&&) noexcept = default;

  Vec2f getPosition(void);
  void setPosition(Vec2f pos);
  float getRotation(void);
  void setRotation(float rot);
  Vec2f getScale(void);
  void setScale(Vec2f);

  Color getFillColor(void);
  void setFillColor(Color color);
  Color getOutlineColor(void);
  void setOutlineColor(Color color);

  std::string getTexturePath(void);
  void setTexturePath(std::string texturePath);

  void move(Vec2f offset);
  void rotate(float angle);
  void scale(Vec2f factor);
};

inline Vec2f AShape::getPosition() { return _position; }
inline void AShape::setPosition(Vec2f pos) { _position = pos; }
inline float AShape::getRotation() { return _rotation; }
inline void AShape::setRotation(float rot) { _rotation = rot; }
inline Vec2f AShape::getScale() { return _scale; }
inline void AShape::setScale(Vec2f s) { _scale = s; }
inline Color AShape::getFillColor() { return _fillColor; }
inline void AShape::setFillColor(Color color) { _fillColor = color; }
inline Color AShape::getOutlineColor() { return _outlineColor; }
inline void AShape::setOutlineColor(Color color) { _outlineColor = color; }
inline std::string AShape::getTexturePath() { return _texturePath; }
inline void AShape::setTexturePath(std::string path) { _texturePath = path; }
inline void AShape::move(Vec2f offset) { _position.x += offset.x; _position.y += offset.y; }
inline void AShape::rotate(float angle) { _rotation += angle; }
inline void AShape::scale(Vec2f factor) { _scale.x *= factor.x; _scale.y *= factor.y; }

}

#endif
