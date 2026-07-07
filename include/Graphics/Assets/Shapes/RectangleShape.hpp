#ifndef RECTANGLESHAPEHPP
  #define RECTANGLESHAPEHPP

#include "Graphics/Assets/Shapes/IShape.hpp"
#include <cstddef>

namespace Tdsjjg {
class RectangleShape : public IShape {
private:
  Vec2f _size;

public:
  RectangleShape(std::size_t id, Vec2f position={0, 0}, float rotation=0, Vec2f scale={0, 0}, Color fillColor={0, 0, 0}, Color outlineColor={0, 0, 0}, std::string texturePath=".", Vec2f size={0, 0})
    : IShape(id, position, rotation, scale, fillColor, outlineColor, texturePath), _size(size) {}

  virtual ~RectangleShape() = default;
  RectangleShape(const RectangleShape&) = delete;
  RectangleShape& operator=(const RectangleShape&) = delete;
  RectangleShape(RectangleShape&&) noexcept = default;
  RectangleShape& operator=(RectangleShape&&) noexcept = default;

  Vec2f getSize(void);
  void setSize(Vec2f size);
};
}

#endif // !RECTANGLESHAPEHPP
