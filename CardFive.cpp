#include "CardFive.h"


CardFive:: CardFive(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 5;
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	int newcell = pPlayer->getplayercellnum() - pPlayer->GetJustRolledDiceNum();
	CellPosition pos(newcell);
	Card::Apply(pGrid, pPlayer);
	pGrid->GetOutput()->PrintMessage("You have reached card 5,you will go back with your dice value ,click to continue...");
	pGrid->GetInput()->GetPointClicked(x,y);
	pGrid->GetOutput()->ClearStatusBar();
	pGrid->UpdatePlayerCell(pPlayer, pos);
	GameObject* ptr = pPlayer->GetCell()->GetGameObject();
	if (ptr != NULL)
		ptr->Apply(pGrid,pPlayer);
}

void CardFive::SaveCard(ofstream& OutFile, int cardnum)
{
	if (cardnum == 5)
		return;
}

void CardFive::LoadCard(ifstream& InFile)
{
	return;
}

void CardFive::restartcard()
{
}

int CardFive::Getcardprice()
{
	return 0;
}

void CardFive::SetOwner(Player* newowner)
{
}

CardFive::~CardFive()
{
}


