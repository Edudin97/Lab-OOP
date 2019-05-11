/*
   Написать программу, демонстрирующую работу с объектами двух типов: Т1 и Т2, для чего создать систему соответствующих классов. 
   Каждый объект должен иметь идентификатор (в виде произвольной строки символов) и одно или несколько полей
   для хранения состояния объекта (один класс является потомком другого).

   Клиенту (функции main) должны быть доступны следующие основные операции (методы):
   создать объект, удалить объект, показать значение объекта и прочие дополнительные операции (зависят от варианта).
   Операции по созданию и удалению объектов инкапсулировать в классе Factory., Предусмотреть меню, позволяющее продемонстрировать заданные операции.

   При необходимости в разрабатываемые классы добавляются дополнительные методы (например, конструктор копирования, операция присваивания и т. п.)
   для обеспечения надлежащего функционирования этих классов.

   Вариант 10.

   T1 - SymbString Символьная строка (произвольная строка символов)
   T2 - HexString - Шестнадцатеричная строка (изображение шестнадцатеричного числа)
   Метод: operator -(T&. T&)

   Для объектов SymbString — если s2 содержится как подстрока в s1, то результатом является строка, полученная из s1 удалением подстроки s2;
   в противном случае возвращается значение s1; для объектов прочих классов — вычитание соответствующих численных значений 
   с последующим преобразованием к типу Т 
*/

// Main.cpp
#include <iostream>
#include <string>
#include "AString.h"
#include "SymbString.h"
#include "HexString.h"
#include "Action.h"
#include "ShowStr.h"
#include "OperatorSub.h"
#include "Factory.h"
#include "Menu.h"

using namespace std;

Action* pActs[] = { &show_str, &operator_sub };
vector<Action*> actionList(pActs,
	pActs + sizeof(pActs) / sizeof(Action*));
AString* pSubObj;

int main() {
	Factory factory;
	Menu menu(actionList);
	JobMode jobMode;
	while ((jobMode = menu.SelectJob()) != Exit) {
		switch (jobMode) {
		case AddObj:
			factory.AddObject();
			break;
		case DelObj:
			factory.DeleteObject();
			break;
		case WorkWithObj:
			AString* pObj = menu.SelectObject(factory, "\nSelect one of the following Object:\n"); // выбор объекта
			Action* pAct = menu.SelectAction(pObj); // выбор действия
			if (pAct == &operator_sub) { // если выбран "Оператор -"
				pSubObj = menu.SelectObject(factory, "Select the subtracted object\n"); // выбор вычитаемого объекта
				if ((dynamic_cast<HexString*>(pObj)) && (dynamic_cast<HexString*>(pSubObj)) // если тип обоих объектов HexString
					|| (dynamic_cast<SymbString*>(pObj)) && (dynamic_cast<SymbString*>(pSubObj))) {// или если тип обоих объектов SymbString
					pObj->SubObjValue = pSubObj->GetVal();
					pAct->Operate(pObj);
				}
				else {
					cout << "Object types are not identical\n"; // если объекты разных типов
				}
			}
			else {
				pAct->Operate(pObj);
			}
			break;
		}
		cin.get();
	}
	cout << "Bye!\n";
	return 0;
}