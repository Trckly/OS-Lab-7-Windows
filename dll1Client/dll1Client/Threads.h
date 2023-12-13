#pragma once

#include <Windows.h>
#include <iostream>
#include <fstream>

typedef ULONGLONG(__cdecl* MYFUNC_oneParam_RetVal_ull)(FILETIME kernelTime);
typedef void(__cdecl* MYFUNC_twoParams)(HANDLE th, DWORD dwTh);
typedef void(__cdecl* MYFUNC)();

class Threads
{
	static DWORD WINAPI CycleOutputAsync(PVOID pvParam);
	MYFUNC_twoParams OutputInfo;
	MYFUNC ConfirmationStringOut;
	MYFUNC Test;
	static const std::string Info;
	HANDLE thread;
	DWORD dwThread;
	int GeneralGap = 1000000;
	MYFUNC_oneParam_RetVal_ull ConvertKernelTime;

public:
	Threads();

	void ExecDynamicFuncs();
	void EXecStaticFuncs();
};

