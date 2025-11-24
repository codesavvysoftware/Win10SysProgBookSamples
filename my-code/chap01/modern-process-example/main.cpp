#include <Windows.h>
#include <iostream>

int main() {
    STARTUPINFO si{};
    si.cb = sizeof(si);

    PROCESS_INFORMATION pi{};
    LPCWSTR cmd = L"notepad.exe";

    if (!CreateProcessW(
        nullptr,
        const_cast<LPWSTR>(cmd),
        nullptr,
        nullptr,
        FALSE,
        CREATE_NEW_CONSOLE,
        nullptr,
        nullptr,
        &si,
        &pi
    )) {
        std::wcerr << L"CreateProcess failed: " << GetLastError() << L"\n";
        return 1;
    }

    std::wcout << L"Child PID: " << pi.dwProcessId << L"\n";

    WaitForSingleObject(pi.hProcess, INFINITE);

    DWORD exitCode{};
    GetExitCodeProcess(pi.hProcess, &exitCode);

    std::wcout << L"Child exited with code: " << exitCode << L"\n";

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);

    return 0;
}
