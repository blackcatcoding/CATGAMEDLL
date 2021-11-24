#include "pch.h"
#include "framework.h"
#include "Cat.h"

int MyCat::MoveTo(int x, int y) {
	if (SetCursorPos(x, y))
		return 1;
	return 0;
}

void MyCat::LeftClick() {
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

BOOL MyCat::GetCursorPos(LPPOINT lpPoint) {
	BOOL ret = ::GetCursorPos(lpPoint);
	if (ret) return ret;
	return 0;
}


