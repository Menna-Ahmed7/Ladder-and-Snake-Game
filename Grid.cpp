#include "Grid.h"

#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Card.h"
#include "Player.h"
#include"CardOne.h"
#include"CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include"CardSeven.h"
#include"CardEight.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"

Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if( pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}


// Note: You may need to change the return type of this function (Think)
void Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);
	
	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}


// ========= Setters and Getters Functions =========


Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card * pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}

Card * Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

// ========= Other Getters =========


Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder * Grid::GetNextLadder(const CellPosition & position)
{
	
	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			Ladder* L = CellList[i][j]->HasLadder();
			if (L != NULL)
			{
				return L;
			}

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}


// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount-1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}


void Grid::SaveAll(ofstream& OutFile, Type GOBJ)
{
	GameObject* ptr;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			ptr=CellList[i][j]->GetGameObject();
			if(ptr!=NULL)
				ptr->Save(OutFile, GOBJ);
		}
}

int Grid::count(Type GOBJ)
{
	int cl=0,cc=0,cs=0;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
		for (int j = 0; j < NumHorizontalCells; j++)
			if (CellList[i][j]->HasLadder())
				cl++;
			else if (CellList[i][j]->HasCard())
				cc++;
			else if (CellList[i][j]->HasSnake())
				cs++;
	if (GOBJ == Type::ladder)
		return cl;
	else if (GOBJ == Type::card)
		return cc;
	else if (GOBJ == Type::snake)
		return cs;
}

Player* Grid::getnextplayerincell(Player* p)     //check every player position and return the nearest player to the current player
{
	int n = p->getplayercellnum();                           
	int pnum = p->GetPlayerNum();
	int min = 100;                               //let minimum cellnum = 100 as it never can happen
	int j = 0;
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		if (PlayerList[i]->GetPlayerNum() != pnum && PlayerList[i]->getplayercellnum() < min && PlayerList[i]->getplayercellnum() > n)
		{   
			min = PlayerList[i]->getplayercellnum();
			j = i;
		}
	}
	return PlayerList[j];
}

bool Grid::IsOverLapping(GameObject* newobj) const
{

	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			if (CellList[i][j]->GetGameObject() != NULL)
			{
				if (CellList[i][j]->GetGameObject()->IsOverLapping(newobj))
					return true;
			}
		}
	}
	return false;
}

void Grid::ClearAll()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			RemoveObjectFromCell(CellList[i][j]->GetCellPosition());
		}
	}
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		CellPosition pos(1);
		Player* p = GetCurrentPlayer();
		UpdatePlayerCell(p, pos);
		p->SetWallet(100);
		p->SetTurnCount(0);
	    AdvanceCurrentPlayer();
	}
}

void Grid::setcurrentplayernumber(int num)
{
	currPlayerNumber = num;
}

void Grid::restartcards()
{
	Card* ptr;
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
		    ptr = CellList[i][j]->HasCard();
			if (ptr != NULL)
				ptr->restartcard();
		}
	}
}

Card* Grid::GetCardofCell(const  CellPosition& c)
{
	Card* card = CellList[c.VCell()][c.HCell()]->HasCard();
	return card;
}



Player* Grid::GetPoorestPlayer()
{
	int min = PlayerList[0]->GetWallet();
	Player* poor = PlayerList[0];
	for (int i = 1; i < 4; i++)
		if (min > PlayerList[i]->GetWallet()) {
			min = PlayerList[i]->GetWallet();
			poor = PlayerList[i];
		}
	return poor;
}

bool Grid::hasgameobject(const CellPosition& pos)
{
	GameObject* pObj = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
	if (pObj)  // the cell already contains a game object
		return false; // do NOT add and return false
	return true;
}


Grid::~Grid()
{
	delete pIn;
	delete pOut;
	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			RemoveObjectFromCell(CellList[i][j]->GetCellPosition());
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}
}