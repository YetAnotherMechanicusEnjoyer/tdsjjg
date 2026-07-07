#ifndef CIRCLESHAPEHPP
  #define CIRCLESHAPEHPP

#include "Graphics/Assets/Shapes/AShape.hpp"
#include <cstddef>

namespace Tdsjjg {
class CircleShape : public AShape {
private:
  float _radius;
  std::size_t _pointCount;

public:
  CircleShape(std::size_t id, Vec2f position={0, 0}, float rotation=0, Vec2f scale={0, 0}, Color fillColor={0, 0, 0}, Color outlineColor={0, 0, 0}, std::string texturePath=".", float radius=0, std::size_t pointCount=30)
    : AShape(id, position, rotation, scale, fillColor, outlineColor, texturePath), _radius(radius), _pointCount(pointCount) {}

  virtual ~CircleShape() = default;
  CircleShape(const CircleShape&) = delete;
  CircleShape& operator=(const CircleShape&) = delete;
  CircleShape(CircleShape&&) noexcept = delete;
  CircleShape& operator=(CircleShape&&) noexcept = delete;

  float getRadius(void);
  void setRadius(float radius);
};

inline float CircleShape::getRadius() { return _radius; }
}

#endif // !CIRCLESHAPEHPP
