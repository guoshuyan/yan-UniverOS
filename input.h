#pragma once
#include <vector>
#include <string>
using namespace std;

typedef vector<std::string> StringList;


StringList splitstr(const std::string& str, const std::string& pattern)
{
    StringList  li;
    std::string subStr;
    std::string tPattern;
    size_t      patternLen = pattern.length();

    //遍历字符串，将i位置的字符放入子串中，当遇到pattern子串时完成一次切割
    //遍历之后得到切割后的子串列表
    for (size_t i = 0; i < str.length(); i++)
    {
        if (pattern[0] == str[i])//遇到需要检测pattern的情况
        {
            tPattern = str.substr(i, patternLen);
            if (tPattern == pattern)//找到一个匹配的pattern，完成切割
            {
                i += patternLen - 1;
                if (!subStr.empty())
                {
                    li.push_back(subStr);
                    subStr.clear();
                }
            }
            else//不是匹配的pattern，将i位置的字符放入子串
            {
                subStr.push_back(str[i]);
            }
        }
        else//未遇到pattern，将i位置的字符放入子串
        {
            subStr.push_back(str[i]);
        }
    }
    if (!subStr.empty())//将子串中的剩余字符放入子字符串队列
    {
        li.push_back(subStr);
    }
    return li;
}

struct InputDevice
{
	int deviceID;
	int IDOffset;
};

struct InputProgram
{
	string Path;
};

struct InputCommand {
	InputDevice inputDevice;
	InputProgram inputProgram;
	string content;
};