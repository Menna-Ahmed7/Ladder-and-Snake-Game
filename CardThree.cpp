#include "CardThree.h"
#include "RollDiceAction.h"


CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (3 here)
}

CardThree::~CardThree(void)
{
}
//TODO

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	pOut->PrintMessage("Card3 gives the player an extra dice roll..");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	//2- Gives the player an extra dice roll 
	for (int j = 0; j < MaxPlayerCount - 1; j++)
	{
		pGrid->AdvanceCurrentPlayer();
	}

}

void CardThree::SaveCard(ofstream& OutFile, int cardnum)
{
	if (cardnum == 3)
		return;
}

void CardThree::LoadCard(ifstream& InFile)
{
	return;
}

void CardThree::restartcard()
{
}

int CardThree::Getcardprice()
{
	return 0;
}

void CardThree::SetOwner(Player* newowner)
{
}

