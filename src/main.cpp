#include "include/func.h"
#include <cstring>
#include <iostream>

int main(int argc, char *argv[]) {

  // ARGUMENT LIST
  const char *debug_mode_arg = "-debug";
  bool debugMode = false;

  if (argc > 1) {

    if (std::strcmp(argv[1], debug_mode_arg) == 0) {
      GameMessage("Debug mode eneabled!", true);
      debugMode = true;
    } else {
      GameMessage("Debug mode disabled!", false);
    }
  }

  return 0;
}
