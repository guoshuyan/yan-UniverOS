#pragma once

#include <string>
#include <io.h>

bool FindAllFilesOnCurFolder(string path)
{
	_finddata_t file_info;
	int folder_num = 0;
	int file_num = 0;
	//���Զ������ĺ�׺Ϊ*.exe��*.txt���������ض���׺���ļ���*.*��ͨ�����ƥ����������,·�����ӷ��������б��/���ɿ�ƽ̨
	string current_path = path + "/*.*";
	_int64 handle = _findfirst(current_path.c_str(), &file_info);
	//����ֵΪ-1�����ʧ��  
	if (-1 == handle)
		return false;
	try
	{
		do
		{
			string attribute;
			if (file_info.attrib == _A_SUBDIR) { //��Ŀ¼  
				attribute = "dir";
				folder_num++;
			}
			else {
				attribute = "file";
				file_num++;
			}
			//��õ�����޸�ʱ����time_t��ʽ�ĳ�����
			cout << file_info.name << "\t" << file_info.time_write << "\t" << file_info.size << "\t" << attribute << endl;

		} while (!_findnext(handle, &file_info));
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	cout << endl << path << " \t\t " << folder_num << " ���ļ��� " << endl << "\t\t" << file_num << " ���ļ�" << endl << endl;
	//�ر��ļ����  
	_findclose(handle);
	return true;
}

BOOL isFolderExist(const char* folder) {
	int ret = 0;
	ret = _access(folder, 0x0);
	if (ret == 0) {
		ret = TRUE;
	} else {
		ret = FALSE;
	}
	return ret;
}

struct FileInfo
{
	string fileName;
	string fileNewLocation;
	string fileNewName;
	string filePath;
	string fileContent;
};