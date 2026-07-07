#ifndef TEXTHPP
  #define TEXTHPP

#include "Graphics/Assets/AAsset.hpp"
#include "Graphics/Assets/Font.hpp"

namespace Tdsjjg {
class Text : public AAsset {
private:
  enum class Style {
    Regular = 0,
    Bold = 1 << 0,
    Italic = 1 << 1,
    Underlined = 1 << 2,
    StrikeThough = 1 << 3,
  };

  enum class LineAlignment {
    Default,
    Left,
    Center,
    Right,
  };

  Style _style;
  LineAlignment _alignment;

  Font& _font;
  std::string _string;
  unsigned int _characterSize;

public:
  Text(std::size_t id, Font& font, std::string string="", unsigned int characterSize=30) : AAsset(id), _font(font), _string(string), _characterSize(characterSize) {}

  virtual ~Text() = default;
  Text(const Text&) = delete;
  Text& operator=(const Text&) = delete;
  Text(Text&&) noexcept = default;
  Text& operator=(Text&&) noexcept = delete;

  Style getStyle(void);
  void setStyle(Style style);
  LineAlignment getLineAlignment(void);
  void setLineAlignment(LineAlignment alignment);

  Font& getFont(void);
  void setFont(Font& font);
  std::string getString(void);
  void setString(std::string string);
  unsigned int getCharacterSize(void);
  void setCharacterSize(unsigned int characterSize);
};
}

#endif // !TEXTHPP
