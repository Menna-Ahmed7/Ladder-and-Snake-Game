#include"CardNine.h"
bool CardNine::check = true;
int CardNine::count = 0;
bool CardNine::avaliable = true;
Player* CardNine::owner = NULL;
int CardNine::cardprice = 0;//not required!!
int CardNine::fees = 0;//
bool CardNine::readed = false;
bool CardNine::saved = false;
CardNine::CardNine(const CellPosition& pos) :Card(pos) 
{
	cardNumber = 9;
	count++;
}
void CardNine::ReadCardParameters(Grid* pGrid) {
	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (check) {
		pOut->PrintMessage("Enter the Card price :");
		x = pIn->GetInteger(pOut);
		if (x >= 0)cardprice = x;
		pOut->ClearStatusBar();
		pOut->PrintMessage("Enter the fees value :");
		y = pIn->GetInteger(pOut);
		if (y >= 0)
			fees = y;
		check = false;
		pOut->ClearStatusBar();
	}
	else return;
}
void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	string s;
	pOut->PrintMessage("You have reached Card 9 ,click to continue...");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	if (avaliable)
	{
		pOut->PrintMessage("You have an option to buy this cell ,click to continue... ");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		pOut->PrintMessage("Type yes if you want to buy the cell and No if you don't want to ,click to continue... ");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		s = pIn->GetSrting(pOut);
		pOut->ClearStatusBar();
		if (s == "Yes" || s == "yes")
		{
			CardNine* p=new CardNine(0);
			pPlayer->setOwningCards(p);
			owner = pPlayer;
			avaliable = false;
			pPlayer->SetWallet(pPlayer->GetWallet() - cardprice);
		}
		else
		{
			pOut->PrintMessage("Card 9 won't be bought ,click to continue...");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			return;
		}
	}
	else
	{
		if (owner->GetPlayerNum() != pPlayer->GetPlayerNum())
		{
			pOut->PrintMessage("A fees will be taken from your wallet ,click to continue...");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			pPlayer->SetWallet(pPlayer->GetWallet() - fees);
			owner->SetWallet(owner->GetWallet() + fees);
			return;
		}
		else
		{
			pOut->PrintMessage("You Own Card 9 ,click to continue...");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			return;
		}
	}
}
void CardNine::SaveCard(ofstream& OutFile, int cardnum)
{
	if (cardnum == 9 && !saved)
	{
		OutFile << cardprice << " " << fees;
		saved= true;
	}
}
void CardNine::LoadCard(ifstream& InFile)
{
	if (!readed)
	{
		int price, f;
		InFile >> price >> f;
		this->cardprice = price;
		this->fees = f;
		readed = true;
	}
}

void CardNine::restartcard()
{
	avaliable = true;
	owner = NULL;
}

int CardNine::Getcardprice()
{
	return cardprice;
}

void CardNine::SetOwner(Player* newowner)
{
	owner = newowner;
	//add the card to the player owningcards 
}

CardNine::~CardNine()
{
    count--;
	if (count == 0)
	{
		check = true;
	    avaliable = true;
		owner == NULL;
		//do we set check to true??//as it will read price&fees
	}
}