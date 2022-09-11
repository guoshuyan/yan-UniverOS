#pragma once

struct Time
{
	short hour;
	short min;
	short sec;
};

struct Date
{
	int year;
	short month;
	short day;
	Time time;
};


struct AccountInfo {
	int ID;
	int Age;
	bool Sex; // true Ϊ�� false ΪŮ
	bool IsAdmin;
	bool Status;
	bool IsDead;
	bool IsRobot;
	bool IsTest;
	string UserCountry;
	string UserPhone;
	string UserEmail;
	string UserRealName;
	string UserName;
	string UserPassword;
	Date CreateDate;
	Date Birthday;
};