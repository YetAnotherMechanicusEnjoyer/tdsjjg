#ifndef AASSETHPP
  #define AASSETHPP

#include <cstddef>
#include "Graphics/Assets/IAsset.hpp"

namespace Tdsjjg {
class AAsset : public IAsset {
private:
  std::size_t _id;

public:
  AAsset(std::size_t id) : _id(id) {}
  virtual ~AAsset() = default;
  AAsset(const AAsset&) = delete;
  AAsset& operator=(const AAsset&) = delete;
  AAsset(AAsset&&) noexcept = default;
  AAsset& operator=(AAsset&&) noexcept = default;

  std::size_t getId(void) { return _id; }
};
}

#endif // !AASSETHPP
