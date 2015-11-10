//////////////////////////////////////////////////////////////////////////
// 此处定义的是编译器部分，负责将输入源代码编译成可执行程序

#pragma once
#include "ry_stdlib.h"

typedef enum RYCompilerState
{
	RYCS_Success,			///< 编译成功
	RYCS_CompileError,		///< 编译的时候遇到编译错误
	RYCS_Uninitialized,		///< 编译器对象没有正确初始化
	RYCS_BadFileName,		///< 输入文件找不到或没有写入输出文件的权限
	RYCS_ParamsError,		///< 设定的编译参数不支持
	RYCS_SystemError		///< 未知系统错误
} RYCompileState;

typedef enum RYCompilerParams
{
	RYCP_EnableDebug,			///< 启用调试信息
	RYCP_Optimization,			///< 对代码进行优化
	RYCP_Lib,					///< 指定引入的库文件
	RYCP_Include,				///< 指定需要包含的头文件
	RYCP_EnableWarnings,		///< 指定是否输出警告信息
	RYCP_Macro,					///< 指定预定义宏
	RYCP_TreatWarningAsError	///< 指定是否将警告视为错误
};

class RYCompileError
{
protected:
	RYCompileErrorNumber errNum;		///< 错误号
	RYString errMsg;					///< 错误描述文字
	size_t lineNum;						///< 错误所在行号
	size_t colNum;						///< 错误所在列号
	RYString fileName;					///< 错误所在文件名称

public:
	RYCompileErrorNumber GetErrNum();
	LPCTSTR GetErrMsg();
	size_t GetLineNum();
	size_t GetColNum();
	LPCTSTR GetErrFileName();
};

interface RYCompiler
{
protected:

public:
	virtual bool Compile(LPCTSTR srcFile, LPCTSTR dstFile) = 0;
	virtual RYCompilerState GetLastError() = 0;
	virtual const RYCompileError* GetLastCompileError() = 0;
	virtual bool SetCompileParam(RYCompilerParams param, void* data) = 0;
	virtual void* GetCompileParam(RYCompilerParams param) = 0;

	virtual bool Initialize(LPCTSTR initFile = NULL);
	virtual void CoInitialize();
};
