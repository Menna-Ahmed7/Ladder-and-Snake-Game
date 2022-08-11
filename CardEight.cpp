#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos):Card(pos)
{
	cardNumber = 8;
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	pGrid->GetOutput()->PrintMessage("New CardEight: Enter the amounts needed to go out of the prison ...");
	taxcoins = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	pGrid->GetOutput()->ClearStatusBar();
}                                             

void CardEight::Apply(Grid* pGrid, Player* pPlayer) 
{
	int choosennum = 0,x,y;
	Card::Apply( pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You entered the prison:the tax coins equal "+ to_string(taxcoins)+" ,click to continue...");
	pIn->GetPointClicked(x,y);
	pOut->ClearStatusBar();
	pOut->PrintMessage("Choose to pay the tax coins (Enter 1) or to go to the prison (Enter 0) ,click to continue...");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	choosennum =pIn->GetInteger(pGrid->GetOutput());
	pGrid->GetOutput()->ClearStatusBar();
	if (choosennum == 1)
	{
		if (pPlayer->GetWallet() >= taxcoins)
		{
			pOut->PrintMessage("You choose to pay the tax coins,check your wallet ,click to continue...");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			pPlayer->SetWallet(pPlayer->GetWallet() - taxcoins);
		}
		else 
		{
			pOut->PrintMessage("You did not have enough money, so you will go to the prison ,click to continue...");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			pPlayer->setifprevented(true, 3);
		}
	}
	else if (choosennum == 0)
	{
		pOut->PrintMessage("You choosed to go to prison ,click to continue...");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		// prevents the player from rolling next 3 turns
		pPlayer->setifprevented(true, 3);
	}
	else
	{
		pOut->PrintMessage("You did not choose correctly, so you will go to the prison ,click to continue...");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		pPlayer->setifprevented(true, 3);
	}
}

void CardEight::SaveCard(ofstream& OutFile, int cardnum)
{
	if (cardnum == 8 )
	{
		OutFile << taxcoins;
	}
}

void CardEight::LoadCard(ifstream& InFile)
{
	int tax;
	InFile >> tax;
	this->taxcoins = tax;
}

void CardEight::restartcard()
{
}

int CardEight::Getcardprice()
{
	return 0;
}

void CardEight::SetOwner(Player* newowner)
{
}

CardEight::~CardEight()
{
}
