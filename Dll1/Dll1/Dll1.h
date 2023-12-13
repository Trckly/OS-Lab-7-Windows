    // libcontents.h - Contains declarations of math functions
    #pragma once

    #include <Windows.h>

    #ifdef DLL1_EXPORTS
    #define DLL1_API __declspec(dllexport)
    #else
    #define DLL1_API __declspec(dllimport)
    #endif

    extern "C" DLL1_API void CALLBACK RunDLLFunction(HWND hwnd, HINSTANCE hinst, LPSTR lpszCmdLine, int nCmdShow)
    {
        MessageBoxA(hwnd, "Hello from DLL!", "DLL Message", MB_OK);
    }

    extern "C" DLL1_API ULONGLONG ConvertKernelTime(FILETIME kernelTime);

    extern "C" DLL1_API void OutputInfo(HANDLE thread, DWORD dwThread);

    extern "C" DLL1_API void ConfirmationStringOut();

    extern "C" DLL1_API void TestFunc();