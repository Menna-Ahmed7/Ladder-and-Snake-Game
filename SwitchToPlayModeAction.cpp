#include "SwitchToPlayModeAction.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"

SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp) :Action(pApp)
{
}

void SwitchToPlayModeAction::ReadActionParameters()
{
}

void SwitchToPlayModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreatePlayModeToolBar();
}

SwitchToPlayModeAction::~SwitchToPlayModeAction()
{
}
