#pragma once
#include"Card.h"
class CardTen :public Card {
private:
	static int cardprice;//int or float ?
	static int fees;
	static bool check;//if true it means there is no card nine allocated yet;
	static bool avaliable;//checks if the card is availabe to buy
	static Player* owner;//the current owner of the card;
	static int count;//current cards of CardNine
	static bool readed;
	static bool saved;
public:
	CardTen(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void SaveCard(ofstream& OutFile, int cardnum);
	virtual void LoadCard(ifstream& InFile);
	virtual void restartcard();
	virtual int Getcardprice();
	virtual void SetOwner(Player* newowner);
	virtual ~CardTen();
};



