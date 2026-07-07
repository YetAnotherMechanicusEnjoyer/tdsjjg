#ifndef AASSETHPP
  #define AASSETHPP

#include <cstddef>

namespace Tdsjjg {
class AAsset {
private:
  std::size_t _id;

public:
  AAsset(std::size_t id) : _id(id) {}
  virtual ~AAsset() = default;
  AAsset(const AAsset&) = delete;
  AAsset& operator=(const AAsset&) = delete;
  AAsset(AAsset&&) noexcept = default;
  AAsset& operator=(AAsset&&) noexcept = default;

  std::size_t getId(void);
};
}

#endif // !AASSETHPP
