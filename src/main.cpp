#include "Core.hpp"
#include "Errors.hpp"
#include <iostream>

int main() {
  try {
    Tdsjjg::Core core;
    core.run();
    return SUCCESS;
  } catch (const Tdsjjg::TDSJJGError& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return ERROR;
  } catch (const std::exception& e) {
    std::cerr << "Uncaught error: " << e.what() << std::endl;
    return ERROR;
  } catch (...) {
    std::cerr << "Uncaught error." << std::endl;
    return ERROR;
  }
}
