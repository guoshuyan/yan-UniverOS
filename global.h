#pragma once
#include <windows.h>
#include <winuser.rh>
#define DISABLE_QUICK_EDIT_MODE 0x01
#define DISABLE_INSERT_MODE 0x02
#define DISABLE_MOUSE_INPUT 0x03 
#define DISABLE_ALL (DISABLE_QUICK_EDIT_MODE | DISABLE_INSERT_MODE | DISABLE_MOUSE_INPUT)

// 系统变量
// bool	NeedLogin			= false;
bool	NeedLogin			= true;
// bool	NeedCheck			= false;
bool	NeedCheck			= true;
// bool	TestMode			= true;
bool    TestMode            = false;
bool	enableCommand		= true;
bool	CheckColor			= true;
bool	CheckCalc			= true;
bool	CheckMaxMem			= true;
int		CheckMaxMemEnd		= 0xfff;
int		CheckMaxMemCount	= 3;



// 占位函数
void __DEBUG_PAUSE() {};
void __SKIP() {};

// 控制台参数
VOID KillConsoleCloseButton(VOID) {
    DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE),
        SC_CLOSE, MF_DISABLED);
    DrawMenuBar(GetConsoleWindow());
}
VOID SetTitle(LPCSTR lpTitle) {
    SetConsoleTitle(lpTitle);
}
