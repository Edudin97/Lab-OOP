// OperatorSub.h
#include "Action.h"

class OperatorSub : public Action {
public:
	OperatorSub() : name("Operator -") {}
	void Operate(AString*);
	const std::string& GetName() const { return name; }
private:
	std::string name; // 
};

extern OperatorSub operator_sub;