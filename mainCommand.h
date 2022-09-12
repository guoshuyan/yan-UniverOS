#pragma once

/*
	ID:
	0 - �ɹ�
	-1 - δ�ҵ�����
	-2 - �����ڲ�����
	-3 - �û��������
	\ -3001 - �û������������Ϊ�գ�
	-10 - ������δ����
*/


/* Command ID:
	-2147483648 - 1899999999 => ϵͳ
	1900000000 - 1999999999 => �û�
	2000000000 - 2147483647 => ����
*/

int StringToCommandID() {
	if (inputCommand.content.empty()) {
		return -3000;
	} else if (inputCommand.content == "ls" || inputCommand.content == "\nls" || inputCommand.content == "dir" || inputCommand.content == "\ndir") {
		return 1;
	} else if (inputCommand.content.find("endl>") != string::npos || inputCommand.content.find("\nendl>") != string::npos) {
		return 2;
	} else if(inputCommand.content == "command" || inputCommand.content == "\ncommand") {
		return 3;
	} else if (inputCommand.content == "exit" || inputCommand.content == "\nexit") {
		return 4;
	} else if (inputCommand.content == "help" || inputCommand.content == "\nhelp") {
		return 5;
	} else if (inputCommand.content.find("cd>") != string::npos || inputCommand.content.find("\ncd>") != string::npos) {
		return 6;
	} else if (inputCommand.content.find("mkfile>") != string::npos || inputCommand.content.find("\nmkfile>") != string::npos) {
		return 7;
	} else if (inputCommand.content.find("mkdir>") != string::npos || inputCommand.content.find("\nmkdir>") != string::npos) {
		return 8;
	} else if (inputCommand.content.find("del>") != string::npos || inputCommand.content.find("\ndel>") != string::npos) {
		return 9;
	} else if (inputCommand.content.find("cp>") != string::npos || inputCommand.content.find("\ncp>") != string::npos) {
		return 10;
	} else if (inputCommand.content.find("rena>") != string::npos || inputCommand.content.find("\nrena>") != string::npos) {
		return 11;
	} else if (inputCommand.content == "date" || inputCommand.content == "\ndate") {
		return 12;
	} else if (inputCommand.content == "cls" || inputCommand.content == "\ncls") {
		return 13;
	} else if (inputCommand.content == "__install" || inputCommand.content == "\n__install") {
		return 99;
	} else if (inputCommand.content == "restart" || inputCommand.content == "\nrestart") {
		return 100;
	} else if (inputCommand.content.find("show>") != string::npos || inputCommand.content.find("\nshow>") != string::npos) {
		return 1900000000;
	} else {
		return -1;
	}
}

/* Command ID eXtended:
	-2147483648 - 1899999999 => ϵͳ
	1900000000 - 1999999999 => �û�
	2000000000 - 2147483647 => ����
*/

long StringToCommandIDX() {
	return -10;
}

/* Extended Command ID eXtended:
	-9223372036854775808 - 999999999999999999 => ϵͳ
	1000000000000000000 - 8999999999999999999 => �û�
	9000000000000000000 - 9223372036854775807 => ����
*/

long long StringToECommandIDX() {
	return -10;
}

struct Command
{
	int CommandID;
	long CommandIDX;
	long long ECommandIDX;
};