#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"
#include "Grid.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{

	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();



	bool validcellornot = false;

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	if (startPos.VCell() == NumVerticalCells - NumVerticalCells)
	{
		validcellornot = false;
		pGrid->PrintErrorMessage("Error ,startcell of Snake can't be in first row");
	}
	else if (startPos.HCell() != endPos.HCell())
	{
		validcellornot = false;
		pGrid->PrintErrorMessage("Error ,end cell and start cell are not in the same column");
	}
	else if ((startPos.VCell() > endPos.VCell()))
	{
		validcellornot = false;
		pGrid->PrintErrorMessage("Error ,end cell cannot be greater than start cell");
	}
	else if (startPos.VCell() == (NumVerticalCells - 1))
	{
		validcellornot = false;
		pGrid->PrintErrorMessage("startcell of snake can't be in last row");
	}
	else if (startPos.GetCellNum() != endPos.GetCellNum())
	{
		validcellornot = true;
	}

	if (!validcellornot)
	{
		startPos = -1;
		endPos = -1;
		pGrid->PrintErrorMessage("Error occurs , invalid snake parameters");
	}

	// Clear messages
	pOut->ClearStatusBar();

}


// Execute the action
void AddSnakeAction::Execute()
{


	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	Snake* pSnake;


	// The first line of any Action Execution is to read its parameter first 
// and hence initializes its data members
	ReadActionParameters();

	// Create a Snake object with the parameters read from the user
	pSnake = new Snake(startPos, endPos);

	if (!(startPos.IsValidCell() && endPos.IsValidCell()))
		return;

	if (pGrid->IsOverLapping(pSnake))//check
	{

		pGrid->PrintErrorMessage("Error, Overlapping snake");
		delete pSnake;

	}

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pSnake);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}


	// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddSnakeAction

}

