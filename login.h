#pragma once

string username;
string password;

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
			cin >> password;
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
			cin >> password;
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