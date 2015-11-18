#pragma once
#include "ry_stdlib.h"

class RYOjSandBox
{
private:
	bool bDebugProcRuning;	///< 被调试的子进程准备运行时会发出一个 EXCEPTION_BREAKPOINT 异常，
							//	 该变量用于记录子进程是否已经开始运行了

protected:
	HANDLE hStdInput;		///< 子进程的标准输入端口，只可写
	HANDLE hStdOutput;		///< 子进程的标准输出端口，只可读
	HANDLE hStdError;		///< 子进程的标准错误输出，只可读

public:
	virtual void RunProcessInSandBox(LPCTSTR procName);

	virtual DWORD OnExceptionOccur(LPDEBUG_EVENT event);
	virtual DWORD OnCreateProcess(LPDEBUG_EVENT event);
	virtual DWORD OnCreateThread(LPDEBUG_EVENT event);
	virtual DWORD OnExitProcess(LPDEBUG_EVENT event);
	virtual DWORD OnExitThread(LPDEBUG_EVENT event);
	virtual DWORD OnUnloadDll(LPDEBUG_EVENT event);
	virtual DWORD OnLoadDll(LPDEBUG_EVENT event);
	virtual DWORD OnOutputDebugString(LPDEBUG_EVENT event);

protected:
	virtual DWORD ProcessDebugEvents(LPDEBUG_EVENT event);
};