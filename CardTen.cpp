#include"CardTen.h"
bool CardTen::check = true;
int CardTen::count = 0;
bool CardTen::avaliable = true;
Player* CardTen::owner = NULL;
int CardTen::cardprice = 0;//
//not required!!
int CardTen::fees = 0;//
bool CardTen::readed = false;
bool CardTen::saved = false;
CardTen::CardTen(const CellPosition& pos) :Card(pos) {
	cardNumber = 10;
	count++;
}
void CardTen::ReadCardParameters(Grid* pGrid)
{
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
void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	string s;
	pOut->PrintMessage("You have reached Card 10 ,click to continue...");
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
			CardTen* p=new CardTen(0);
			pPlayer->setOwningCards(p);
			owner = pPlayer;
			avaliable = false;
			pPlayer->SetWallet(pPlayer->GetWallet() - cardprice);
		}
		else 
		{
			pOut->PrintMessage("Card10 won't be bought ,click to continue...");
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
		}
		else
		{
			pOut->PrintMessage("You Own Card10 ,click to continue...");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			return;
		}
	}
}
void CardTen::SaveCard(ofstream& OutFile, int cardnum)
{
	if (cardnum == 10 && !saved)
	{
		OutFile << cardprice << " " << fees;
		saved = true;
	}
}
void CardTen::LoadCard(ifstream& InFile)
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
void CardTen::restartcard()
{
	avaliable = true;
	owner = NULL;
}

int CardTen::Getcardprice()
{
	return cardprice;
}

void CardTen::SetOwner(Player* newowner)
{
	owner = newowner;
	//add the card to the player owningcards 
}

CardTen::~CardTen()
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