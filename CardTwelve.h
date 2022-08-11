#pragma once
#include "Card.h"

class CardTwelve:public Card
{
public:
	CardTwelve(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual int Getcardprice(); //specific for cards 9->11
	virtual void SetOwner(Player* newowner);//specific for cards 9->11
	virtual void SaveCard(ofstream& OutFile, int cardnum);
	virtual void LoadCard(ifstream& InFile);
	virtual void restartcard();
	virtual ~CardTwelve();
};

