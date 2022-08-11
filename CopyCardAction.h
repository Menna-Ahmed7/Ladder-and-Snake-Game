#pragma once
#include "Action.h"
class CopyCardAction :public Action
{
private:
	CellPosition SourceCell;
public:
	CopyCardAction(ApplicationManager* p);
	virtual	void ReadActionParameters();
	virtual	void Execute();
	virtual ~CopyCardAction();
};