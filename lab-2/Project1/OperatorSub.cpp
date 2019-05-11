// ShowDec.cpp
#include <iostream>
#include "SymbString.h"
#include "OperatorSub.h"
using namespace std;

void OperatorSub::Operate(AString* pObj) {
	string Value1 = pObj->GetVal(); // считываем изображение объекта вычитания
	string Value2 = pObj->SubObjValue; // считываем изображение сохраненного значения вычитаемого объекта
	cout << Value1 << " - " << Value2 << " = "; // выыодим изображение действия

	if ((dynamic_cast<SymbString*>(pObj))) { // если тип объектов SymbString
		size_t pos; // переменная для хранения позиции первого вхождения str2 в str1
		while ((pos = Value1.find(Value2)) != string::npos) { // пока str2 присутствует в str1
			string before = Value1.substr(0, pos); // "вырезаем" первый блок
			string after = Value1.substr(pos + Value2.length()); // "вырезаем" второй блок
			Value1 = before + after; // таким образом вырезали блоки до и после вхождения str2 в str1
		}
		cout << Value1 << "\n"; // выводим результат вычитания
	}
	else { // если тип объектов HexString
		long dest1, dest2;
		sscanf(Value1.c_str(), "%x", &dest1); // переводим изображение первого объекта в числовой тип (long dest1)
		sscanf(Value2.c_str(), "%x", &dest2); // переводим изображение второго объекта в числовой тип (long dest2)
		cout << hex << dest1 - dest2 << hex << "\n"; // выводим результат вычитания в шеснадцатиричной системе счисления
	}
}

OperatorSub operator_sub;