#pragma once

void colorcheck() {
	printf(RED "RED TEXT TESTING...\n" NONE);
	_sleep(1 * 100);
	printf(LIGHT_RED "LIGHT RED TEXT TESTING...\n" NONE);
	_sleep(1 * 100);
	printf(GREEN "GREEN TEXT TESTING...\n" NONE);
	_sleep(1 * 100);
	printf(LIGHT_GREEN "LIGHT GREEN TEXT TESTING...\n" NONE);
	_sleep(1 * 100);
	printf(BLUE "BLUE TEXT TESTING...\n" NONE);
	_sleep(1 * 100);
	printf(LIGHT_BLUE "LIGHT BLUE TEXT TESTING...\n" NONE);
	_sleep(1 * 100);
	printf(CYAN "CYAN TEXT TESTING...\n" NONE);
	_sleep(1 * 100);
	printf(LIGHT_CYAN "LIGHT CYAN TEXT TESTING...\n" NONE);
	_sleep(1 * 100);
	printf(PURPLE "PURPLE TEXT TESTING...\n" NONE);
	_sleep(1 * 100);
	printf(LIGHT_PURPLE "LIGHT PURPLE TEXT TESTING...\n" NONE);
	_sleep(1 * 100);
	printf(YELLOW "YELLOW TEXT TESTING...\n" NONE);
	_sleep(1 * 100);
	printf(WHITE "WHITE TEXT TESTING...\n" NONE);
	_sleep(1 * 100);
	printf(DARY_GRAY "DARY GRAY TEXT TESTING...\n" NONE);
	_sleep(3 * 100);
}

void numcheck() {
	srand((unsigned int)time(0));
	for (int i = 0; i <= 5; i++) {
		int a = rand();
		int b = rand();
		cout << a << "\t+\t" << b << "\t=\t" << (a + b) << endl;
		_sleep(1 * 100);
		cout << a << "\t*\t" << b << "\t=\t" << (a * b) << endl;
		_sleep(2 * 100);
	}
}

std::string dec2hex(int i, int width)
{
	stringstream ioss;     //定义字符串流
	string s_temp;         //存放转化后字符
	ioss << hex << i;      //以十六制形式输出
	ioss >> s_temp;

	if (width > s_temp.size())
	{
		std::string s_0(width - s_temp.size(), '0');      //位数不够则补0
		s_temp = s_0 + s_temp;                            //合并
	}

	std::string s = "0x" + s_temp.substr(s_temp.length() - width, s_temp.length());    //取右width位
	return s;
}
void maxmemcheck() {
	for (int i = 0; i <= CheckMaxMemEnd; i++) {
		printf(dec2hex(i, CheckMaxMemCount).c_str());
		printf(" \n");
	}
}

void check() {
	cout << "Power On Self Test Start" << endl;
	_sleep(5 * 100);
	cout << "COLORCHECK is starting..." << endl;
	_sleep(8 * 100);
	system("cls");
	CheckColor ? colorcheck() : __DEBUG_PAUSE();
	_sleep(3 * 100);
	system("cls");
	cout << "Power On Self Test Start" << endl << endl;
	cout << "COLORCHECK is starting..." << endl;
	cout << "COLORCHECK completed!" << endl;
	cout << "NUMBERCHECK is starting..." << endl;
	_sleep(8 * 100);
	system("cls");
	CheckCalc ? numcheck() : __DEBUG_PAUSE();
	_sleep(3 * 100);
	system("cls");
	cout << "Power On Self Test Start" << endl << endl;
	cout << "COLORCHECK is starting..." << endl;
	cout << "COLORCHECK completed!" << endl;
	cout << "NUMBERCHECK is starting..." << endl;
	cout << "NUMBERCHECK completed!" << endl;
	cout << "MAXMEMCHECK is starting..." << endl;
	_sleep(8 * 100);
	system("cls");
	CheckMaxMem ? maxmemcheck() : __DEBUG_PAUSE();
	_sleep(3 * 100);
	system("cls");
	cout << "Power On Self Test Start" << endl << endl;
	cout << "COLORCHECK is starting..." << endl;
	cout << "COLORCHECK completed!" << endl;
	cout << "NUMBERCHECK is starting..." << endl;
	cout << "NUMBERCHECK completed!" << endl;
	cout << "MAXMEMCHECK is starting..." << endl;
	cout << "MAXMEMCHECK completed!" << endl << endl;
	cout << "Power On Self Test Completed" << endl << endl;
	cout << "Press any key to enter UniverOS ..." << endl;
	getch();
	system("cls");
}