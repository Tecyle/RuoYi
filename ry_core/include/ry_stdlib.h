#pragma once

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