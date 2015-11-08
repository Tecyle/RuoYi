// ry_core.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "ry_core.h"


// 这是导出变量的一个示例
RY_CORE_API int nry_core=0;

// 这是导出函数的一个示例。
RY_CORE_API int fnry_core(void)
{
	return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 ry_core.h
Cry_core::Cry_core()
{
	return;
}
