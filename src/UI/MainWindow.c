#include <stdio.h>
#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
  switch (uMsg){
      case WM_DESTROY:
          PostQuitMessage(0);
          return 0;
  }
  
  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WindowGen(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  // Register the window class
  char CLASS_NAME[] = "NotepadImprovedWindow";
  WNDCLASS wc = { };

  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = CLASS_NAME;

  RegisterClass(&wc);

  // Create the window

  // Define parameters
  DWORD style = 0;
  LPCSTR windowName = "NotepadImproved";
  
  HWND hwnd = CreateWindowEx(
    style,                // Optional window styles
    CLASS_NAME,           // Window class
    windowName,           // Window Text
    WS_OVERLAPPEDWINDOW,  // Window Style constant
    
    // Size and Position
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    CW_USEDEFAULT,

    NULL,                 // Parent window
    NULL,                 // Menu
    hInstance,            // Instance handle
    NULL                  // Additional application data
  );

  if (hwnd == NULL)
  {
    return 0;
  }

  ShowWindow(hwnd, nCmdShow);

  MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
  return 0;
}