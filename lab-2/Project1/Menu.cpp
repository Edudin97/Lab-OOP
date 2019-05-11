// Menu.cpp
#include <iostream>
#include "AString.h"
#include "SymbString.h"
#include "HexString.h"
#include "Menu.h"

using namespace std;

Menu::Menu(vector<Action*> _pAct) : pAct(_pAct) {}

JobMode Menu::SelectJob() const {
	cout << "======================================\n";
	cout << "Select one of the following job modes:\n";
	cout << "1. Add object" << endl;
	cout << "2. Delete object" << endl;
	cout << "3. Work with object" << endl;
	cout << "4. Exit" << endl;
	int item = SelectItem(4);
	return (JobMode)(item - 1);
}

AString* Menu::SelectObject(const Factory & fctry, const string Header) const {
	int nItem = fctry.pObj.size();
	if (!nItem) {
		cout << "There are no objects." << endl;
		cin.get();
		return 0;
	}

	int item;
	while (true) {
		cout << Header;
		//		cout << "...................................\nSelect one of the following Object:\n";
		for (int i = 0; i < nItem; ++i) {
			cout << i + 1 << ". ";
			cout << fctry.pObj[i]->GetName() << endl;
		}
		item = SelectItem(nItem);
		if (item > 0 && item <= nItem) { // óñëîâèå êîððåêòíîãî ââîäà íîìåðà îáúåêòà
			break;
		}
		else {
			cin.get();
		}
	}
	return fctry.pObj[item - 1];
}

Action* Menu::SelectAction(const AString * pObj) const {
	if (!pObj) return 0;
	int nItem = pAct.size();
	int item;
	while (true) {
		cout << ". . . . . . . . . . . . . . . . . .\n";
		cout << "Select one of the following Actions:\n";
		for (int i = 0; i < nItem; ++i) {
			cout << i + 1 << ". ";
			cout << pAct[i]->GetName() << endl;
		}
		item = SelectItem(nItem);
		if (item > 0 && item <= nItem) { // óñëîâèå êîððåêòíîãî ââîäà íîìåðà äåéñòâèÿ
			break;
		}
		else {
			cin.get();
		}
	}
	return pAct[item - 1];
}

int Menu::SelectItem(int nItem) {
	cout << "-------------------\n";
	int item;
	while (true) {
		cin >> item;
		if ((item > 0) && (item <= nItem)) {
			return item;
			break;
		}
		else {
			cout << "Error (must be number from 1 to " << nItem << " ) : " << endl;
			cin.clear();
			while (cin.get() != '\n') {};
			return item;
		}
	}
}