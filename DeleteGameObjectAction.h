#pragma once
#include"Action.h"
class DeleteGameobjectAction :public Action {
	CellPosition sourcecell;
public:
	DeleteGameobjectAction(ApplicationManager* p);
	virtual	void ReadActionParameters();
	virtual	void Execute();
	virtual ~DeleteGameobjectAction();
};

