#pragma once
#include"Action.h"
#include"fstream"
class OpenGridAction :public Action
{
	string Name;
	ifstream inputFile;
public:
	OpenGridAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~OpenGridAction();
};

