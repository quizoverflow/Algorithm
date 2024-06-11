#include <windows.h>
#include <iostream>

// 전역 변수
HHOOK hHook = NULL;
bool capsLockActive = false;

// 키보드 후크 프로시저
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && wParam == WM_KEYDOWN) {
        KBDLLHOOKSTRUCT *pKeyBoard = (KBDLLHOOKSTRUCT *)lParam;
        DWORD vkCode = pKeyBoard->vkCode;
        
        // Caps Lock 키 상태 확인
        if (vkCode == VK_CAPITAL) {
            capsLockActive = !capsLockActive;
            return 1; // Caps Lock 키가 기본 동작을 하지 않도록 차단
        }

        if (capsLockActive) {
            // Caps Lock + P : Caps Lock On/Off
            if (vkCode == 'P') {
                // Caps Lock 상태 토글
                keybd_event(VK_CAPITAL, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
                keybd_event(VK_CAPITAL, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
                return 1;
            }
            // Caps Lock + I/K/J/L : 방향키 상/하/좌/우
            if (vkCode == 'I') {
                keybd_event(VK_UP, 0, 0, 0);
                keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
                return 1;
            }
            if (vkCode == 'K') {
                keybd_event(VK_DOWN, 0, 0, 0);
                keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
                return 1;
            }
            if (vkCode == 'J') {
                keybd_event(VK_LEFT, 0, 0, 0);
                keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
                return 1;
            }
            if (vkCode == 'L') {
                keybd_event(VK_RIGHT, 0, 0, 0);
                keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
                return 1;
            }
            // Caps Lock + F : End
            if (vkCode == 'F') {
                keybd_event(VK_END, 0, 0, 0);
                keybd_event(VK_END, 0, KEYEVENTF_KEYUP, 0);
                return 1;
            }
            // Caps Lock + D : Home
            if (vkCode == 'D') {
                keybd_event(VK_HOME, 0, 0, 0);
                keybd_event(VK_HOME, 0, KEYEVENTF_KEYUP, 0);
                return 1;
            }
            // Caps Lock + H : +
            
            if (vkCode == 'H') {
                keybd_event(VK_OEM_PLUS, 0, 0, 0);
                keybd_event(VK_OEM_PLUS, 0, KEYEVENTF_KEYUP, 0);
                return 1;
            }
            // Caps Lock + N : =
            if (vkCode == 'N') {
                keybd_event(VK_OEM_PLUS, 0, 0, 0); // Shift 없는 상태로 '=' 입력
                keybd_event(VK_OEM_PLUS, 0, KEYEVENTF_KEYUP, 0);
                return 1;
            }
            // Caps Lock + U : -
            if (vkCode == 'U') {
                keybd_event(VK_OEM_MINUS, 0, 0, 0);
                keybd_event(VK_OEM_MINUS, 0, KEYEVENTF_KEYUP, 0);
                return 1;
            }
        }
    }
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

int main() {
    // 후크 설치
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (!hHook) {
        std::cerr << "키보드 후크를 설정할 수 없습니다." << std::endl;
        return 1;
    }

    // 메시지 루프
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // 후크 제거
    UnhookWindowsHookEx(hHook);
    return 0;
}
