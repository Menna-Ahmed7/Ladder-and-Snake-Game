#include"DeleteGameobjectAction.h"
#include"Grid.h"
DeleteGameobjectAction::DeleteGameobjectAction(ApplicationManager* p) :Action(p)
{

}
void DeleteGameobjectAction::ReadActionParameters() 
{
	int x, y;
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the start cell of the object you want to delete ,click to continue...");
	pIn->GetPointClicked(x,y);
	pOut->ClearStatusBar();
	sourcecell = pIn->GetCellClicked();
}
void DeleteGameobjectAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	if (sourcecell.IsValidCell())
	{
		pGrid->RemoveObjectFromCell(sourcecell);
		pOut->DrawCell(sourcecell, -1);
	}
}
DeleteGameobjectAction::~DeleteGameobjectAction() {

}
