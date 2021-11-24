#include "pch.h"
#include "framework.h"
#include "Cat.h"

LRESULT MyCat::SendMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
	LRESULT ret = ::SendMessageA(hWnd, Msg, wParam, lParam);
	return ret;
}
//
//LRESULT MyCat::PostMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
//	LRESULT ret = ::PostAppMessageA(hWnd, Msg, wParam, lParam);
//	return ret;
//}

