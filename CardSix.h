#pragma once
#include "Card.h"

class CardSix:public Card
{
	int enteredcellnum;

public:
	CardSix(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardSix

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSix on the passed Player

	virtual void SaveCard(ofstream& OutFile,int cardnum);

	virtual void LoadCard(ifstream& InFile);

	virtual void restartcard();

	virtual int Getcardprice();

	virtual void SetOwner(Player* newowner);

	virtual ~CardSix(); // A Virtual Destructor
};

