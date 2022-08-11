#pragma once

#include "Card.h"


class CardThree : public Card
{


public:
	CardThree(const CellPosition& pos); // A Constructor takes card position


	//TODO

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
													  //  by giving the player an extra dice roll
	virtual void SaveCard(ofstream& OutFile, int cardnum);

	virtual void LoadCard(ifstream& InFile);

	virtual void restartcard();
	virtual int Getcardprice();
	virtual void SetOwner(Player* newowner);

	virtual ~CardThree(); // A Virtual Destructor
};


