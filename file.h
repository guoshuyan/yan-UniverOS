#pragma once

#include <string>
#include <io.h>

bool FindAllFilesOnCurFolder(string path)
{
	_finddata_t file_info;
	int folder_num = 0;
	int file_num = 0;
	//可以定义后面的后缀为*.exe，*.txt等来查找特定后缀的文件，*.*是通配符，匹配所有类型,路径连接符最好是左斜杠/，可跨平台
	string current_path = path + "/*.*";
	_int64 handle = _findfirst(current_path.c_str(), &file_info);
	//返回值为-1则查找失败  
	if (-1 == handle)
		return false;
	try
	{
		do
		{
			string attribute;
			if (file_info.attrib == _A_SUBDIR) { //是目录  
				attribute = "dir";
				folder_num++;
			}
			else {
				attribute = "file";
				file_num++;
			}
			//获得的最后修改时间是time_t格式的长整型
			cout << file_info.name << "\t" << file_info.time_write << "\t" << file_info.size << "\t" << attribute << endl;

		} while (!_findnext(handle, &file_info));
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	cout << endl << path << " \t\t " << folder_num << " 个文件夹 " << endl << "\t\t" << file_num << " 个文件" << endl << endl;
	//关闭文件句柄  
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