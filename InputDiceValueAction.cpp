#include"InputDiceValueAction.h"
#include"Grid.h"
#include"Player.h"
InputDiceValueAction::InputDiceValueAction(ApplicationManager* p) :Action(p) {
	value = 0;

}
void InputDiceValueAction::ReadActionParameters() {
	int v;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please Enter a Value between 1-6.....");
	v = pIn->GetInteger(pOut);
	if (v > 0 && v <= 6)
		value = v;
	else 
	{
		pOut->PrintMessage("Error!Value must be between 1-6....");
			return;
	}

}
void InputDiceValueAction::Execute() 
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	ReadActionParameters();
	Player* p = pGrid->GetCurrentPlayer();
	p->Move(pGrid, value);
	pOut->ClearStatusBar();
	pGrid->AdvanceCurrentPlayer();
}

InputDiceValueAction::~InputDiceValueAction() 
{
}
