/*
Описать класс «студенческая группа». 
Предусмотреть возможность работы с переменным числом студентов, поиска студента по какому-либо признаку 
(например, по фамилии, дате рождения или номеру телефона), добавления и удаления записей, сортировки по разным полям. 
Написать программу, демонстрирующую работу с этим классом. 
Программа должна содержать меню, позволяющее осуществить проверку всех методов класса. 
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct student {
	string name;
	string surname;
	string date;
	int kurs;
};

class group_students
{
private:
	string group;
	student students;
	group_students* next;
public:
	group_students() {}
	~group_students() {}

	bool isEmpty(group_students* head)
	{
		if (head == NULL)
			return true;
		else
			return false;
	}

	void insertAsFirstElement(group_students * &head, group_students * &last, string surname, string name, string date, int kurs, string title) // Äîáàâëåíèå ïåðâîãî ñòóäåíòà
	{
		group = title;
		group_students* temp = new group_students;
		temp->students.name = name;
		temp->students.surname = surname;
		temp->students.date = date;
		temp->students.kurs = kurs;
		temp->next = NULL;
		head = temp;
		last = temp;
	}

	void insert(group_students * &head, group_students * &last, string surname, string name, string date, int kurs, string title) // Äîáàâëåíèå ñòóäåíòîâ
	{
		if (isEmpty(head))
			insertAsFirstElement(head, last, surname, name, date, kurs, title);
		else
		{
			group_students* temp = new group_students;
			temp->students.name = name;
			temp->students.surname = surname;
			temp->students.date = date;
			temp->students.kurs = kurs;
			temp->next = NULL;
			last->next = temp;
			last = temp;
		}
	}

	void showList(group_students * current) // Âûâîä
	{
		if (isEmpty(current))
			cout << "The list is empty.\n";
		else
		{
			cout << setw(31) << " Group: " << "\"" << group << "\"" << endl;
			cout << "\n";
			cout << left << setw(18) << "   Surname";
			cout << left << setw(10) << "Forename";
			cout << right << setw(18) << "Date of Birth";
			cout << right << setw(18) << "Kurs";
			cout << "\n\n";
			int i = 0;
			while (current != NULL)
			{
				i++;
				cout << i << ". " << left << setw(15) << current->students.surname << left << setw(15) << current->students.name << right << setw(13) << current->students.date << right << setw(18) << current->students.kurs << endl;
				current = current->next;
			}
			cout << "\n";
		}
	}

	void remove(group_students * &head, group_students * &last, int del, int& count) // Ôóíêöèÿ óäàëåíèÿ
	{
		if ((head != NULL) && (del > 0) && (del <= count))
		{
			del = del - 1;
			group_students* temp = head, * helping = head;
			for (int i = 0; i < del; i++)
			{
				helping = temp;
				temp = temp->next;
			}

			if (temp == head)
			{
				head = temp->next;
			}
			else
			{
				helping->next = temp->next;
			}
			delete temp;
			count--;
		}
	}

	void sortList(group_students * head) // Ñîðòèðîâêà
	{
		group_students* temp2;
		group_students* temp3;
		string tmp, tmp1, tmp2;
		int tmp3;

		for (temp2 = head; temp2 != NULL; temp2 = temp2->next)
		{
			for (temp3 = temp2->next; temp3 != NULL; temp3 = temp3->next)
			{
				if (temp2->students.surname > temp3->students.surname)
				{
					tmp = temp2->students.surname;
					tmp1 = temp2->students.name;
					tmp2 = temp2->students.date;
					tmp3 = temp2->students.kurs;
					temp2->students.surname = temp3->students.surname;
					temp2->students.name = temp3->students.name;
					temp2->students.date = temp3->students.date;
					temp2->students.kurs = temp3->students.kurs;
					temp3->students.surname = tmp;
					temp3->students.name = tmp1;
					temp3->students.date = tmp2;
					temp3->students.kurs = tmp3;
				}
			}
		}
	}

	void searchList(group_students * head, string findValue) // Ïîèñê
	{
		cout << setw(35) << " Results for " << "\"" << findValue << "\"" << endl;
		cout << "\n";
		cout << left << setw(18) << "   Surname";
		cout << left << setw(10) << "Forename";
		cout << right << setw(18) << "Date of Birth";
		cout << right << setw(18) << "Kurs";
		cout << "\n\n";
		int i = 0;
		while (head != NULL)
		{
			if ((head->students.surname == findValue) || (head->students.name == findValue) || (head->students.date == findValue))
			{
				i++;
				cout << i << ". " << left << setw(15) << head->students.surname << left << setw(15) << head->students.name << right << setw(13) << head->students.date << right << setw(18) << head->students.kurs << endl;
			}
			head = head->next;
		}
		cout << "\n";
		if (i == 0)
			cout << "\"" << findValue << "\"" << " not fonud! \n\n";
	}

	char menu() // Ìåíþ
	{
		char choice;
		cout << "Menu\n";
		cout << "1. Add student\n";
		cout << "2. Remove student\n";
		cout << "3. Dispaly group\n";
		cout << "4. Sort students\n";
		cout << "5. Search students in a group\n";
		cout << "6. Exit\n";

		cin >> choice;
		return choice;
	}
};

int main()
{
	group_students group;
	group_students* head = NULL;
	group_students* last = NULL;
	char choice;
	string title, surname, name, date, poisk;
	int kurs;
	int count = 0, del;
	while (1)
	{
		choice = group.menu();
		switch (choice)
		{
		case'1':
			if (count == 0)
			{
				cout << "\n\n";
				cout << "Enter group title: ";
				cin >> title;
			}
			count++;
			cout << "\n\n";
			cout << "Surname: ";
			cin >> surname;
			cout << "Firstname: ";
			cin >> name;
			cout << "Date of Birth: ";
			cin >> date;
			cout << "Kurs: ";
			while (!(cin >> kurs))
			{
				cin >> kurs;
				if (!cin)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Try again" << endl;
				}
			}
			cout << "\n";
			group.insert(head, last, surname, name, date, kurs, title);
			break;

		case'2':
			cout << "\n\n";
			cout << "Enter the number to delete: ";
			cin >> del;
			cout << "\n\n";
			group.remove(head, last, del, count);
			break;

		case'3':
			cout << "\n\n";
			group.showList(head);
			break;

		case'4':
			cout << "\n\n";
			group.sortList(head);
			break;

		case'5':
			cout << "\n\n";
			cout << "Search Name: ";
			cin >> poisk;
			cout << "\n";
			group.searchList(head, poisk);
			break;

		case'6':
			exit(0);
			break;
		}
	}
	return 0;
}
