// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 CAT_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// CAT_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef CAT_EXPORTS
#define CAT_API __declspec(dllexport)
#else
#define CAT_API __declspec(dllimport)
#endif
#include <Windows.h>
#include <iostream>

typedef long long LL;

// 调试输出对话框
#define CatBox(fmt, ...); \
CString str; \
str.Format(CString(fmt), __VA_ARGS__); \
AfxMessageBox(str);

extern CAT_API int nCat;

CAT_API int fnCat(void);

class Cat {
public:
	// 窗口
	virtual int MessageBox(HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType) = 0;

	virtual HWND FindWindow(LPCTSTR lpClassName, LPCTSTR lpWindowName) = 0;
	virtual int GetClientRect(HWND hWnd, LPRECT lpRect) = 0;
	virtual int SetWindowText(HWND hWnd, LPCTSTR lpString) = 0;
	virtual BOOL SetWindowTop(HWND hWnd) = 0;

	// 键鼠
	virtual int MoveTo(int x, int y) = 0;
	virtual void LeftClick() = 0;
	virtual BOOL GetCursorPos(LPPOINT lpPoint) = 0;

	// 进程线程
	virtual DWORD GetWindowProcessId(HWND hWnd) = 0;
	virtual HANDLE OpenProcess(DWORD dwProcessId) = 0;
	
	// 内存
	virtual LL ReadInt(HANDLE hProcess, int lpBaseAddress, int nBytes) = 0;
	virtual BOOL ReadProcessMemory(HANDLE hProcess, LPCVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize) = 0;
	virtual BOOL WriteInt(HANDLE hProcess, int lpBaseAddress, int lpBuffer, int nBytes) = 0;

	// 消息处理
	virtual LRESULT SendMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) = 0;

	// 时间
	virtual VOID Delay(DWORD dwMilliseconds) = 0;

};

class MyCat : public Cat {
public:
	// 窗口
	virtual int MessageBox(HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType);

	virtual HWND FindWindow(LPCTSTR lpClassName, LPCTSTR lpWindowName);		// 查找窗口
	virtual int GetClientRect(HWND hWnd, LPRECT lpRect);		// 获取窗口客户区域在屏幕上的位置
	virtual int SetWindowText(HWND hWnd, LPCTSTR lpString);
	virtual BOOL SetWindowTop(HWND hWnd);

	// 键鼠
	virtual int MoveTo(int x, int y);
	virtual void LeftClick();
	virtual BOOL GetCursorPos(LPPOINT lpPoint);

	// 进程线程
	virtual DWORD GetWindowProcessId(HWND hWnd);
	virtual HANDLE OpenProcess(DWORD dwProcessId);

	// 内存
	virtual LL ReadInt(HANDLE hProcess, int lpBaseAddress, int nBytes);
	virtual BOOL ReadProcessMemory(HANDLE hProcess, LPCVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize);
	
	virtual BOOL WriteInt(HANDLE hProcess, int lpBaseAddress, int lpBuffer, int nBytes);

	// 消息处理
	virtual LRESULT SendMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

	// 时间
	virtual VOID Delay(DWORD dwMilliseconds);
};

CAT_API Cat* BlackCat();

