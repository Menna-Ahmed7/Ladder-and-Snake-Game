#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos):Card(pos)
{
	cardNumber = 6;
}

void CardSix::ReadCardParameters(Grid* pGrid)
{
	int x, y;
	pGrid->GetOutput()->PrintMessage("New CardSix: Enter the cellNum to make the player to move to ...");
	pGrid->GetInput()->GetPointClicked(x, y);
	pGrid->GetOutput()->ClearStatusBar();
	enteredcellnum = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	Card::Apply(pGrid,pPlayer);
	pGrid->GetOutput()->PrintMessage("You have reached card 6 ,you will go to the cell you had choosen ,click to continue...");
	pGrid->GetInput()->GetPointClicked(x, y);
	pGrid->GetOutput()->ClearStatusBar();
	CellPosition pos(enteredcellnum);
	pGrid->UpdatePlayerCell(pPlayer, pos );
}

void CardSix::SaveCard(ofstream& OutFile, int cardnum)
{
	if (cardnum == 6)
	{
		OutFile << enteredcellnum;
	}
}

void CardSix::LoadCard(ifstream& InFile)
{
	int cellnum;
	InFile >> cellnum;
	this->enteredcellnum = cellnum;
}

void CardSix::restartcard()
{
}

int CardSix::Getcardprice()
{
	return 0;
}

void CardSix::SetOwner(Player* newowner)
{
}

CardSix::~CardSix()
{
}
