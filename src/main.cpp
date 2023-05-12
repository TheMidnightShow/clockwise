#include <ctime>
#include <thread>
#include <iostream>
#include <sys/ioctl.h>
#include "numbers.hpp"

inline auto getCurrentTime() noexcept -> std::tm* {
  std::time_t now = std::time(nullptr);

  return std::localtime(&now);
}

inline auto getWindowSize() noexcept -> winsize {
  winsize window;
  ioctl(0, TIOCGWINSZ, &window);

  return window;
}

inline auto oversizeNumber(int num, int row) -> const char* {
  switch(num) {
    case 0:
      return zero[row];
      break;

    case 1:
      return one[row];
      break;

    case 2:
      return two[row];
      break;

    case 3:
      return three[row];
      break;

    case 4:
      return four[row];
      break;

    case 5:
      return five[row];
      break;

    case 6:
      return six[row];
      break;

    case 7:
      return seven[row];
      break;

    case 8:
      return eight[row];
      break;

    case 9:
      return nine[row];
      break;

    default:
      return dot[row];
      break;
  }
} 

inline auto printTime(std::tm* currentTime) noexcept -> void {
  winsize windowSize = getWindowSize();

  std::system("clear"); 

  for(int i = 0; i < (windowSize.ws_row / 2) - 3; i++) {
    std::cout << '\n';
  }

  for(int i = 0; i < 5; i++) {
    for(int i = 0; i < (windowSize.ws_col / 2) - 22; i++) {
      std::cout << ' ';
    }

    std::cout 
      << oversizeNumber(currentTime->tm_hour / 10, i) 
      << oversizeNumber(currentTime->tm_hour % 10, i) 

      << oversizeNumber(10, i) 

      << oversizeNumber(currentTime->tm_min / 10, i) 
      << oversizeNumber(currentTime->tm_min % 10, i) 

      << oversizeNumber(10, i) 

      << oversizeNumber(currentTime->tm_sec / 10, i) 
      << oversizeNumber(currentTime->tm_sec % 10, i) 

      << '\n';
  }
}

auto main(int argc, char** argv) -> int {
  bool runProgram = true;

  auto shouldProgramStop = [&]() -> void {
    std::cin.get();

    runProgram = false;
  };

  std::jthread programControl(shouldProgramStop);

  while(runProgram) {
    auto currentTime = getCurrentTime();

    printTime(currentTime);

    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  return 0;
}
