#include "pch.h"
#include "framework.h"
#include "Cat.h"

LL MyCat::ReadInt(HANDLE hProcess, int lpBaseAddress, int nBytes) {

	BOOL ret;

	if (nBytes == 1) {
		char num;
		ret = ::ReadProcessMemory(hProcess, (LPCVOID)lpBaseAddress, (LPVOID)&num, nBytes, NULL);
		if (ret)
			return num;
		else
			return 0;
	}
	else if (nBytes == 4) {
		int num;
		ret = ::ReadProcessMemory(hProcess, (LPCVOID)lpBaseAddress, (LPVOID)&num, nBytes, NULL);
		if (ret)
			return num;
		else
			return 0;
	}
	else if (nBytes == 8) {
		long long num;
		ret = ::ReadProcessMemory(hProcess, (LPCVOID)lpBaseAddress, (LPVOID)&num, nBytes, NULL);
		if (ret)
			return num;
		else
			return 0;
	}

	return 0;

}

BOOL MyCat::WriteInt(HANDLE hProcess, int lpBaseAddress, int lpBuffer, int nBytes) {

	if (nBytes == 1) {
		BOOL ret = ::WriteProcessMemory(hProcess, (LPVOID)lpBaseAddress, (LPCVOID)lpBuffer, nBytes, NULL);
		if (ret)
			return ret;
		else
			return 0;
	}
	else if (nBytes == 4) {
		BOOL ret = ::WriteProcessMemory(hProcess, (LPVOID)lpBaseAddress, (LPCVOID)lpBuffer, nBytes, NULL);
		if (ret)
			return ret;
		else
			return 0;
	}
	else if (nBytes == 8) {
		BOOL ret = ::WriteProcessMemory(hProcess, (LPVOID)lpBaseAddress, (LPCVOID)lpBuffer, nBytes, NULL);
		if (ret)
			return ret;
		else
			return 0;
	}
	return 0;
}

BOOL MyCat::ReadProcessMemory(HANDLE hProcess, LPCVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize) {
	int ret = ::ReadProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, NULL);
	if (ret)
		return 1;
	else
		return 0;
}

