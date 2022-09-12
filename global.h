#pragma once
#include <windows.h>
#include <winuser.rh>
#define DISABLE_QUICK_EDIT_MODE 0x01
#define DISABLE_INSERT_MODE 0x02
#define DISABLE_MOUSE_INPUT 0x03 
#define DISABLE_ALL (DISABLE_QUICK_EDIT_MODE | DISABLE_INSERT_MODE | DISABLE_MOUSE_INPUT)

// ϵͳ����
// bool	NeedLogin			= false;
bool	NeedLogin			= true;
// bool	NeedCheck			= false;
bool	NeedCheck			= true;
bool	enableCommand		= true;
bool	CheckColor			= true;
bool	CheckCalc			= true;
bool	CheckMaxMem			= true;
int		CheckMaxMemEnd		= 0xfff;
int		CheckMaxMemCount	= 3;



// ռλ����
void __DEBUG_PAUSE() {};
void __SKIP() {};

// ����̨����
VOID KillConsoleCloseButton(VOID) {
    DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE),
        SC_CLOSE, MF_DISABLED);
    DrawMenuBar(GetConsoleWindow());
}
VOID SetTitle(LPCSTR lpTitle) {
    SetConsoleTitle(lpTitle);
}

VOID CloseConsoleMode(UINT uTag = DISABLE_QUICK_EDIT_MODE)
{	//ͨ�ú���
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    if (uTag & DISABLE_QUICK_EDIT_MODE)
        mode &= ~ENABLE_QUICK_EDIT_MODE;  //�Ƴ����ٱ༭ģʽ
    if (uTag & DISABLE_INSERT_MODE)
        mode &= ~ENABLE_INSERT_MODE;      //�Ƴ�����ģʽ
    if (uTag & DISABLE_MOUSE_INPUT)
        mode &= ~ENABLE_MOUSE_INPUT;
    SetConsoleMode(hStdin, mode);
    return;
}