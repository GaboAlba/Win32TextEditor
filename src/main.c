#ifdef RELEASE

#include <stdio.h>

#include "MainWindow.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  WindowGen(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
  return 0;
}

#endif