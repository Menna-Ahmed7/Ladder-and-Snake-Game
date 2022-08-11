#pragma once
#include"Action.h"

class SwitchToPlayModeAction:public Action
{
public:
	SwitchToPlayModeAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~SwitchToPlayModeAction(); // Virtual Destructor
};

