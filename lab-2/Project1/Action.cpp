// Action.cpp
#include <iostream>
#include "Action.h"
#include "HexString.h"
using namespace std;

long Action::GetDecimal(AString* pObj) const {
	if (dynamic_cast<HexString*>(pObj)) {
		long dest;
		string source = pObj->GetVal();
		sscanf(source.c_str(), "%x", &dest);
		return dest;
	}
	else {
		cout << "Action not supported." << endl;
		return -1;
	}
}