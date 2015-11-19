#include "stdafx.h"
#include "ry_sand_box.h"


int RYSandBox::RunProcessInSandBox(LPCTSTR procName)
{
	// 重定向程序的标准输入输出和错误流
	SECURITY_ATTRIBUTES sa = { 0 };
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	HANDLE  hInStreamRead;
	CreatePipe(&hInStreamRead, &hStdInput, &sa, 0);
	SetHandleInformation(hStdInput, HANDLE_FLAG_INHERIT, 0);

	HANDLE hOutStreamWrite;
	CreatePipe(&hStdOutput, &hOutStreamWrite, &sa, 0);
	SetHandleInformation(hStdOutput, HANDLE_FLAG_INHERIT, 0);

	HANDLE hErrStreamWrite;
	CreatePipe(&hStdError, &hErrStreamWrite, &sa, 0);
	SetHandleInformation(hStdError, HANDLE_FLAG_INHERIT, 0);

	STARTUPINFO startUpInfo = { 0 };
	startUpInfo.cb = sizeof(STARTUPINFO);
	startUpInfo.hStdInput = hInStreamRead;
	startUpInfo.hStdOutput = hStdOutput;
	startUpInfo.hStdError = hStdError;
	startUpInfo.dwFlags |= STARTF_USESTDHANDLES;

	CreateProcess(procName, NULL, NULL, NULL, FALSE, DEBUG_ONLY_THIS_PROCESS, NULL, NULL, &startUpInfo, &piProcInfo);

	DEBUG_EVENT debugEvent;
	while (WaitForDebugEvent(&debugEvent, INFINITE))
	{
		ProcessDebugEvents(&debugEvent);
	}
}

DWORD RYSandBox::ProcessDebugEvents(LPDEBUG_EVENT event)
{
	switch (event->dwDebugEventCode)
	{
	case EXCEPTION_DEBUG_EVENT:
		if (!bDebugProcRuning && event->u.Exception.ExceptionRecord.ExceptionCode == EXCEPTION_BREAKPOINT)
			return DBG_CONTINUE;
		return OnExceptionOccur(event);
	case CREATE_THREAD_DEBUG_EVENT:
		return OnCreateThread(event);
	case CREATE_PROCESS_DEBUG_EVENT:
		return OnCreateProcess(event);
	case EXIT_THREAD_DEBUG_EVENT:
		return OnExitThread(event);
	case EXIT_PROCESS_DEBUG_EVENT:
		return OnExitProcess(event);
	case LOAD_DLL_DEBUG_EVENT:
		return OnLoadDll(event);
	case UNLOAD_DLL_DEBUG_EVENT:
		return OnUnloadDll(event);
	case OUTPUT_DEBUG_STRING_EVENT:
		return OnOutputDebugString(event);
	default:
		return DBG_CONTINUE;
	}
}

BOOL RYSandBox::InjectAPIHookDll(LPCTSTR dllName)
{
	CONTEXT context;
	context.ContextFlags = CONTEXT_ALL;
	if(!GetThreadContext(piProcInfo.hThread, &context))
		return FALSE;
	context.SegCs + context.Eip;
	VirtualProtectEx(piProcInfo.hProcess, );

	LoadLibraryW()
}
