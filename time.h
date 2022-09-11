#pragma once

time_t nowTime;
struct tm* timePointer;


string GetWDay(void) {
	time(&nowTime);
	timePointer = localtime(&nowTime);
	const char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	return wday[timePointer->tm_wday];
}
int GetYear(void) {
	time(&nowTime);
	timePointer = localtime(&nowTime);
	return (timePointer->tm_year) + 1900;
}
int GetMon(void) {
	time(&nowTime);
	timePointer = localtime(&nowTime);
	return (timePointer->tm_mon) + 1;
}
int GetDay(void) {
	time(&nowTime);
	timePointer = localtime(&nowTime);
	return timePointer->tm_mday;
}
int GetHour( void ){
	time(&nowTime);
	timePointer = localtime(&nowTime);
	return timePointer->tm_hour;
}
int GetMin(void) {
	time(&nowTime);
	timePointer = localtime(&nowTime);
	return timePointer->tm_min;
}
int GetSec(void) {
	time(&nowTime);
	timePointer = localtime(&nowTime);
	return timePointer->tm_sec;
}