#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos):Card(pos)
{
	cardNumber = 7;
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	Player* nextplayer = pGrid->getnextplayerincell(pPlayer);
	Card::Apply(pGrid, pPlayer);
	pGrid->GetOutput()->PrintMessage("You have reached card 7,the next player after you in the grid will restart the game ,click to continue...");
	pGrid->GetInput()->GetPointClicked(x, y);
	pGrid->GetOutput()->ClearStatusBar();
	CellPosition pos(1);
	if(pPlayer->getplayercellnum()!=nextplayer->getplayercellnum() && nextplayer->getplayercellnum() > pPlayer->getplayercellnum())
	     pGrid->UpdatePlayerCell(nextplayer, pos);
}

void CardSeven::SaveCard(ofstream& OutFile, int cardnum)
{
	if (cardnum == 7)
		return;
}

void CardSeven::LoadCard(ifstream& InFile)
{
	return;
}

void CardSeven::restartcard()
{
}

int CardSeven::Getcardprice()
{
	return 0;
}

void CardSeven::SetOwner(Player* newowner)
{
}

CardSeven::~CardSeven()
{
}
