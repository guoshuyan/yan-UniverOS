#pragma once

string username;

bool CheckPassWord(string password)/*��"*"�������룬���λ���*/
{
	bool judge = false;
	int i = 0;
	int times = 1;
	string s;
	char ch;
	char pw[50];
	while (times <= 3)
	{
		i = 0;
		while ((ch = _getch()) != '\r')
		{
			if (ch == '\b' && i > 0)//�˸�
			{
				printf("\b \b");
				i--;
			}
			else
			{
				pw[i++] = ch;
				cout << '*';
			}
		}
		pw[i] = '\0';
		cout << endl;
		if (password.compare(md5(pw)) != 0)
		{
			if (times == 3)
				cout << "��������˳���" << endl << endl;
			else
				cout << "�������ʣ��" << (3 - times) << "�λ��᣺";
			times++;
		}
		else
		{
			cout << "������ȷ��" << endl << endl;
			judge = true;
			return judge;
		}
	}
	if (times == 4)
		return judge;
	return judge;
}


void login(int Mode) {
	if (Mode == 0) {
		cout << "<---------- Login ---------->" << endl;
		while (1) {
			cout << "User : ";
			cin >> username;
			if (username == shuyan.UserName) {
				cout << "Welcome Back , " << shuyan.UserRealName << endl;
				cout << "Please input your password" << endl;
				break;
			} else {
				cout << "The user was not found" << endl;
				for (int i = 5; i >= 1; i--) {
					cout << "Please try again in " << i << " seconds." << endl;
					_sleep(1000);
				}
			}
		}
		while (1) {
			cout << "Password : ";
			if (CheckPassWord(shuyan.UserPassword)) {
				break;
			}
			else {
				for (int i = 3; i >= 1; i--) {
					cout << "Please try again in " << i << " seconds.\n";
					_sleep(1000);
				}
			}
		}
		cout << "<---------- Login succeeded! ---------->" << endl;
	} else {
		cout << "<---------- Authentication ---------->" << endl;
		while (1) {
			cout << "User : ";
			cin >> username;
			if (username == shuyan.UserName) {
				cout << "Please input your password" << endl;
				break;
			}
			else {
				cout << "The user was not found" << endl;
				for (int i = 5; i >= 1; i--) {
					cout << "Please try again in " << i << " seconds.\n";
					_sleep(1000);
				}
			}
		}
		while (1) {
			cout << "Password : ";
			if (CheckPassWord(shuyan.UserPassword)) {
				break;
			}
			else {
				for (int i = 3; i >= 1; i--) {
					cout << "Please try again in " << i << " seconds.\n";
					_sleep(1000);
				}
			}
		}
		cout << "<---------- Authentication succeeded! ---------->" << endl;
	}
	_sleep(3 * 1000);
	system("cls");
}