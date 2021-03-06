// 空の Win32 コンソールアプリケーションを作成し、
// 新規クラスを用意すれば OK
//
// 参考：『Windows プログラミングの極意』

#define STRICT
#include <windows.h>
#include <windowsx.h>
#include <ole2.h>
#include <commctrl.h>
#include <shlwapi.h>

#include <iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "comctl32.lib")

HINSTANCE g_hinst;
HWND g_hwndChild;

OVERLAPPED g_o;
HANDLE g_hRegister;

void Cleanup() {
	if (g_hRegister) {
		UnregisterWaitEx(g_hRegister, INVALID_HANDLE_VALUE);
		g_hRegister = NULL;
	}
	if (g_o.hEvent) {
		CloseHandle(g_o.hEvent);
		g_o.hEvent = NULL;
	}
}

void OnSize(HWND hwnd, UINT state, int cx, int cy) {
	if (g_hwndChild) {
		MoveWindow(g_hwndChild, 0, 0, cx, cy, TRUE);
	}
}

void PaintContent(HWND hwnd, PAINTSTRUCT *pps) {
}

void OnPaint(HWND hwnd) {
	PAINTSTRUCT ps;
	BeginPaint(hwnd, &ps);
	PaintContent(hwnd, &ps);
	EndPaint(hwnd, &ps);
}

void OnPrintClient(HWND hwnd, HDC hdc) {
	PAINTSTRUCT ps;
	ps.hdc = hdc;
	GetClientRect(hwnd, &ps.rcPaint);
	ps.fErase = FALSE;
	PaintContent(hwnd, &ps);
}

void RegisterForAddrChange() {
	HANDLE h;
	NotifyAddrChange(&h, &g_o);
}

void CALLBACK OnAddrChanged(void *p, BOOLEAN fTimedOut) {
	MessageBeep(0);
	RegisterForAddrChange();
}

BOOL OnCreate(HWND hwnd, LPCREATESTRUCT lpcs) {
	g_o.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	if (g_o.hEvent &&
		RegisterWaitForSingleObject(&g_hRegister, g_o.hEvent,
			OnAddrChanged, NULL, INFINITE, 0)) {
		RegisterForAddrChange();
		return TRUE;
	}
	Cleanup();
	return FALSE;
}

void OnDestroy(HWND hwnd) {
	Cleanup();
	PostQuitMessage(0);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uiMsg,
	WPARAM wParam, LPARAM lParam) {
	switch (uiMsg) {
		HANDLE_MSG(hwnd, WM_CREATE, OnCreate);
		HANDLE_MSG(hwnd, WM_SIZE, OnSize);
		HANDLE_MSG(hwnd, WM_DESTROY, OnDestroy);
		HANDLE_MSG(hwnd, WM_PAINT, OnPaint);
	case WM_PRINTCLIENT: OnPrintClient(hwnd, (HDC)wParam); return 0;
	}

	return DefWindowProc(hwnd, uiMsg, wParam, lParam);
}

BOOL InitApp(void) {
	WNDCLASS wc;

	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = g_hinst;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = TEXT("Scratch");

	if (!RegisterClass(&wc)) {
		return FALSE;
	}

	InitCommonControls();

	return TRUE;
}

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hinstPrev,
	LPSTR lpCmdLine, int nShowCmd) {
	MSG msg;
	HWND hwnd;

	g_hinst = hinst;

	if (!InitApp()) {
		return 0;
	}

	if (SUCCEEDED(CoInitialize(NULL))) {
		hwnd = CreateWindow(TEXT("Scratch"),
			TEXT("Scratch"),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			CW_USEDEFAULT, CW_USEDEFAULT,
			NULL,
			NULL,
			hinst,
			0);

		ShowWindow(hwnd, nShowCmd);

		while (GetMessage(&msg, NULL, 0, 0)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		CoUninitialize();
	}

	return 0;
}
