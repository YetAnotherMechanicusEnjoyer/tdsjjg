#include "Scenes/MenuSelector.hpp"
#include "Graphics/Assets/Text.hpp"
#include "Graphics/Assets/Font.hpp"
#include <memory>

namespace Tdsjjg {
  static Font menuFont("assets/font.ttf");

  MenuSelector::MenuSelector(void) : AScene(), _selectedIdx(0) {
    auto playText = std::make_shared<Text>(10, menuFont, "RATTRAPPER SES CREDITS", 50, Vec2f{250, 200}, Color{255, 255, 255});
    auto quitText = std::make_shared<Text>(11, menuFont, "GRADER ECHEC", 50, Vec2f{250, 300}, Color{255, 255, 255});

    _assets.push_back(playText);
    _assets.push_back(quitText);
  }

  std::optional<InputAction> MenuSelector::onInput(std::vector<InputAction>& actions) {
    for (auto action : actions) {
      if (action == InputAction::Up) {
        if (_selectedIdx > 0) _selectedIdx--;
      }
      else if (action == InputAction::Down) {
        if (_selectedIdx < _assets.size() - 1) _selectedIdx++;
      }
      else if (action == InputAction::Action || action == InputAction::Select) {
        if (_selectedIdx == 0) return InputAction::Select;
        if (_selectedIdx == 1) return InputAction::Quit;
      }
      else if (action == InputAction::Quit) return InputAction::Quit;
    }
    actions.clear();
    return std::nullopt;
  }

  void MenuSelector::update(void) {
    for (size_t i = 0; i < _assets.size(); ++i) {
      if (auto* text = dynamic_cast<Text*>(_assets[i].get())) {
        if (i == _selectedIdx) {
          text->setColor(Color{50, 100, 255});
          text->setStyle((Text::Style)((std::uint32_t)Text::Style::Bold | (std::uint32_t)Text::Style::Underlined));
        } else {
          text->setColor(Color{255, 255, 255});
          text->setStyle(Text::Style::Regular);
        }
      }
    }
  }

  std::string MenuSelector::run(void) {
    return "";
  }
}
