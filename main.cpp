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
        MessageBox(NULL, L"�۾��� ���������� �Ϸ�Ǿ����ϴ�.", L"����", MB_ICONINFORMATION);
    }
    else {
        MessageBox(NULL, L"�۾��� �����Ͽ��ų� ������ �߻��߽��ϴ�.", L"����", MB_ICONERROR);
    }

    return 0;
}
