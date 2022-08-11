#pragma once
#include"Action.h"
class SwitchToDesignModeAction:public Action
{
public:
	SwitchToDesignModeAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~SwitchToDesignModeAction(); // Virtual Destructor
};

