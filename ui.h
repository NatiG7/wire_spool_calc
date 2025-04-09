#ifndef UI_H
#define UI_H

#include <windows.h>

/**
 * @file ui.h
 * @brief Header file for UI component creation and window procedure.
 *
 * This file declares the functions used to create and manage UI elements
 * (window, button, label, textbox) and handle user interaction in a Windows desktop app.
 */

/**
 * Window procedure to handle messages for the main window.
 *
 * @param hwnd     Handle to the window.
 * @param uMsg     Message identifier.
 * @param wParam   Additional message information.
 * @param lParam   Additional message information.
 * @return         Result of message processing.
 */
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

/**
 * Creates and returns the main application window.
 *
 * @param hInstance  Application instance handle.
 * @return           Handle to the created main window.
 */
HWND CreateMainWindow(HINSTANCE hInstance);

/**
 * Creates a push button and returns its handle.
 *
 * @param hwndParent  Handle to the parent window.
 * @param hInstance   Application instance handle.
 * @param labelText   The text label for the button.
 * @param x           The x-coordinate of the button's position.
 * @param y           The y-coordinate of the button's position.
 * @param id          The button's identifier.
 * @return            Handle to the created button.
 */
HWND CreateButton(HWND hwndParent, HINSTANCE hInstance, LPCSTR labelText, int x, int y, int id);

/**
 * Creates a static label and returns its handle.
 *
 * @param hwndParent  Handle to the parent window.
 * @param hInstance   Application instance handle.
 * @param labelText   The text label for the label.
 * @param x           The x-coordinate of the label's position.
 * @param y           The y-coordinate of the label's position.
 * @param id          The label's identifier.
 * @return            Handle to the created label.
 */
HWND CreateLabel(HWND hwndParent, HINSTANCE hInstance, LPCSTR labelText, int x, int y, int id);

/**
 * Creates an editable text box and returns its handle.
 *
 * @param hwndParent  Handle to the parent window.
 * @param hInstance   Application instance handle.
 * @param x           The x-coordinate of the text box's position.
 * @param y           The y-coordinate of the text box's position.
 * @param id          The text box's identifier.
 * @return            Handle to the created text box.
 */
HWND CreateTextBox(HWND hwndParent, HINSTANCE hInstance, int x, int y, int id);

/**
 * Handles button click logic: retrieves text from the textbox and displays it in a message box.
 *
 * @param hwnd          Handle to the main window.
 * @param hwndTextBox   Handle to the text box control.
 */
HWND CreateInputField(HWND hwndParent, HINSTANCE hInstance, LPCSTR labelText, int x, int y, int id);

/**
 * Handles button click logic: retrieves text from the textbox and displays it in a message box.
 *
 * @param hwnd          Handle to the main window.
 * @param hwndTextBox   Handle to the text box control.
 */
void HandleButtonClick(HWND hwnd, HWND hwndTextBox);

#endif // UI_H
