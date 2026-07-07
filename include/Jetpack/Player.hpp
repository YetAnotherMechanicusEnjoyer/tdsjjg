#ifndef PLAYERHPP
  #define PLAYERHPP

#include "Graphics/Assets/IAsset.hpp"
#include <memory>

namespace Tdsjjg {
class Player {
private:
  std::unique_ptr<IAsset> _asset;

public:
  Player(std::unique_ptr<IAsset> asset) : _asset(std::move(asset)) {}

  ~Player(void) = default;
  Player(const Player&) = delete;
  Player& operator=(const Player&) = delete;
  Player(Player&&) noexcept = default;
  Player& operator=(Player&&) noexcept = delete;

  IAsset& getAsset(void) { return *_asset; }
  void setAsset(std::unique_ptr<IAsset> asset) { _asset = std::move(asset); }
};
}

#endif // !PLAYERHPP
