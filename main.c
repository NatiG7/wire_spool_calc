#include <windows.h>
#include <shellscalingapi.h>
#include "ui.h" // Custom header containing UI component declarations

/**
 * Entry point for a Windows application.
 *
 * Initializes DPI awareness, creates the main window and UI elements
 * (label, textbox, and button), shows the window, and enters the message loop.
 *
 * @param hInstance      Handle to the current instance of the application.
 * @param hPrevInstance  (Unused) Handle to the previous instance of the application.
 * @param lpCmdLine      Command line string.
 * @param nCmdShow       Flag that says whether the main window will be minimized, maximized, or shown normally.
 * @return               Exit code of the application.
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Enable high DPI scaling for sharp UI
    SetProcessDPIAware();

    // Create the main application window
    HWND hwnd = CreateMainWindow(hInstance);
    if (hwnd == NULL)
    {
        MessageBox(NULL, "Window creation failed!", "Error", MB_ICONERROR);
        return 0;
    }

    // Create UI elements: labels, textboxes, and button (dynamically created)
    HWND hwndLabel1 = CreateInputField(hwnd, hInstance, "Enter wire length:", 50, 150, 3);
    HWND hwndLabel2 = CreateInputField(hwnd, hInstance, "Enter spool diameter:", 50, 200, 4);
    HWND hwndLabel3 = CreateInputField(hwnd, hInstance, "Enter wire weight:", 50, 250, 5);  // New label for wire weight
    HWND hwndLabel4 = CreateInputField(hwnd, hInstance, "Enter spool weight:", 50, 300, 6); // New label for spool weight
    HWND hwndLabel5 = CreateInputField(hwnd, hInstance, "Enter number of coils:", 50, 350, 7); // New label for number of coils
    
    // Create a button with dynamic label and position
    HWND hwndButton = CreateButton(hwnd, hInstance, "Calculate", 50, 400, 1);

    // Show the main window and button
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    ShowWindow(hwndButton, SW_SHOW);

    // Main message loop to keep the window responsive
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
