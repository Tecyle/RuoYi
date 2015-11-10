//////////////////////////////////////////////////////////////////////////
// C++ 编译器使用的是 g++ 编译器

#pragma once
#include "ry_compiler.h"

class RYCppCompiler :
	public RYCompiler
{
private:
#ifdef _WINDOWS_
	RYString compilerFileName = _T("Windows\\MinGW\\bin\\g++.exe");
#endif

public:
	virtual bool Compile(LPCTSTR srcFile, LPCTSTR dstFile);
	virtual RYCompilerState GetLastError();
	virtual const RYCompileError* GetLastCompileError();
	virtual bool SetCompileParam(RYCompilerParams param, void* data);
	virtual void* GetCompileParam(RYCompilerParams param);

	virtual bool Initialize(LPCTSTR initFile = NULL);
	virtual void CoInitialize();
};