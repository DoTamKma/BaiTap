#include <windows.h>
#include <commctrl.h>

#define ID_TEXT 10
#define B_Add 11
#define B_Sub 12
#define B_Mul 13
#define B_Div 14
#define ID_Result 15
#define B_Clear 16
// gọi hàm xử lý
LRESULT CALLBACK Calculator(HWND, UINT, WPARAM, LPARAM);
//Khai báo hàm winmain()
void AddControls(HWND hwnd);
char buffer[1024];
HWND hOut, hResult, hAdd, hSub, hMul, hDiv, hClear;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR pCmdLine, int nCmdShow) {

    MSG  msg;
    HWND hwnd;
    WNDCLASSW wc;
// Style của cửa sổ
    wc.style         = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
//Tên của class
    wc.lpszClassName = L"Calculator";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpszMenuName  = NULL;
//Khai báo hàm xử lý cho class
    wc.lpfnWndProc   = Calculator;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
//đăng ký cửa sổ
    RegisterClassW(&wc);
//Hàm tao cửa sổ mới để hiển thị text
    hwnd = CreateWindowW(wc.lpszClassName, L"Calculator",
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                100, 100, 450, 560, NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0)) {

        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

LRESULT CALLBACK Calculator(HWND hwnd, UINT msg,
    WPARAM wParam, LPARAM lParam) {

    switch(msg)
    {
        case WM_COMMAND:
            for(int i=0;i<=9;i++)
            {
                if (LOWORD(wParam) == i)
                {
                    GetDlgCtrlID(hwnd);
                    SetDlgItemInt(hwnd, ID_TEXT, i, 0);
                }
            }
            if (LOWORD(wParam) == B_Add)
            {
                char add, out;
                GetWindowText(hOut, add, "+");
                SetWindowTextW(hwnd, B_Add);
            }
            if (LOWORD(wParam) == B_Sub)
            {
                SetDlgItemInt(hwnd, ID_TEXT, "-", 0);
            }
            if (LOWORD(wParam) == B_Add)
            {
                SetDlgItemInt(hwnd, ID_TEXT, "*", 0);
            }
            if (LOWORD(wParam) == B_Sub)
            {
                SetDlgItemInt(hwnd, ID_TEXT, "/", 0);
            }
            if (LOWORD(wParam) == B_Clear)
            {
                SetDlgItemText(hwnd, ID_TEXT, "0");
                break;
            }

            break;
        case WM_CREATE:
            AddControls(hwnd);
            break;

        case WM_DESTROY:

            PostQuitMessage(0);
          break;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}
void AddControls(HWND hwnd)
{
    hOut= CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | ES_AUTOHSCROLL | ES_AUTOVSCROLL| ES_MULTILINE, 10, 10, 400, 80, hwnd, (HMENU)ID_TEXT, NULL, NULL);
    CreateWindowW(L"Button",L"1",WS_VISIBLE | WS_CHILD |SS_LEFT, 10, 110, 75, 50, hwnd, (HMENU) 1, NULL, NULL);
    CreateWindowW(L"Button",L"2",WS_VISIBLE | WS_CHILD | SS_LEFT, 110, 110, 75, 50, hwnd,(HMENU) 2 , NULL, NULL);
    CreateWindowW(L"Button",L"3",WS_VISIBLE | WS_CHILD | SS_LEFT, 210, 110, 75, 50, hwnd, (HMENU) 3, NULL, NULL);
    hAdd = CreateWindowW(L"Button",L"+",WS_VISIBLE | WS_CHILD | SS_LEFT, 310, 110, 100, 50, hwnd,(HMENU) B_Add , NULL, NULL);

    CreateWindowW(L"Button",L"4",WS_VISIBLE | WS_CHILD |SS_LEFT, 10, 180, 75, 50, hwnd, (HMENU) 4, NULL, NULL);
    CreateWindowW(L"Button",L"5",WS_VISIBLE | WS_CHILD | SS_LEFT, 110, 180, 75, 50, hwnd, (HMENU) 5, NULL, NULL);
    CreateWindowW(L"Button",L"6",WS_VISIBLE | WS_CHILD | SS_LEFT, 210, 180, 75, 50, hwnd, (HMENU) 6, NULL, NULL);
    hSub = CreateWindowW(L"Button",L"-",WS_VISIBLE | WS_CHILD | SS_LEFT, 310, 180, 100, 50, hwnd, (HMENU) B_Sub, NULL, NULL);

    CreateWindowW(L"Button",L"7",WS_VISIBLE | WS_CHILD |SS_LEFT, 10, 250, 75, 50, hwnd, (HMENU) 7, NULL, NULL);
    CreateWindowW(L"Button",L"8",WS_VISIBLE | WS_CHILD | SS_LEFT, 110, 250, 75, 50, hwnd, (HMENU) 8, NULL, NULL);
    CreateWindowW(L"Button",L"9",WS_VISIBLE | WS_CHILD | SS_LEFT, 210, 250, 75, 50, hwnd, (HMENU) 9, NULL, NULL);
    hMul= CreateWindowW(L"Button",L"*",WS_VISIBLE | WS_CHILD | SS_LEFT, 310, 250, 100, 50, hwnd, (HMENU) B_Mul, NULL, NULL);

    hClear = CreateWindowW(L"Button",L"C",WS_VISIBLE | WS_CHILD |SS_LEFT, 10, 320, 75, 50, hwnd, (HMENU) B_Clear, NULL, NULL);
    CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD | SS_LEFT, 110, 320, 75, 50, hwnd, (HMENU) 0, NULL, NULL);
    CreateWindowW(L"Button",L".",WS_VISIBLE | WS_CHILD | SS_LEFT, 210, 320, 75, 50, hwnd, NULL, NULL, NULL);
    hDiv = CreateWindowW(L"Button",L"/",WS_VISIBLE | WS_CHILD | SS_LEFT, 310, 320, 100, 50, hwnd, (HMENU) B_Div, NULL, NULL);

    hResult= CreateWindowW(L"Button", L"=", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 10, 390, 400, 50, hwnd, (HMENU) ID_Result, NULL, NULL);
}
void Calc()
{
    //Them ham xu ly

}
