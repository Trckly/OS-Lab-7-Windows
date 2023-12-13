#include "Threads.h"
#include "LibHeader.h"

const std::string Threads::Info = "Shlomiak Danylo StudentID:BK13914809\n";

Threads::Threads()
{
    HMODULE mylib = LoadLibrary((LPCWSTR)(L"C:\\Users\\bossofthisgym\\source\\repos\\Dll1\\ARM64\\Debug\\Dll1.dll"));
    if (mylib == NULL) { std::cerr << "Can`t open Dll1: " << GetLastError(); }

    ConvertKernelTime = (MYFUNC_oneParam_RetVal_ull)GetProcAddress(mylib, "ConvertKernelTime");
    if (ConvertKernelTime == NULL) { std::cerr << "Can`t bind ConvertKernelTime: " << GetLastError(); }

    OutputInfo = (MYFUNC_twoParams)GetProcAddress(mylib, "OutputInfo");
    if (OutputInfo == NULL) { std::cerr << "Can`t bind OutputInfo: " << GetLastError(); }

    ConfirmationStringOut = (MYFUNC)GetProcAddress(mylib, "ConfirmationStringOut");
    if (ConfirmationStringOut == NULL) { std::cerr << "Can`t bind ConfirmationStringOut: " << GetLastError(); }

    Test = (MYFUNC)GetProcAddress(mylib, "TestFunc");
    if (Test == NULL) { std::cerr << "Can`t bind Test: " << GetLastError(); }
}

DWORD WINAPI Threads::CycleOutputAsync(PVOID pvParam)
{
    DWORD dwResult = 0;
    int* gap = static_cast<int*>(pvParam);
    int counter = *gap;
    std::ofstream fout(R"(\\Mac\Home\Documents\OC\OC Lab 3\ThreadManager\Log.txt)", std::ios::app);

    for (int i = 0; i < counter; ++i)
        for (auto Character : Info)
            fout << Character;

    fout.close();
    return dwResult;
}

void Threads::ExecDynamicFuncs()
{
    ConfirmationStringOut();
    if (!(thread = CreateThread(0, 0, CycleOutputAsync, static_cast<LPVOID>(&GeneralGap), 0, &dwThread))) {
        std::cerr << "Failed to create thread!" << std::endl;
    }
    OutputInfo(thread, dwThread);
    WaitForSingleObject(thread, INFINITE);

    FILETIME creationTime, exitTime, kernelTime, userTime;
    GetThreadTimes(thread, &creationTime, &exitTime, &kernelTime, &userTime);
    ULONGLONG OverallTime = ConvertKernelTime(kernelTime);

    std::cout << "Time: " << OverallTime << std::endl;
    CloseHandle(thread);
}

void Threads::EXecStaticFuncs()
{
    Output::OutFuncs::ConfirmationStringOutStat();
   if (!(thread = CreateThread(0, 0, CycleOutputAsync, static_cast<LPVOID>(&GeneralGap), 0, &dwThread))) {
        std::cerr << "Failed to create thread!" << std::endl;
    }
    Output::OutFuncs::OutputInfoStat(thread, dwThread);
    WaitForSingleObject(thread, INFINITE);

    FILETIME creationTime, exitTime, kernelTime, userTime;
    GetThreadTimes(thread, &creationTime, &exitTime, &kernelTime, &userTime);
    ULONGLONG OverallTime = Output::OutFuncs::ConvertKernelTimeStat(kernelTime);

    std::cout << "Time: " << OverallTime << std::endl;
    CloseHandle(thread);
}
