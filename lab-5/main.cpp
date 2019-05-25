#include <fstream>
#include <iostream>
using namespace std;

int main() {
	int maxstr = 3, ch;
	string str = "";

	fstream fp("E:\\lab-5\\data.txt");
	if (!fp.is_open())
		return 1;
	while (!fp.eof()) {
		ch = fp.get();
		str.insert(str.end(), ch);
		if (ch == '.' || ch == '?' || ch == '!') {
			if (--maxstr < 0)
				break;
			_strrev((char*)& str.at(0));
			cout << str.c_str();
			str = "";
		}
	}
	fp.close();
	cin.get();
	return 0;
}