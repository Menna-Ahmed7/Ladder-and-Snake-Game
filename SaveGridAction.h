#pragma once
#include"Action.h"
#include"fstream"
class SaveGridAction:public Action
{
	ofstream outputFile;
	string Name;
public:
	SaveGridAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~SaveGridAction();
};


