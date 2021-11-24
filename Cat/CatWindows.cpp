#include "pch.h"
#include "framework.h"
#include "Cat.h"

int MyCat::MessageBox(HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType) {
	int ret = ::MessageBoxA(hWnd, lpText, lpCaption, uType);
	return ret;
}

HWND MyCat::FindWindow(LPCTSTR lpClassName, LPCTSTR lpWindowName) {
	HWND hwnd = ::FindWindowA(lpClassName, lpWindowName);
	if (hwnd)
		return hwnd;
	return NULL;
}

int MyCat::GetClientRect(HWND hWnd, LPRECT lpRect) {
	BOOL ret = ::GetWindowRect(hWnd, lpRect);
	if (ret)
		return 1;
	return 0;
}

int MyCat::SetWindowText(HWND hWnd, LPCTSTR lpString) {
	BOOL ret = ::SetWindowTextA(hWnd, lpString);
	if (ret)
		return 1;
	return 0;
}

BOOL MyCat::SetWindowTop(HWND hWnd) {
	BOOL ret = ::SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
	if (ret) return ret;
	return 0;
}