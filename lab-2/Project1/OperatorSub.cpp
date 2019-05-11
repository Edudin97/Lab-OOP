// ShowDec.cpp
#include <iostream>
#include "SymbString.h"
#include "OperatorSub.h"
using namespace std;

void OperatorSub::Operate(AString* pObj) {
	string Value1 = pObj->GetVal(); // ��������� ����������� ������� ���������
	string Value2 = pObj->SubObjValue; // ��������� ����������� ������������ �������� ����������� �������
	cout << Value1 << " - " << Value2 << " = "; // ������� ����������� ��������

	if ((dynamic_cast<SymbString*>(pObj))) { // ���� ��� �������� SymbString
		size_t pos; // ���������� ��� �������� ������� ������� ��������� str2 � str1
		while ((pos = Value1.find(Value2)) != string::npos) { // ���� str2 ������������ � str1
			string before = Value1.substr(0, pos); // "��������" ������ ����
			string after = Value1.substr(pos + Value2.length()); // "��������" ������ ����
			Value1 = before + after; // ����� ������� �������� ����� �� � ����� ��������� str2 � str1
		}
		cout << Value1 << "\n"; // ������� ��������� ���������
	}
	else { // ���� ��� �������� HexString
		long dest1, dest2;
		sscanf(Value1.c_str(), "%x", &dest1); // ��������� ����������� ������� ������� � �������� ��� (long dest1)
		sscanf(Value2.c_str(), "%x", &dest2); // ��������� ����������� ������� ������� � �������� ��� (long dest2)
		cout << hex << dest1 - dest2 << hex << "\n"; // ������� ��������� ��������� � ���������������� ������� ���������
	}
}

OperatorSub operator_sub;