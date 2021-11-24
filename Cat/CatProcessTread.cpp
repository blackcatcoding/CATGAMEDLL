#include "pch.h"
#include "framework.h"
#include "Cat.h"


DWORD MyCat::GetWindowProcessId(HWND hWnd) {
	DWORD process_id;
	DWORD thread_id;
	thread_id = ::GetWindowThreadProcessId(hWnd, &process_id);
	if (thread_id)
		return process_id;
	return NULL;
}

HANDLE MyCat::OpenProcess(DWORD dwProcessId) {
	HANDLE process_hwnd = ::OpenProcess(PROCESS_ALL_ACCESS, NULL, dwProcessId);
	if (process_hwnd)
		return process_hwnd;
	else
		return NULL;
}

