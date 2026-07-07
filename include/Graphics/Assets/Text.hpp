#ifndef TEXTHPP
  #define TEXTHPP

#include "Common.hpp" // Ajouté pour Vec2f et Color
#include "Graphics/Assets/AAsset.hpp"
#include "Graphics/Assets/Font.hpp"

namespace Tdsjjg {
class Text : public AAsset {
public:
  enum class Style {
    Regular = 0,
    Bold = 1 << 0,
    Italic = 1 << 1,
    Underlined = 1 << 2,
    StrikeThough = 1 << 3,
  };

  enum class LineAlignment {
    Default, Left, Center, Right,
  };

  Text(std::size_t id, Font& font, std::string string="", unsigned int characterSize=30, Vec2f position={0,0}, Color color={255,255,255}) 
    : AAsset(id), _style(Style::Regular), _alignment(LineAlignment::Default), _font(font), _string(string), _characterSize(characterSize), _position(position), _color(color) {}

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

  Vec2f getPosition(void) { return _position; }
  void setPosition(Vec2f pos) { _position = pos; }
  Color getColor(void) { return _color; }
  void setColor(Color color) { _color = color; }

private:
  Style _style;
  LineAlignment _alignment;
  Font& _font;
  std::string _string;
  unsigned int _characterSize;
  Vec2f _position;
  Color _color;
};

inline Text::Style Text::getStyle(void) { return _style; }
inline void Text::setStyle(Text::Style style) { _style = style; }
inline Text::LineAlignment Text::getLineAlignment(void) { return _alignment; }
inline void Text::setLineAlignment(Text::LineAlignment alignment) { _alignment = alignment; }
inline Font& Text::getFont(void) { return _font; }
inline void Text::setFont(Font& font) { _font = std::move(font); }
inline std::string Text::getString(void) { return _string; }
inline void Text::setString(std::string string) { _string = string; }
inline unsigned int Text::getCharacterSize(void) { return _characterSize; }
inline void Text::setCharacterSize(unsigned int characterSize) { _characterSize = characterSize; }
}

#endif // !TEXTHPP
