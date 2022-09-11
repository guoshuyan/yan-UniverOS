#pragma once

string username;
string password;

// https://www.cnblogs.com/youdias/p/9643456.html
string GetPasswordWithOutPlainAata()
{
	string ret;
	char ch;
	ch = _getch();
	while (ch != '\n' && ch != '\r')
	{
		ret += ch;
		//cout << "debug:" << ret << endl;
		ch = _getch();
	}

	return ret;

}

string GetPasswordWithStar()
{
	string ret;
	char ch;
	ch = _getch();
	while (ch != '\n' && ch != '\r')
	{
		_putch('*');
		ret += ch;
		ch = _getch();
	}

	return ret;

}


string GetPasswordAnotherChar(char rch)
{
	string ret;
	char ch;
	ch = _getch();
	while (ch != '\n' && ch != '\r')
	{
		_putch(rch);
		ret += ch;
		ch = _getch();
	}

	return ret;

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
			password = GetPasswordWithStar();
			cout << endl;
			if (md5(password) == shuyan.UserPassword) {
				break;
			}
			else {
				cout << "Password error." << endl;
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
			password = GetPasswordWithStar();
			cout << endl;
			if (md5(password) == shuyan.UserPassword) {
				break;
			}
			else {
				cout << "Password error." << endl;
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