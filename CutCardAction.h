#pragma once
#include"Action.h"
class CutCardAction :public Action {
private:
	CellPosition sourcecell;
public:
	CutCardAction(ApplicationManager* p);
	virtual	void ReadActionParameters();
	virtual	void Execute();
	virtual ~CutCardAction();



};
