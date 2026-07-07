#ifndef IASSETHPP
  #define IASSETHPP

namespace Tdsjjg {
class IAsset {
public:
  IAsset() = default;
  virtual ~IAsset() = default;
  IAsset(const IAsset&) = delete;
  IAsset& operator=(const IAsset&) = delete;
  IAsset(IAsset&&) noexcept = default;
  IAsset& operator=(IAsset&&) noexcept = default;
};
}

#endif // !IASSETHPP
