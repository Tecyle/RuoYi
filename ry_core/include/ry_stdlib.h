#pragma once
#include <tchar.h>

typedef unsigned int RYCompileErrorNumber;
typedef int RYReturnCode;

#ifdef _UNICODE
#define RYString wstring
#else
#define RYString string
#endif

#ifdef __cplusplus
#define interface class
#else
#define interface struct
#endif

interface RYStream
{
public:
	virtual size_t Read(LPTSTR buff, size_t maxSize);
	virtual size_t Write(LPTSTR buff, size_t maxSize);
};

RYReturnCode RYRunProcess(LPCTSTR procName, RYStream* input, RYStream* output, RYStream* err);