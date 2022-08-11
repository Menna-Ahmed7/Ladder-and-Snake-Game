#pragma once
#include "Card.h"

class CardFive :public Card
{

public:
	CardFive(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFive on the passed Player
												
	virtual void SaveCard(ofstream& OutFile, int cardnum);

	virtual void LoadCard(ifstream& InFile);

	virtual void restartcard();

	virtual int Getcardprice();

	virtual void SetOwner(Player* newowner);

	virtual ~CardFive(); // A Virtual Destructor
};
