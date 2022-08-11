#include "CardTwo.h"
#include "Ladder.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

CardTwo::~CardTwo(void)
{
}

//TODO


void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	pOut->PrintMessage("Card2 Moves the player forward to the start of the next ladder in the grid.");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	// 2- move the player forward to start of next ladder in the grid
	Ladder* L = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());
	//getposition function in gameobject class where ladder inherit from gameobject 
	if (L != NULL)
	{
		//ASK//is true?
		pGrid->UpdatePlayerCell(pPlayer, L->GetPosition());
		L->Apply(pGrid, pPlayer);

	}
	else return;

	// i reached to getting cell of player and pass to getnextladder to find next ladder in the row of player
		//then we have to get cell of next ladder to set to Updateplayercell

}

void CardTwo::SaveCard(ofstream& OutFile, int cardnum)
{
	if (cardnum == 2)
		return;
}

void CardTwo::LoadCard(ifstream& InFile)
{
	return;
}

void CardTwo::restartcard()
{
}

int CardTwo::Getcardprice()
{
	return 0;
}

void CardTwo::SetOwner(Player* newowner)
{
}

