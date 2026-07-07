#ifndef FONTHPP
  #define FONTHPP

#include <filesystem>

namespace Tdsjjg {
class Font {
private:
  std::filesystem::path _filePath;

public:
  Font(const std::filesystem::path filePath) : _filePath(filePath) {}

  virtual ~Font() = default;
  Font(const Font&) = delete;
  Font& operator=(const Font&) = delete;
  Font(Font&&) noexcept = default;
  Font& operator=(Font&&) noexcept = default;

  std::filesystem::path getFilePath(void);
  void setFilePath(std::filesystem::path filePath);
};
}

#endif // !FONTHPP
