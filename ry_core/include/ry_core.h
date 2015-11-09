#pragma once


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

