#include "NewGameAction.h"
#include "Grid.h"
#include "Player.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"GameObject.h"

NewGameAction::NewGameAction(ApplicationManager* pApp):Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{
}

void NewGameAction::Execute()
{	
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	CellPosition pos(1);
	Player* p;
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		p = pGrid->GetCurrentPlayer();
		pGrid->UpdatePlayerCell(p, pos);
		p->SetWallet(100);
		p->SetTurnCount(0);
		p->setifprevented(false,0);
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->setcurrentplayernumber(0);
	pGrid->restartcards();
	pGrid->SetEndGame(false);
}

NewGameAction::~NewGameAction()
{
}
