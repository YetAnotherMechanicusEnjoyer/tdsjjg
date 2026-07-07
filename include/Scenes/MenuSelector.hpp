#ifndef MENUSELECTOR_HPP
#define MENUSELECTOR_HPP

#include "Scenes/AScene.hpp"
#include <string>
#include <functional>

namespace Tdsjjg {
class MenuSelector : public AScene {
public:
  struct MenuOption {
    std::string name;
    std::function<void()> action;
  };

  MenuSelector(void);

  ~MenuSelector(void) = default;
  MenuSelector(const MenuSelector&) = delete;
  MenuSelector& operator=(const MenuSelector&) = delete;
  MenuSelector(MenuSelector&&) noexcept = default;
  MenuSelector& operator=(MenuSelector&&) noexcept = default;

  std::optional<InputAction> onInput(std::vector<InputAction>& actions) override;
  void update(void) override;
  std::string run(void);

private:
  size_t _selectedIdx;
};
}

#endif
