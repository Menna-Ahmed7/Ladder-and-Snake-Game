#pragma once
#include"Action.h"
class InputDiceValueAction :public Action {
private:
	int value;
public:
	InputDiceValueAction(ApplicationManager* p);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputDiceValueAction();
};

