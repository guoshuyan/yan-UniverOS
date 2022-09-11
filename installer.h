#pragma once

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取标准输出句柄
//设置光标位置
void pos(int x, int y)
{
    COORD posPoint = { x,y }; //设置坐标
    SetConsoleCursorPosition(hOut, posPoint);
}
void white_back()
{
    WORD white = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
    SetConsoleTextAttribute(hOut, white);
}
void cyan_choose()
{
    WORD cyan = FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE;
    SetConsoleTextAttribute(hOut, cyan);
}
BOOL SetConsoleColor(WORD wAttributes)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE)
        return FALSE;

    return SetConsoleTextAttribute(hConsole, wAttributes);
}

void installEnd() {
    white_back();
    system("cls");
    WinExec(_pgmptr, SW_SHOW);
    exit(0);
}
void on_Select()
{
    WORD select = FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED;
    SetConsoleTextAttribute(hOut, select);
}
void onChoose(int x, int y)
{
    if (x == 25 && y == 20)
    {
        on_Select();
        cout << "1. 安装 ";
    }
    else if (x == 65 && y == 20)
    {
        on_Select();
        cout << "2. 退出 ";
    }
}

void SetFont(int size = 30) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = size;  //设置字体大小
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL; //字体粗细 FW_BOLD
	wcscpy_s(cfi.FaceName, L"黑体");  //设置字体，必须是控制台已有的
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	//获得当前字体
	//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//CONSOLE_FONT_INFO consoleCurrentFont;
	//GetCurrentConsoleFont(handle, FALSE, &consoleCurrentFont);
}
void star()
{
    cyan_choose();
    pos(25, 20);
    cout << "1. 安装 ";
    pos(65, 20);
    cout << "2. 退出 ";
}

void install() {
	system("cls");
	system("color 17");
	SetFont();
    SetConsoleColor(FOREGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "UniverOS Installer [TEST RUN]" << endl << endl;
    cyan_choose();
    cout << "z,m 控制光标选择；空格 确定" << endl;
    cyan_choose();
    pos(25, 20);
    on_Select();
    cout << "1. 安装 ";
    pos(65, 20);
    cout << "2. 退出 ";
    int x = 65, y = 20;
    char sel;
    sel = getch();
    while (sel != ' ')
    {
        star();
        switch (sel)
        {
        case 'z':
            x = x - 40;
            break;
        case 'm':
            x = x + 40;
            break;
        }
        //防止超出范围
        if (x >= 65)
        {
            x = 65;
        }
        if (x <= 25)
        {
            x = 25;
        }
        pos(x, y);
        onChoose(x, y);
        sel = getch();
    }
    if (x == 25) {
        system("cls");
        cout << "安装中..." << endl;
        cout << "[          ] 0%";
        _sleep(3 * 1500);
        system("cls");
        cout << "安装中..." << endl;
        cout << "[■■■       ] 32%";
        _sleep(1 * 2000);
        system("cls");
        cout << "安装中..." << endl;
        cout << "[■■■■      ] 40%";
        _sleep(12 * 1000);
        system("cls");
        cout << "安装中..." << endl;
        cout << "[■■■■■■■■  ] 83%";
        _sleep(5 * 1000);
        system("cls");
        cout << "安装中..." << endl;
        cout << "[■■■■■■■■■■] 97%";
        _sleep(1 * 1000);
        system("cls");
        cout << "安装中..." << endl;
        cout << "[■■■■■■■■■■] 98%";
        _sleep(1 * 1000);
        system("cls");
        cout << "安装中..." << endl;
        cout << "[■■■■■■■■■■] 99%";
        _sleep(10 * 1000);
        system("cls");
        cout << "安装中..." << endl;
        cout << "[■■■■■■■■■■] 100%" << endl;
        cout << "[...]   安装程序正在复制文件..." << endl;
        _sleep(10 * 1000);
        cout << "[...]   安装程序正在寻找分区..." << endl;
        _sleep(10 * 1000);
        cout << "[...]   安装程序正在安装扩展..." << endl;
        _sleep(10 * 1000);
        cout << "[...]   安装程序正在写入文件..." << endl;
        _sleep(10 * 1000);
        cout << "[...]   安装程序正在修改文件权限..." << endl;
        _sleep(10 * 1000);
        cout << "[...]   安装程序正在测试性能..." << endl;
        _sleep(10 * 1000);
        cout << "[...]   安装程序正在归纳信息..." << endl;
        _sleep(10 * 1000);
        cout << "[...]   安装程序即将完成..." << endl;
        _sleep(12 * 1000);
        cout << "[√]     安装程序已完成" << endl;
        _sleep(3 * 1000); 
        cout << "[...]   正在结束程序" << endl;
        _sleep(1 * 1000);
        installEnd();
        system("cls");

    } else if (x == 65) {
        installEnd();
    } else {
        cout << "错误。" << endl;
        _sleep(1 * 1000);
        installEnd();
    }
}