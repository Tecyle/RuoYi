#pragma once
#include "ry_stdlib.h"

typedef enum RYCompilerState
{

} RYCompileState;

class RYCompiler
{
protected:

public:
	virtual bool Compile(LPCTSTR srcFile, LPCTSTR dstFile) = 0;
	virtual 
};

class RYCppCompiler : public RYCompiler
{
public:
	virtual bool Compile(LPCTSTR srcFile, LPCTSTR dstFile);
};