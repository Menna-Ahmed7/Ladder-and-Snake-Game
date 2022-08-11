#include "CardTwelve.h"
#include "Grid.h"
CardTwelve::CardTwelve(const CellPosition& pos) :Card(pos) {
	cardNumber = 12;
}
void CardTwelve::ReadCardParameters(Grid* pGrid)
{
	//no card parmeters to read


}
void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Player* Poorestplayer = pGrid->GetPoorestPlayer();
	Card* mostexpensive = pPlayer->Getmostexpensivecard();
	if (mostexpensive != NULL && Poorestplayer->GetPlayerNum()!=pPlayer->GetPlayerNum()) //This validates that the player does have stations and he is not the poorest player
	{
		Card::Apply(pGrid, pPlayer);
		pOut->PrintMessage("Your Most Expensive Station will go to the poorest player ,click to continue");
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
		pPlayer->deleteowningcard(mostexpensive);//delete the card from player's owning stations
		mostexpensive->SetOwner(Poorestplayer);//set the new owner of the card
		Poorestplayer->setOwningCards(mostexpensive);//add the card to the player's stations
	}
	else return;
}

CardTwelve::~CardTwelve() {


}

void CardTwelve::SaveCard(ofstream& OutFile, int cardnum)
{
	if (cardnum == 12)
		return;
}

void CardTwelve::LoadCard(ifstream& InFile)
{
	return;
}

void CardTwelve::restartcard()
{
}

int CardTwelve::Getcardprice()
{
	return 0;
}

void CardTwelve::SetOwner(Player* newowner)
{
}
