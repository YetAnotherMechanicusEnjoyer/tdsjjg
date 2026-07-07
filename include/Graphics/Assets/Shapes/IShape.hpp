#ifndef SHAPEHPP
  #define SHAPEHPP
#include "Common.hpp"
#include "Graphics/Assets/AAsset.hpp"
#include <string>

namespace Tdsjjg {
class IShape : public AAsset {
private:
  Vec2f _position;
  float _rotation;
  Vec2f _scale;
  
  Color _fillColor;
  Color _outlineColor;

  std::string _texturePath;

public:
  IShape(std::size_t id, Vec2f position={0, 0}, float rotation=0, Vec2f scale={0, 0}, Color fillColor={0, 0, 0}, Color outlineColor={0, 0, 0}, std::string texturePath=".") : AAsset(id), _position(position), _rotation(rotation), _scale(scale), _fillColor(fillColor), _outlineColor(outlineColor), _texturePath(texturePath) {}
  virtual ~IShape() = default;
  IShape(const IShape&) = delete;
  IShape& operator=(const IShape&) = delete;
  IShape(IShape&&) noexcept = default;
  IShape& operator=(IShape&&) noexcept = default;

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
}

#endif
