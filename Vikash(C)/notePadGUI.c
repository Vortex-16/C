#include <windows.h>

#define ID_TEXTBOX 1

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR args, int ncmdshow) {
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"notepadClone";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"notepadClone", L"My Notepad App",
                  WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  100, 100, 700, 500,
                  NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    static HWND hEdit;

    switch(msg) {
        case WM_CREATE:
            hEdit = CreateWindowW(L"Edit", L"",
                                  WS_CHILD | WS_VISIBLE | WS_BORDER |
                                  ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
                                  10, 10, 660, 430,
                                  hWnd, (HMENU)ID_TEXTBOX, NULL, NULL);
            break;

        case WM_SIZE:
            // Auto-resize textbox with window
            MoveWindow(hEdit, 10, 10, LOWORD(lp) - 20, HIWORD(lp) - 20, TRUE);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}
