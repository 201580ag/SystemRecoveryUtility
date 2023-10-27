#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

bool ExecuteSystemCommands() {
    int result = 0;

    result = system("dism /online /cleanup-image /restorehealth");
    if (result != 0) {
        return false;
    }

    result = system("sfc /scannow");
    if (result != 0) {
        return false;
    }

    result = system("chkdsk");
    if (result != 0) {
        return false;
    }

    return true;
}

int main() {
    if (ExecuteSystemCommands()) {
        MessageBox(NULL, L"작업이 성공적으로 완료되었습니다.", L"성공", MB_ICONINFORMATION);
    }
    else {
        MessageBox(NULL, L"작업이 실패하였거나 오류가 발생했습니다.", L"오류", MB_ICONERROR);
    }

    return 0;
}
