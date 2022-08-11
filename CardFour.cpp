#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (4 here)
}

int CardFour::Getcardprice()
{
	return 0;
}

void CardFour::SetOwner(Player* newowner)
{
}

CardFour::~CardFour(void)
{
}


void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	pOut->PrintMessage("Card4 prevents the player from rolling the next turn.");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	// 2- prevents the player from rolling next turn
	pPlayer->setifprevented(true,1);
}

void CardFour::SaveCard(ofstream& OutFile, int cardnum)
{
	if (cardnum == 4)
		return;
}

void CardFour::LoadCard(ifstream& InFile)
{
	return;
}

void CardFour::restartcard()
{
}

