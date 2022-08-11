#include"CardEleven.h"
bool CardEleven::check = true;
int CardEleven::count = 0;
bool CardEleven::avaliable = true;
Player* CardEleven::owner = NULL;
int CardEleven::cardprice = 0;//
//not required!!
int CardEleven::fees = 0;
bool CardEleven::readed = false;
bool CardEleven::saved = false;
CardEleven::CardEleven(const CellPosition& pos) :Card(pos) {
	cardNumber = 11;
	count++;
}
void CardEleven::ReadCardParameters(Grid* pGrid) {
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
void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	string s;
	pOut->PrintMessage("You have reached Card11..");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	if (avaliable) {
		pOut->PrintMessage("You have an option to buy this cell.... ");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		pOut->PrintMessage("Type yes if you want to buy the cell and No if you don't want to  : ");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		s = pIn->GetSrting(pOut);
		pOut->ClearStatusBar();
		if (s == "Yes" || s == "yes") 
		{
			CardEleven* p=new CardEleven(0);
			pPlayer->setOwningCards(p);
			owner = pPlayer;
			avaliable = false;
			pPlayer->SetWallet(pPlayer->GetWallet() - cardprice);


		}
		else {
			pOut->PrintMessage("Card11 won't be bought Thank you...");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			return;
		}
	}
	else
	{
		if (owner->GetPlayerNum() != pPlayer->GetPlayerNum())
		{
			pOut->PrintMessage("A fees will be taken from your wallet Thank You...");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			pPlayer->SetWallet(pPlayer->GetWallet() - fees);
			owner->SetWallet(owner->GetWallet() + fees);
		}
		else
		{
			pOut->PrintMessage("You Own Card11..");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			return;
		}
	}
}
void CardEleven::SaveCard(ofstream& OutFile, int cardnum)
{
	if (cardnum == 11 && !saved)
	{
		OutFile << cardprice << " " << fees;
		saved = true;
	}
}
void CardEleven::LoadCard(ifstream& InFile)
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
void CardEleven::restartcard()
{
	avaliable = true;
	owner = NULL;
}

int CardEleven::Getcardprice()
{
	return cardprice;
}

void CardEleven::SetOwner(Player* newowner)
{
	owner = newowner;
	//add the card to the player owningcards 
}

CardEleven::~CardEleven()
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