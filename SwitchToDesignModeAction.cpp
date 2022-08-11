#include "SwitchToDesignModeAction.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"

SwitchToDesignModeAction::SwitchToDesignModeAction(ApplicationManager* pApp):Action(pApp)
{
}

void SwitchToDesignModeAction::ReadActionParameters()
{
}

void SwitchToDesignModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();
}

SwitchToDesignModeAction::~SwitchToDesignModeAction()
{
}
