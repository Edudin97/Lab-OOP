// HexString.cpp
#include <iostream>
#include "HexString.h"
using namespace std;

bool IsHexStrVal(string str) {
	for (int i = 0; i < str.size(); ++i)
		if (-1 == alph.find_first_of(str[i]))
			return false;
	return true;
}

HexString::HexString(string _name, string _val) :
	name(_name) {
	if (IsHexStrVal(_val))
		val = _val;
}