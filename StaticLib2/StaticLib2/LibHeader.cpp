#include "LibHeader.h"

void Output::OutFuncs::ConfirmationStringOutStat()
{
	std::cout << "******This is Static Library functions******" << std::endl;
}
bool IsThreadSuspended(HANDLE hThread)
{
    // Suspend the thread temporarily
    DWORD suspendCount = SuspendThread(hThread);

    if (suspendCount == (DWORD)-1) {
        // The thread is not running or an error occurred
        ResumeThread(hThread); // Resume the thread if it was not running
        return false;
    }

    // Resume the thread to its original state
    DWORD resumeCount = ResumeThread(hThread);

    if (resumeCount == (DWORD)-1) {
        // An error occurred while resuming the thread
        return false;
    }

    // Check if the thread was suspended
    return (suspendCount > 0) && (resumeCount > suspendCount);
}

std::string GetPriorityName(int dwPriority)
{
    std::string result;
    switch (dwPriority)
    {
    case THREAD_PRIORITY_NORMAL:
        result = "Normal";
        break;

    case THREAD_PRIORITY_ABOVE_NORMAL:
        result = "Above Normal";
        break;

    case THREAD_PRIORITY_BELOW_NORMAL:
        result = "Below Normal";
        break;

    case THREAD_PRIORITY_HIGHEST:
        result = "Highest";
        break;

    case THREAD_PRIORITY_TIME_CRITICAL:
        result = "Time Critical";
        break;

    case THREAD_PRIORITY_IDLE:
        result = "Idle";
        break;

    case THREAD_PRIORITY_LOWEST:
        result = "Lowest";
        break;

    default:
        break;
    }

    return result;
}

ULONGLONG Output::OutFuncs::ConvertKernelTimeStat(FILETIME kernelTime)
{
    ULONGLONG microseconds;
    ULONGLONG kernelTimeIn100NanoSeconds = ((ULONGLONG)kernelTime.dwHighDateTime << 32) + kernelTime.dwLowDateTime;


    // Convert 100-nanosecond intervals to microseconds.
    microseconds = kernelTimeIn100NanoSeconds / 10;

    return microseconds;
}

void Output::OutFuncs::OutputInfoStat(HANDLE thread, DWORD dwThread)
{
    std::cout << "TID: " << dwThread << std::endl;

    if (IsThreadSuspended(thread))
        std::cout << "Status: Suspended" << std::endl;
    else
        std::cout << "Status: Running" << std::endl;

    std::cout << "Priority: " << GetPriorityName(GetThreadPriority(thread)) << std::endl;
}