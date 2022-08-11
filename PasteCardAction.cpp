#include "PasteCardAction.h"
#include"Grid.h"
#include"Card.h"
#include"CardOne.h"
#include"CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include"CardSeven.h"
#include"CardEight.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"

PasteCardAction::PasteCardAction(ApplicationManager* p) :Action(p)
{

}
void PasteCardAction::ReadActionParameters()
{
	int x, y;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("click on the destination cell");
	pIn->GetPointClicked(x,y);
	pOut->ClearStatusBar();
	ToCell = pIn->GetCellClicked();

}

void PasteCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Card* C = pGrid->GetClipboard();
	if (ToCell.IsValidCell()) // Check if valid position
	{
		Card* pObj;
		bool check = pGrid->hasgameobject(ToCell);         //checks if the cell has game object or not
		if (check)
		{
			switch (C->GetCardNumber())
			{
			case 1:
				pObj = new CardOne(ToCell);
				pGrid->AddObjectToCell(pObj);
				break;
			case 2:
				pObj = new CardTwo(ToCell);
				pGrid->AddObjectToCell(pObj);
				break;
			case 3:
				pObj = new CardThree(ToCell);
				pGrid->AddObjectToCell(pObj);
				break;
			case 4:
				pObj = new CardFour(ToCell);
				pGrid->AddObjectToCell(pObj);
				break;
			case 5:
				pObj = new CardFive(ToCell);
				pGrid->AddObjectToCell(pObj);
				break;
			case 6:
				pObj = new CardSix(ToCell);
				pGrid->AddObjectToCell(pObj);
				break;
			case 7:
				pObj = new CardSeven(ToCell);
				pGrid->AddObjectToCell(pObj);
				break;
			case 8:
				pObj = new CardEight(ToCell);
				pGrid->AddObjectToCell(pObj);
				break;
			case 9:
				pObj = new CardNine(ToCell);
				pGrid->AddObjectToCell(pObj);
				break;
			case 10:
				pObj = new CardTen(ToCell);
				pGrid->AddObjectToCell(pObj);
				break;
			case 11:
				pObj = new CardEleven(ToCell);
				pGrid->AddObjectToCell(pObj);
				break;
			case 12:
				pObj = new CardTwelve(ToCell);
				pGrid->AddObjectToCell(pObj);
				break;
			}
		}
	}
}

PasteCardAction::~PasteCardAction() 
{
}

