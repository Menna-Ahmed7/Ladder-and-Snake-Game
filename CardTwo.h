#pragma once

#include "Card.h"


class CardTwo : public Card
{


public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position


	//TODO

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player
													  //  by moving the player forward to start of next ladder in the grid

	virtual void SaveCard(ofstream& OutFile, int cardnum);

	virtual void LoadCard(ifstream& InFile);

	virtual void restartcard();

	virtual int Getcardprice();
	virtual void SetOwner(Player* newowner);

	virtual ~CardTwo(); // A Virtual Destructor
};

