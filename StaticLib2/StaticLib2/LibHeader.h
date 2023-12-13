#pragma once

#include <Windows.h>
#include <iostream>

namespace Output
{
	class OutFuncs 
	{
	public:
		static void ConfirmationStringOutStat();
		static ULONGLONG ConvertKernelTimeStat(FILETIME kernelTime);
		static void OutputInfoStat(HANDLE thread, DWORD dwThread);
	};
}