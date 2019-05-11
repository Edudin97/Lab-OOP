// Menu.h
#include <vector>
#include "AString.h"
#include "Action.h"
#include "Factory.h"

typedef enum { AddObj, DelObj, WorkWithObj, Exit } JobMode;

class Menu {
public:
	Menu(std::vector<Action*>);
	JobMode SelectJob() const;
	AString* SelectObject(const Factory&, const std::string) const;
	Action* SelectAction(const AString*) const;
	static int SelectItem(int);
private:
	std::vector<Action*> pAct;
};