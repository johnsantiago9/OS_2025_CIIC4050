#include "functions.h"

int main() {
  SetupSharedMemory();
  SetupSemaphore();
  SignalHandlerSetup();

  // Wait indefinitely for signals
  while (1) {
    pause();
  }

  return 0;
}
