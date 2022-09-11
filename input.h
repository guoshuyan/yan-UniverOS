#pragma once
#include <vector>
#include <string>
using namespace std;

typedef vector<std::string> StringList;

string trimAllSpace(string str)
{
    string::iterator pos = str.begin();
    while (1)
    {
        pos = find(pos, str.end(), ' ');
        if (pos == str.end()) break;
        str.erase(pos);
    }
    return str;
}

StringList splitstr(const std::string& str, const std::string& pattern)
{
    StringList  li;
    std::string subStr;
    std::string tPattern;
    size_t      patternLen = pattern.length();

    //�����ַ�������iλ�õ��ַ������Ӵ��У�������pattern�Ӵ�ʱ���һ���и�
    //����֮��õ��и����Ӵ��б�
    for (size_t i = 0; i < str.length(); i++)
    {
        if (pattern[0] == str[i])//������Ҫ���pattern�����
        {
            tPattern = str.substr(i, patternLen);
            if (tPattern == pattern)//�ҵ�һ��ƥ���pattern������и�
            {
                i += patternLen - 1;
                if (!subStr.empty())
                {
                    li.push_back(subStr);
                    subStr.clear();
                }
            }
            else//����ƥ���pattern����iλ�õ��ַ������Ӵ�
            {
                subStr.push_back(str[i]);
            }
        }
        else//δ����pattern����iλ�õ��ַ������Ӵ�
        {
            subStr.push_back(str[i]);
        }
    }
    if (!subStr.empty())//���Ӵ��е�ʣ���ַ��������ַ�������
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