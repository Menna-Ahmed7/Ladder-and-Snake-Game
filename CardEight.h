#pragma once

#include "Card.h"


class CardEight:public Card
{
	int taxcoins;

public:

	CardEight(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardEight 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEight on the passed Player

	virtual void SaveCard(ofstream& OutFile, int cardnum);

	virtual void LoadCard(ifstream& InFile);

	virtual void restartcard();

	virtual int Getcardprice();

	virtual void SetOwner(Player* newowner);

	virtual ~CardEight(); // A Virtual Destructor

};

