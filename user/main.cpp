#include<iostream>
#include <windows.h>
#include <winbase.h>
#include <tlhelp32.h>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>

void killerProcess(const std::string &command) {
    const std::string &str_ = command;
    char *proc = (char *) command.c_str();
    STARTUPINFOA startUpInf = {0};
    PROCESS_INFORMATION procInf = {nullptr};
    if (CreateProcessA("D:/bsu/labaPROC/cmake-build-debug/labaPROC.exe", proc, nullptr,
                       nullptr, FALSE, 0, nullptr,
                       nullptr, &startUpInf, &procInf)) {
        WaitForSingleObject(procInf.hProcess, INFINITE);
        CloseHandle(procInf.hProcess);
        CloseHandle(procInf.hThread);
    }
}

int main() {
    SetEnvironmentVariableA("PROC_TO_KILL", "Telegram,notepad++");

    killerProcess("");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    _putenv("PROC_TO_KILL");

    std::string proc;
    std::cin >> proc;
    if (proc == "end") return 0;
    killerProcess(proc);
}
