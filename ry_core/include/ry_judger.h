//////////////////////////////////////////////////////////////////////////
// 此处定义的是检查器，用于判定一个可执行程序是否满足要求

#pragma once
#include "ry_stdlib.h"

typedef enum RYJudgeState
{
	RYJS_Accepted,					///< 答案被接受
	RYJS_PresentationError,			///< 答案是正确的，但是输出格式有问题
	RYJS_TimeLimitExceeded,			///< 运行超时
	RYJS_MemoryLimitExceeded,		///< 内存使用超过限制
	RYJS_WrongAnswer,				///< 输出的答案是错误的
	RYJS_RuntimeError,				///< 运行时遇到了错误
	RYJS_OutputLimitExceeded,		///< 输出内容超过了规定的限制
	RYJS_CompileError,				///< 编译的时候遇到了错误
	RYJS_SystemError,				///< 系统内部遇到了错误
	RYJS_ValidatorError				///< 提交的程序有异常行为
} RYJudgeState;

class RYRunResult
{
protected:
	size_t memUsed;
	size_t timeUsed;
	RYReturnCode returnCode;
	RYJudgeState state;
};

interface RYJudger
{
public:
	virtual void SetTimeLimit(size_t timeLimit) = 0;
	virtual size_t GetTimeLimit() = 0;
	virtual void SetMemoryLimit(size_t memoInBytes) = 0;
	virtual size_t GetMemoryLimit() = 0;

	virtual RYRunResult Judge(LPCTSTR runableFileName, LPCTSTR inputFile, LPCTSTR outputFile);
};