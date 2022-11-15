#include <windows.h>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>
#include <cstring>
#include <string>

void killProcessById(int ProcessID){
    HANDLE handle = OpenProcess(PROCESS_TERMINATE, FALSE, ProcessID);
    if (nullptr != handle) {
        TerminateProcess(handle, 0);
        CloseHandle(handle);
    }
}

void killProcessByName(const char *filename) {
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof(pEntry);
    BOOL hRes = Process32First(hSnapShot, &pEntry);
    while (hRes) {
        if (strcmp(pEntry.szExeFile, filename) == 0) {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0, (DWORD) pEntry.th32ProcessID);
            if (hProcess != nullptr) {
                TerminateProcess(hProcess, 9);
                CloseHandle(hProcess);
            }
        }
        hRes = Process32Next(hSnapShot, &pEntry);
    }
    CloseHandle(hSnapShot);
}


int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; ++i)
    {
        if (strcmp(argv[i], "--name") == 0)
        {
            killProcessByName(argv[i + 1]);
        }
        if (strcmp(argv[i], "--id") == 0)
        {
            killProcessById(std::stoi(argv[i + 1]));
        }
    }

    return 0;
}
