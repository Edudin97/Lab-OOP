// ShowStr.h
#include "Action.h"

class ShowStr : public Action {
public:
	ShowStr() : name("Show string value") {}
	void Operate(AString*);
	const std::string& GetName() const { return name; }
private:
	std::string name; // îáîçíà÷åíèå îïåðàöèè
};
extern ShowStr show_str;