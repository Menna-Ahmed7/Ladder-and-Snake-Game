#include "CopyCardAction.h"
#include"Grid.h"
CopyCardAction::CopyCardAction(ApplicationManager* p) : Action(p)
{

}
void CopyCardAction::ReadActionParameters() {
	int x, y;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("click on the source cell");
	pIn->GetPointClicked(x,y);
	pOut->ClearStatusBar();
	SourceCell = pIn->GetCellClicked();
}
void CopyCardAction::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (SourceCell.IsValidCell())
		pGrid->SetClipboard(pGrid->GetCardofCell(SourceCell));
}
CopyCardAction::~CopyCardAction() {

}
