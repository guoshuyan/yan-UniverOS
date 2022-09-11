#pragma once

/*
	ID:
	0 - 成功
	-1 - 未找到命令
	-2 - 函数内部错误
	-3 - 用户输入错误
	\ -3001 - 用户输入错误（输入为空）
	-10 - 函数暂未定义
*/


/* Command ID:
	-2147483648 - 1899999999 => 系统
	1900000000 - 1999999999 => 用户
	2000000000 - 2147483647 => 保留
*/

int StringToCommandID() {
	if (inputCommand.content.empty()) {
		return -3001;
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
	-2147483648 - 1899999999 => 系统
	1900000000 - 1999999999 => 用户
	2000000000 - 2147483647 => 保留
*/

long StringToCommandIDX() {
	return -10;
}

/* Extended Command ID eXtended:
	-9223372036854775808 - 999999999999999999 => 系统
	1000000000000000000 - 8999999999999999999 => 用户
	9000000000000000000 - 9223372036854775807 => 保留
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