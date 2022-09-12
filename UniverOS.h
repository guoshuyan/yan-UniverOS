// UniverOS.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

// TODO: "xxx" 不明确削除 - S
#define _HAS_STD_BYTE 0
// TODO: "xxx" 不明确削除 - E

// TODO: Application Info - S
#define _APP_NAME "UniverOS"
#define _APP_VERSION "1.2.2"
#define _APP_VEREXTS "Release"
#define _APP_VEREXTSINFO "[Release]"
#define _APP_START_MESSAGE "Welcome!"
#define _APP_TITLE "UniverOS - By Guoshuyan"
// TODO: Application Info - E

#include <iostream>
#include "global.h"

// TODO: I 相关 - S
#include <algorithm>
#include "input.h"
#include "md5.h"
#include "account.h"
#include "colortext.h"
// TODO: I 相关 - E
struct Time DefaultTime = {
	0,
	0,
	0
};
struct Date DefaultDate = {
	1970,
	1,
	1,
	DefaultTime
};
struct AccountInfo shuyan = {
	10000,
	11,
	true,
	true,
	true,
	false,
	false,
	false,
	"China",
	"15937380181",
	"yanyan11223344@163.com",
	"Guo Shuyan",
	"shuyan",
	"685AFD2C69E12FAD72F0378FEB53BABC",
	DefaultDate,
	DefaultDate
};
struct InputDevice inputDevice = {
	0x0,
	0x0
};
struct InputProgram inputProgram = {
	""
};
struct InputCommand inputCommand = {
	inputDevice,
	inputProgram,
	""
};

// TODO: Kernel 相关 - S
#include <Windows.h>
#include <conio.h>
#include <direct.h>
#include <sstream>
#include "login.h"
#include "startcheck.h"
#include "mainCommand.h"
// TODO: Kernel 相关 - E
struct Command command {
	0x0,
	0x0,
	0x0
};

// TODO: O 相关 - S
#include "file.h"
#include "output.h"
#include <fstream>
// TODO: O 相关 - E
struct FileInfo fileInfo = {
	"",
	"",
	"",
	getcwd(NULL, 0),
	""
};

// TODO: 其他 - S
#include <ctime>
#include <cstdio>
#include "installer.h"
#include "time.h"
// TODO: 其他 - E
// TODO: 在此处引用程序需要的其他标头。
