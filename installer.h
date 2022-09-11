#pragma once

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��׼������
//���ù��λ��
void pos(int x, int y)
{
    COORD posPoint = { x,y }; //��������
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
        cout << "1. ��װ ";
    }
    else if (x == 65 && y == 20)
    {
        on_Select();
        cout << "2. �˳� ";
    }
}

void SetFont(int size = 30) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = size;  //���������С
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL; //�����ϸ FW_BOLD
	wcscpy_s(cfi.FaceName, L"����");  //�������壬�����ǿ���̨���е�
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	//��õ�ǰ����
	//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//CONSOLE_FONT_INFO consoleCurrentFont;
	//GetCurrentConsoleFont(handle, FALSE, &consoleCurrentFont);
}
void star()
{
    cyan_choose();
    pos(25, 20);
    cout << "1. ��װ ";
    pos(65, 20);
    cout << "2. �˳� ";
}

void install() {
	system("cls");
	system("color 17");
	SetFont();
    SetConsoleColor(FOREGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "UniverOS Installer [TEST RUN]" << endl << endl;
    cyan_choose();
    cout << "z,m ���ƹ��ѡ�񣻿ո� ȷ��" << endl;
    cyan_choose();
    pos(25, 20);
    on_Select();
    cout << "1. ��װ ";
    pos(65, 20);
    cout << "2. �˳� ";
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
        //��ֹ������Χ
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
        cout << "��װ��..." << endl;
        cout << "[          ] 0%";
        _sleep(3 * 1500);
        system("cls");
        cout << "��װ��..." << endl;
        cout << "[������       ] 32%";
        _sleep(1 * 2000);
        system("cls");
        cout << "��װ��..." << endl;
        cout << "[��������      ] 40%";
        _sleep(12 * 1000);
        system("cls");
        cout << "��װ��..." << endl;
        cout << "[����������������  ] 83%";
        _sleep(5 * 1000);
        system("cls");
        cout << "��װ��..." << endl;
        cout << "[��������������������] 97%";
        _sleep(1 * 1000);
        system("cls");
        cout << "��װ��..." << endl;
        cout << "[��������������������] 98%";
        _sleep(1 * 1000);
        system("cls");
        cout << "��װ��..." << endl;
        cout << "[��������������������] 99%";
        _sleep(10 * 1000);
        system("cls");
        cout << "��װ��..." << endl;
        cout << "[��������������������] 100%" << endl;
        cout << "[...]   ��װ�������ڸ����ļ�..." << endl;
        _sleep(10 * 1000);
        cout << "[...]   ��װ��������Ѱ�ҷ���..." << endl;
        _sleep(10 * 1000);
        cout << "[...]   ��װ�������ڰ�װ��չ..." << endl;
        _sleep(10 * 1000);
        cout << "[...]   ��װ��������д���ļ�..." << endl;
        _sleep(10 * 1000);
        cout << "[...]   ��װ���������޸��ļ�Ȩ��..." << endl;
        _sleep(10 * 1000);
        cout << "[...]   ��װ�������ڲ�������..." << endl;
        _sleep(10 * 1000);
        cout << "[...]   ��װ�������ڹ�����Ϣ..." << endl;
        _sleep(10 * 1000);
        cout << "[...]   ��װ���򼴽����..." << endl;
        _sleep(12 * 1000);
        cout << "[��]     ��װ���������" << endl;
        _sleep(3 * 1000); 
        cout << "[...]   ���ڽ�������" << endl;
        _sleep(1 * 1000);
        installEnd();
        system("cls");

    } else if (x == 65) {
        installEnd();
    } else {
        cout << "����" << endl;
        _sleep(1 * 1000);
        installEnd();
    }
}