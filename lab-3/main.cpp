#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

template <class T> class stack
{
public:
	stack() { cout << "Debug - stack created. Type of stack - " << typeid(T).name() << endl; };
	~stack() { ourstack.clear(); cout << "Debug - stack of " << typeid(T).name() << " destroyed" << endl; };
	void push(T value) { ourstack.push_back(value); cout << "Debug - stack pushed with [ " << value << " ];" << endl; }; // Äîáàâëÿåò â êîíåö íîâûé ýëåìåíò
	void pop() { if (!empty()) { cout << "Debug - stack popped, deleted element [ " << ourstack.back() << " ];" << endl; ourstack.pop_back(); } }; // Óäàëÿåò ïîñëåäíèé ýëåìåíò
	T   top() const { return ourstack.back(); }; // Âîçâðàùàåò ïîñëåäíèé ýëåìåíò
	void print() const { cout << ourstack.back(); }; // Ïå÷àòàåò ïîñëåäíèé ýëåìåíò. Ïûòàåòñÿ íàïå÷àòàòü ÷åðåç iostream/cout
	void clear() { ourstack.clear(); }; // Ñòèðàåò âåñü ñòåê
	bool empty() { return ourstack.empty(); };
	int size() const { return ourstack.size(); }; // Ðàçìåð ñòåêà
private:
	vector <T> ourstack;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Äóäèí Ýäóàðä. ÁÈÝ18-01, âàðèàíò 6;" << endl << endl;
	cout << "Âî âñåõ âàðèàíòàõ òðåáóåòñÿ ñîçäàòü øàáëîí íåêîòîðîãî öåëåâîãî êëàññà À," << endl
		<< "âîçìîæíî, ðåàëèçîâàííûé ñ ïðèìåíåíèåì íåêîòîðîãî ñåðâåðíîãî êëàññà Â. " << endl
		<< "Ýòî îçíà÷àåò, ÷òî îáúåêò êëàññà Â èñïîëüçóåòñÿ êàê ýëåìåíò êëàññà À. " << endl
		<< "Â êà÷åñòâå ñåðâåðíîãî êëàññà ìîæåò áûòü óêàçàí ëèáî êëàññ, ñîçäàííûé" << endl
		<< "ïðîãðàììèñòîì, ëèáî êëàññ èç ñòàíäàðòíîé áèáëèîòåêè — íàïðèìåð, std::vector. " << endl
		<< "Âàðèàíòû öåëåâûõ èëè ñåðâåðíûõ êëàññîâ, ñîçäàâàåìûõ ïðîãðàììèñòîì, ïðèâåäåíû " << endl
		<< "â òàáë. 3.1. Èíôîðìàöèþ î ðàáîòå ñ äèíàìè÷åñêèìè ñòðóêòóðàìè äàííûõ " << endl
		<< "(ëèíåéíûé ñïèñîê, ñòåê, îäíîñòîðîííÿÿ î÷åðåäü, áèíàðíîå äåðåâî) ñì. â ó÷åáíèêå " << endl
		<< "(ñ. 114-127), à òàêæå â ïåðâîé êíèãå ïðàêòèêóìà [2] (ñåìèíàð 9)." << endl;

	system("pause");
	system("cls");

	stack<int> numbers;
	cout << "Size of stack : " << numbers.size() << endl;
	numbers.push(15);
	numbers.push(14);
	numbers.push(13);
	numbers.push(11);
	numbers.push(10);
	cout << "Size of stack : " << numbers.size() << endl;
	cout << "At top of stack : " << numbers.top() << endl;
	numbers.pop();
	numbers.pop();
	numbers.pop();
	numbers.pop();
	if (numbers.empty())
		cout << "Stack is empty" << endl;
	else
	{
		cout << "Size of stack : " << numbers.size() << endl;
		cout << "At top of stack : " << numbers.top() << endl;
	}

	system("pause");
	system("cls");

	stack<double> numbers_2;
	cout << "Size of stack : " << numbers_2.size() << endl;
	numbers_2.push(1.5);
	numbers_2.push(1.4);
	numbers_2.push(1.3);
	numbers_2.push(1.1);
	numbers_2.push(1.0);
	cout << "Size of stack : " << numbers_2.size() << endl;
	cout << "At top of stack : " << numbers_2.top() << endl;
	numbers_2.pop();
	numbers_2.pop();
	numbers_2.pop();
	numbers_2.pop();
	numbers_2.pop();
	numbers_2.pop();
	if (numbers_2.empty())
		cout << "Stack is empty" << endl;
	else
	{
		cout << "Size of stack : " << numbers_2.size() << endl;
		cout << "At top of stack : " << numbers_2.top() << endl;
	}

	system("pause");
	system("cls");

	stack<string> numbers_3;
	cout << "Size of stack : " << numbers_3.size() << endl;
	numbers_3.push("String 5");
	numbers_3.push("String 4");
	numbers_3.push("String 3");
	numbers_3.push("String 2");
	numbers_3.push("String 1");
	cout << "Size of stack : " << numbers_3.size() << endl;
	cout << "At top of stack : " << numbers_3.top() << endl;
	numbers_3.pop();
	numbers_3.pop();
	if (numbers_3.empty())
		cout << "Stack is empty" << endl;
	else
	{
		cout << "Size of stack : " << numbers_3.size() << endl;
		cout << "At top of stack : " << numbers_3.top() << endl;
	}

	system("pause");
	return 0;
}
