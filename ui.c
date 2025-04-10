#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <shellscalingapi.h>
#include "ui.h" // Header containing UI function declarations

/**
 * Window procedure that handles window messages.
 *
 * Handles destruction and command messages (e.g., button click).
 *
 * @param hwnd     Handle to the window.
 * @param uMsg     Message identifier.
 * @param wParam   Additional message information (dependent on uMsg).
 * @param lParam   Additional message information (dependent on uMsg).
 * @return         Result of message processing (0 or DefWindowProc).
 */
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0); // Post a quit message when window is destroyed
        break;
    case WM_COMMAND:
        if (LOWORD(wParam) == 1) // Check if the button (ID 1) was clicked
        {
            HWND hwndTextBox = GetDlgItem(hwnd, 2); // Get handle to textbox (ID 2)
            HandleButtonClick(hwnd, hwndTextBox);   // Handle the button click
        }
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam); // Default processing
    }
    return 0;
}

/**
 * Creates and registers the main application window.
 *
 * @param hInstance  Handle to the application instance.
 * @return           Handle to the created window.
 */
HWND CreateMainWindow(HINSTANCE hInstance)
{
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "WireSpoolCalc";

    RegisterClass(&wc);

    return CreateWindowEx(
        0,
        wc.lpszClassName,
        "Wire Spool Calculator",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL);
}

/**
 * Creates a push button.
 *
 * @param hwndParent  Handle to the parent window.
 * @param hInstance   Handle to the application instance.
 * @param labelText   Text to display on the button.
 * @param x           X-coordinate for the button.
 * @param y           Y-coordinate for the button.
 * @param id          ID of the button.
 * @return            Handle to the button control.
 */
HWND CreateButton(HWND hwndParent, HINSTANCE hInstance, LPCSTR labelText, int x, int y, int id)
{
    return CreateWindowEx(
        0, "BUTTON", labelText,
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        x, y, 100, 30, // Default button width and height
        hwndParent, (HMENU)(uintptr_t)id, hInstance, NULL);
}

/**
 * Creates a static text label.
 *
 * @param hwndParent  Handle to the parent window.
 * @param hInstance   Handle to the application instance.
 * @param labelText   Text to display in the label.
 * @param x           X-coordinate for the label.
 * @param y           Y-coordinate for the label.
 * @return            Handle to the label control.
 */
HWND CreateLabel(HWND hwndParent, HINSTANCE hInstance, LPCSTR labelText, int x, int y, int id)
{
    return CreateWindowEx(
        0, "STATIC", labelText,
        WS_VISIBLE | WS_CHILD,
        x, y, 200, 20, // Default width and height for label
        hwndParent, NULL, hInstance, NULL);
}

/**
 * Creates an editable textbox.
 *
 * @param hwndParent  Handle to the parent window.
 * @param hInstance   Handle to the application instance.
 * @param x           X-coordinate for the textbox.
 * @param y           Y-coordinate for the textbox.
 * @param id          ID for the text box.
 * @return            Handle to the textbox control.
 */
HWND CreateTextBox(HWND hwndParent, HINSTANCE hInstance, int x, int y, int id)
{
    return CreateWindowEx(
        0, "EDIT", "",
        WS_BORDER | WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL,
        x, y, 200, 25, // Default width and height for textbox
        hwndParent, (HMENU)(uintptr_t)id, hInstance, NULL);
}

/**
 * Creates an input field with a label and a text box.
 *
 * @param hwndParent  Handle to the parent window.
 * @param hInstance   Handle to the application instance.
 * @param labelText   Text to display in the label.
 * @param x           X-coordinate for the label and textbox.
 * @param y           Y-coordinate for the label and textbox.
 * @param id          ID for the text box.
 * @return            Handle to the text box control.
 */
HWND CreateInputField(HWND hwndParent, HINSTANCE hInstance, LPCSTR labelText, int x, int y, int id)
{
    // Create label
    CreateLabel(hwndParent, hInstance, labelText, x, y, id + 1);

    // Create textbox right below the label
    return CreateTextBox(hwndParent, hInstance, x, y + 25, id); // Offset Y to place textbox below label
}

/**
 * Handles the button click by retrieving text from the textbox
 * and displaying it in a message box.
 *
 * @param hwnd          Handle to the main window.
 * @param hwndTextBox   Handle to the textbox.
 */
void HandleButtonClick(HWND hwnd, HWND hwndTextBox)
{
    char text[256];
    GetWindowText(hwndTextBox, text, sizeof(text));                    // Get user input
    MessageBox(hwnd, text, "You Entered", MB_OK | MB_ICONINFORMATION); // Show it
}

// Calculates the total wire length needed for a helical wrap
double calculateWireLength(double coreDiameter, double pitch, double coilLength)
{
    double turns = coilLength / pitch;
    double lengthPerTurn = sqrt(pow(M_PI * coreDiameter, 2) + pow(pitch, 2));
    double totalLength = turns * lengthPerTurn;
    return totalLength;
}
