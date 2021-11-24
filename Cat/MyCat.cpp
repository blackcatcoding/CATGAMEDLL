// Cat.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "framework.h"
#include "Cat.h"


// 这是导出变量的一个示例
CAT_API int nCat=0;

// 这是导出函数的一个示例。
CAT_API int fnCat(void)
{
    return 0;
}



CAT_API Cat* BlackCat() {
	return new MyCat();
}




