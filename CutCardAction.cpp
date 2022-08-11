#include"CutCardAction.h"
#include"Grid.h"
CutCardAction::CutCardAction(ApplicationManager* p) :Action(p) {


}
void CutCardAction::ReadActionParameters() {

	int x, y;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("click on the source cell");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	sourcecell = pIn->GetCellClicked();
}
void CutCardAction::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	if (sourcecell.IsValidCell())
	{
		pGrid->SetClipboard(pGrid->GetCardofCell(sourcecell));
		pGrid->RemoveObjectFromCell(sourcecell);
		pOut->DrawCell(sourcecell, -1);
	}

}
CutCardAction::~CutCardAction() {

}
