// UniverOS.cpp: 定义应用程序的入口点。
//


#include "UniverOS.h"

using namespace std;

int isNum(const char* st)
{
	int num = atoi(st);
	if (num != 0) {
		return 0;
	} else { 
		return -1;
	}
}//st不可能是0时

int main(int argc, char* argv[])
{
	KillConsoleCloseButton();
	SetTitle("UniverOS - By Guoshuyan");
	NeedCheck ? check() : __VOID();
	NeedLogin ? login(0) : __VOID();
	cout << "Welcome!" << endl;
	cout << "UniverOS 1.2.0 rc [Beta]" << endl << endl;
	while (1) {
		cout << "(UniverOS) " << fileInfo.filePath << " > ";
		cin >> inputCommand.content;
		if (enableCommand) {
			inputCommand.content = trimAllSpace(inputCommand.content);
			command.CommandID = StringToCommandID();
			string msg = IDtoMSG(command.CommandID);
			if (command.CommandID < 0) {
				cout << msg << endl;
			}
			else if (command.CommandID == 1) {
				cout << "名称\t写入时间\t大小\t类型" << endl;
				FindAllFilesOnCurFolder(fileInfo.filePath);
			}
			else if (command.CommandID == 2) {
				string endline = "";
				for (int i = 0; i < atoi(splitstr(inputCommand.content, ">").back().c_str()); i++) {
					endline += '\n';
				}
				cout << endline;
			}
			else if (command.CommandID == 3) {
				system("%ComSpec%");
			}
			else if (command.CommandID == 4) {
				exit(0);
			}
			else if (command.CommandID == 5) {
				string temp;
				system("cls");
				cout << endl << "欢迎来到 " << GREEN "UniverOS " NONE << "!" << endl;
				cout << "下面，我将带你了解基本命令：" << endl;
				cout << "┏━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "┃ ID             ┃ Name               ┃" << endl;
				cout << "┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━┫" << endl;
				cout << "┃ 1              ┃ ls | dir           ┃" << endl;
				cout << "┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━┫" << endl;
				cout << "┃ 2              ┃ endline>[xxx]      ┃" << endl;
				cout << "┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━┫" << endl;
				cout << "┃ 3              ┃ command            ┃" << endl;
				cout << "┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━┫" << endl;
				cout << "┃ 4              ┃ exit               ┃" << endl;
				cout << "┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━┫" << endl;
				cout << "┃ 5              ┃ help               ┃" << endl;
				cout << "┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━┫" << endl;
				cout << "┃ 6              ┃ cd>[xxx]           ┃" << endl;
				cout << "┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━┫" << endl;
				cout << "┃ 7              ┃ mkfile>[xxx]>[yyy] ┃" << endl;
				cout << "┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━┫" << endl;
				cout << "┃ 8              ┃ mkdir>[xxx]        ┃" << endl;
				cout << "┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━┫" << endl;
				cout << "┃ 9              ┃ del>[xxx]          ┃" << endl;
				cout << "┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━┫" << endl;
				cout << "┃ 99             ┃ __install          ┃" << endl;
				cout << "┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━┫" << endl;
				cout << "┃ 100            ┃ restart            ┃" << endl;
				cout << "┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━┫" << endl;
				cout << "┃ 1900000000     ┃ show>[xxx]         ┃" << endl;
				cout << "┗━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━┛" << endl;
				getch();
				cout << endl << "看到 " << RED "ID" NONE << " 那一栏了吗？那是在代码中的 " << YELLOW "表示方式" NONE << endl;
				cout  << "再看 " << RED "Name" NONE << " 那一栏，那是用户连接到应用的 " << YELLOW "桥梁" NONE << endl << endl;
				while (1) {
					cout << "如果你想知道具体命令怎么写，请输入那个命令的 ID（输入 exit 退出）：";
					cin >> temp;
					if (isNum(temp.c_str()) == 0) {
						if (atoi(temp.c_str()) == 0) {
							cout << "Error : atoi(temp.c_str) == 0; Please restart this program. -- Guoshuyan" << endl;
							continue;
						}
						else if (atoi(temp.c_str()) == 1) {
							cout << DARY_GRAY "ls | dir " NONE << " : 显示当前目录下的文件（夹）。" << endl;
						}
						else if (atoi(temp.c_str()) == 2) {
							cout << DARY_GRAY "endline>[xxx] " NONE << " : 换 xxx 行。" << endl << "示例：endline>10 为换 10 行" << endl;
						}
						else if (atoi(temp.c_str()) == 3) {
							cout << DARY_GRAY "command" NONE << " : 打开命令行窗口（%ComSpec%）。" << endl;
						}
						else if (atoi(temp.c_str()) == 4) {
							cout << DARY_GRAY "exit " NONE << " : 退出程序。" << endl;
						}
						else if (atoi(temp.c_str()) == 5) {
							cout << DARY_GRAY "help " NONE << " : 显示帮助（当前信息）。" << endl;
						}
						else if (atoi(temp.c_str()) == 6) {
							cout << DARY_GRAY "cd>[xxx] " NONE << " : 打开 xxx 路径。" << endl << "示例：cd>C:\\ 为进入 C:\\ 路径" << endl;
						}
						else if (atoi(temp.c_str()) == 7) {
							cout << DARY_GRAY "mkfile>[xxx]>[yyy] " NONE << " : 创建 xxx 文件并写入 yyy。" << endl << "示例：mkfile>C:\\0.0>0 为创建 C:\\0.0 文件写入 0" << endl;
						}
						else if (atoi(temp.c_str()) == 8) {
							cout << DARY_GRAY "mkdir>[xxx] " NONE << " : 创建 xxx 文件夹。" << endl << "示例：mkdir>C:\\0.0 为创建 C:\\0.0 文件夹" << endl;
						}
						else if (atoi(temp.c_str()) == 9) {
							cout << DARY_GRAY "del>[xxx] " NONE << " : 删除 xxx 文件（夹）。" << endl << "示例：del>C:\\0.0 为删除 C:\\0.0 文件（夹）" << endl;
						}
						else if (atoi(temp.c_str()) == 99) {
							cout << DARY_GRAY "__install " NONE << " : 安装程序测试工具（试运行）。" << endl;
						}
						else if (atoi(temp.c_str()) == 100) {
							cout << DARY_GRAY "restart " NONE << " : 重启应用。" << endl;
						}
						else if (atoi(temp.c_str()) == 1900000000) {
							cout << DARY_GRAY "show>[xxx] " NONE << " : 显示 xxx 信息。" << endl << "示例：show>abc 为打印 abc" << endl;
						}
						else {
							cout << "ID 输错了！请检查一遍。" << endl;
						}
					} else if (temp == "exit") {
						break;
					} else {
						cout << "请输入数字哦。" << endl;
					}

				}
			}
			else if (command.CommandID == 6) {
				StringList path = splitstr(inputCommand.content, ">");
				StringList *splitPath = new StringList[path.size()];
				for (int i = 0; i < path.size(); i++) {
					splitPath[i] = splitstr(path.back(), "\\");
				}
				
				if (path.size() == 2) {
					struct  _stat fileStat;
					if (path.back() == "." || path.empty() == true) {
						cout << endl << fileInfo.filePath << " ==> " << fileInfo.filePath << endl << endl;
						__VOID();
					} else if (path.back() == "..") {
							try {
								cout << endl << fileInfo.filePath << " ==> ";
								StringList backStr = splitstr(fileInfo.filePath, "\\");
								fileInfo.filePath = "";
								for (int i = 0; i < backStr.size() - 1; i++) {
									fileInfo.filePath += backStr[i];
									fileInfo.filePath += '\\';
								}
								fileInfo.filePath.pop_back();
							}catch (exception e) {

								// TODO : 这里不知道为什么，报错而不输出

								cout << "对不起，这已经是顶级目录了。" << endl;
							}
							cout << fileInfo.filePath << endl << endl;
					} else if ((_stat(path.back().c_str(), &fileStat) == 0) && (fileStat.st_mode & _S_IFDIR)) {
						if (path.back().find(fileInfo.filePath) != string::npos){
							cout << endl << fileInfo.filePath << " ==> " << path.back() << endl << endl;
							fileInfo.filePath = path.back();
						} else {
							cout << endl << fileInfo.filePath << " ==> " << fileInfo.filePath + '\\' + path.back() << endl << endl;
							fileInfo.filePath = fileInfo.filePath + '\\' + path.back();
						}
						__VOID();
					} else {
						if ((_stat((fileInfo.filePath + path.back()).c_str(), &fileStat) == 0) && (fileStat.st_mode & _S_IFDIR))
						{
							cout << endl << fileInfo.filePath << " ==> " << (fileInfo.filePath + path.back()) << endl << endl;
							fileInfo.filePath = (fileInfo.filePath + path.back()).c_str();
							__VOID();
						}
						else {
							if ((_stat((fileInfo.filePath + "\\" + path.back()).c_str(), &fileStat) == 0) && (fileStat.st_mode & _S_IFDIR))
							{
								cout << endl << fileInfo.filePath << " ==> " << (fileInfo.filePath + path.back()) << endl << endl;
								fileInfo.filePath = (fileInfo.filePath + "\\" + path.back()).c_str();
								__VOID();
							}
							else {
								cout << "您输入的 " << path.back() << " 目录不存在" << endl;
								__VOID();
							}
						}
					}
				}
				else {
					cout << "请不要输入过多或过少 连接符 （ > ）" << endl;
				}
			}
			else if (command.CommandID == 7) {
				try {
					fileInfo.fileName = splitstr(inputCommand.content, ">")[1];
					fileInfo.fileContent = splitstr(inputCommand.content, ">")[2];
					if (fileInfo.filePath.at(fileInfo.filePath.size() - 1) == '\\') {
						ofstream fout(fileInfo.filePath + fileInfo.fileName);
						fopen((fileInfo.filePath + fileInfo.fileName).c_str(), "w+");
						fout << fileInfo.fileContent << endl;
						fout.close();
					}
					else {
						ofstream fout(fileInfo.filePath + '\\' + fileInfo.fileName);
						fopen((fileInfo.filePath + '\\' + fileInfo.fileName).c_str(), "w+");
						fout << fileInfo.fileContent << endl;
						fout.close();
					}
				}
				catch (exception e) {
					cout << "Error : No FileName Or FileContent; Please re-input this command. --Guoshuyan" << endl;
				}
			}
			else if (command.CommandID == 8) {
				fileInfo.fileName = splitstr(inputCommand.content, ">")[1];
				if (0 != access(fileInfo.fileName.c_str(), 0))
				{
					// if this folder not exist, create a new one.
					if (mkdir(fileInfo.fileName.c_str()) == 0) {
						cout << "已成功创建 " << fileInfo.fileName.c_str() << " 文件夹！" << endl;
					}
					else {
						cout << "创建失败。" << endl;
					}
				}
			}
			else if (command.CommandID == 9) {
				fileInfo.fileName = splitstr(inputCommand.content, ">").back();
				if (fileInfo.filePath.back() == '\\') {
					char c;
					cout << "您确定要删除 " << fileInfo.filePath + fileInfo.fileName << " 吗？[y/N]:";
					c = getch();
					if (c == 'y' || c == 'Y') {
						string deleteCommand_file = ("del / F / S / Q " + fileInfo.filePath + fileInfo.fileName);
						string deleteCommand_dir = ("rd / S / Q " + fileInfo.filePath + fileInfo.fileName);
						cout << endl << "File_Delete : ";
						system(deleteCommand_file.c_str());
						cout << "Dir_Delete  : ";
						system(deleteCommand_dir.c_str());
					}
				}
				else {
					char c;
					cout << "您确定要删除 " << fileInfo.filePath + '\\' + fileInfo.fileName << " 吗？[y/N]:";
					c = getch();
					if (c == 'y' || c == 'Y') {
						string deleteCommand_file = ("del / F / S / Q " + fileInfo.filePath + '\\' + fileInfo.fileName);
						string deleteCommand_dir = ("rd / S / Q " + fileInfo.filePath + '\\' + fileInfo.fileName);
						cout << endl << "File_Delete : ";
						system(deleteCommand_file.c_str());
						cout << "Dir_Delete  : ";
						system(deleteCommand_dir.c_str());
					}
				}
			}
			else if (command.CommandID == 99) {
				char c;
				cout << "此为 试运行 程序，您要继续吗？[y/N]:";
				c = getch();
				if (c == 'y' || c == 'Y') {
					install();
				}
				cout << endl;
			}
			else if (command.CommandID == 100) {
				system("cls");
				WinExec(_pgmptr, SW_SHOW);
				exit(0);
			}
			else if (command.CommandID == 1900000000) {
				StringList content = splitstr(inputCommand.content, ">");
				if (content.size() == 2) {
					cout << content.back() << endl;
				}
				else {
					for (int i = 0; i < content.size(); i++) {
						if (i == 0) {
							cout << splitstr(inputCommand.content, ">")[i];
						} else {
							cout << " " << splitstr(inputCommand.content, ">")[i];
						}
					}
					cout << endl;
				}
			}
			else {
				cout << "未知命令值" << endl;
			}
		} else {
			cout << "管理员已关闭命令功能。" << endl;
		}
	}
	return 0;
}