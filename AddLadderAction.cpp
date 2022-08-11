#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();


	///TODO: Make the needed validations on the read parameters
	bool validcellornot = false;

	if (startPos.VCell() == NumVerticalCells - 1)
	{
		validcellornot = false;
		pGrid->PrintErrorMessage("Error ,startcell of ladder can't be in last row");
	}
	else if (startPos.HCell() != endPos.HCell())
	{
		validcellornot = false;
		pGrid->PrintErrorMessage("Error ,end cell and start cell are not in the same column");
	}
	else if ((startPos.VCell() < endPos.VCell()))
	{
		validcellornot = false;
		pGrid->PrintErrorMessage("Error ,end cell cannot be smaller than start cell");
	}
	else if (startPos.VCell() == (NumVerticalCells - NumVerticalCells))
	{
		validcellornot = false;
		pGrid->PrintErrorMessage("startcell of ladder can't be in first row");
	}
	else if (startPos.GetCellNum() != endPos.GetCellNum())
	{
		validcellornot = true;
	}


	if (!validcellornot)
	{
		startPos = -1;
		endPos = -1;
		pGrid->PrintErrorMessage("Error occurs , invalid ladder parameters");
	}

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	if (!((startPos.IsValidCell()) && (endPos.IsValidCell())))
		return;

	if (pGrid->IsOverLapping(pLadder))//check
	{

		pGrid->PrintErrorMessage("Error, Overlapping ladder");
		delete pLadder;

	}

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (! added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
