#ifndef JETPACKHPP
  #define JETPACKHPP

#include "Scenes/AScene.hpp"
#include <cstddef>
 
namespace Tdsjjg {
class Jetpack : public AScene {
private:
  std::size_t _score;

public:
  Jetpack(void) : _score(0) {}

  ~Jetpack(void) = default;
  Jetpack(const Jetpack&) = delete;
  Jetpack& operator=(const Jetpack&) = delete;
  Jetpack(Jetpack&&) noexcept = default;
  Jetpack& operator=(Jetpack&&) noexcept = default;

  std::size_t getScore(void);
  void setScore(std::size_t score);
};
}

#endif // !JETPACKHPP

