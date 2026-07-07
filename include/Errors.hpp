#ifndef ERRORS
  #define ERRORS
#include <exception>
#include <string>

namespace Tdsjjg {
class TDSJJGError : public std::exception {
public:
  TDSJJGError(std::string const &message) : _message(message) {}
  const char *what() const noexcept override { return _message.c_str(); }

private:
  std::string _message;
};
}

#endif /* ERRORS */
