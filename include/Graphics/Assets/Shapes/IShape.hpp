#ifndef ISHAPEHPP
  #define ISHAPEHPP

#include <cstddef>
#include "Graphics/Assets/AAsset.hpp"

namespace Tdsjjg {
class IShape : public AAsset {
public:
  IShape(std::size_t id) : AAsset(id) {}
  virtual ~IShape() = default;
};
}

#endif // !ISHAPEHPP
