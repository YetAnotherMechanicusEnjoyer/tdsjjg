#ifndef JETPACKHPP
  #define JETPACKHPP

#include "Scenes/AScene.hpp"
#include "Jetpack/Player.hpp"
#include "Graphics/Assets/Shapes/CircleShape.hpp"
#include <cstddef>
#include <memory>
#include <cstdlib>
#include <optional>

namespace Tdsjjg {
class Jetpack : public AScene {
private:
  std::size_t _score;
  Player& _player;
  
  float _velocity;
  bool _isThrusting;
  std::shared_ptr<CircleShape> _coin;

public:
  Jetpack(Player& player);
  ~Jetpack(void) = default;

  std::optional<InputAction> onInput(std::vector<InputAction>& actions) override;
  void update(void) override;

  std::size_t getScore(void) { return _score; }
  void setScore(std::size_t score) { _score = score; }
  Player& getPlayer(void) { return _player; }

  void setPlayer(Player& player) { (void)player; }
};
}

#endif // !JETPACKHPP
