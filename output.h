#pragma once

string IDtoMSG(int id) {
	switch (id)
	{
	case -1:
		return "δ�ҵ�����";
	case -2:
		return "�����ڲ�����";
	case -3:
		return "�û��������";
	case -3000:
		return "";
	case -10:
		return "������δ����";
	default:
		return "δ֪����";
	}
}