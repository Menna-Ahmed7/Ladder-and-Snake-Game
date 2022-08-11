#include "CardOne.h"

CardOne::CardOne(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

CardOne::~CardOne(void)
{
}

void CardOne::setwalletAmount(int amount)
{
	walletAmount = amount;

}
int CardOne::getwalletAmount()
{
	return walletAmount;
}

void CardOne::SaveCard(ofstream& OutFile, int cardnum)
{
	if (cardnum == 1 )
	{
		OutFile << walletAmount;
	}
}

void CardOne::LoadCard(ifstream& InFile)
{
		int amountofdec;
		InFile >> amountofdec;
		this->setwalletAmount(amountofdec);
}

void CardOne::restartcard()
{
	return;
}

int CardOne::Getcardprice()
{
	return 0;
}

void CardOne::SetOwner(Player* newowner)
{
}

void CardOne::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	pGrid->GetOutput()->PrintMessage("New CardOne :please enter wallet amount to decrement");
	int walletnumdecrement = pGrid->GetInput()->GetInteger(pGrid->GetOutput());

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	setwalletAmount(walletnumdecrement);
	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pGrid->GetOutput()->ClearStatusBar();

}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	pOut->PrintMessage("Card1 Decrements the player’s wallet by a value specified ");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	if (pPlayer->GetWallet() < getwalletAmount())
		pPlayer->SetWallet(0);
	else
		pPlayer->SetWallet(pPlayer->GetWallet() - getwalletAmount());
}
