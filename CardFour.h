#pragma once

#include "Card.h"


class CardFour : public Card
{


public:
	CardFour(const CellPosition& pos); // A Constructor takes card position


	//TODO
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player
													  // by prevents the player from rolling next turn
	virtual void SaveCard(ofstream& OutFile, int cardnum);

	virtual void LoadCard(ifstream& InFile);

	virtual void restartcard();

	virtual int Getcardprice();
	virtual void SetOwner(Player* newowner);

	virtual ~CardFour(); // A Virtual Destructor
};


