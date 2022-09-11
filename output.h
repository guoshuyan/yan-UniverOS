#pragma once

string IDtoMSG(int id) {
	switch (id)
	{
	case -1:
		return "未找到命令";
	case -2:
		return "函数内部错误";
	case -3:
		return "用户输入错误";
	case -3001:
		return "用户输入错误（输入为空）";
	case -10:
		return "函数暂未定义";
	default:
		return "未知错误";
	}
}