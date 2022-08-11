#pragma once
#include "Action.h"
class PasteCardAction :public Action {
private:
	CellPosition ToCell;
public:
	PasteCardAction(ApplicationManager* p);
	virtual	void ReadActionParameters();
	virtual	void Execute();
	virtual ~PasteCardAction();
};

