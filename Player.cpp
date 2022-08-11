#include "Player.h"

#include "GameObject.h"
#include "CellPosition.h"
#include"Card.h"
Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	Isprevented = false;
	preventedcounts = 0;
	for (int i = 0; i < 3; i++)
		Owningcards[i] = NULL;//set the owning cards of the player to 0 at the start of the game
	Countowning = 0;//start the owned cards by zero
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;

}

Cell* Player::GetCell() const
{
	return pCell;
}
//TODO
int Player::GetPlayerNum()const
{
	return playerNum;
}
//TODO
CellPosition Player::getplayercell()const
{
	CellPosition c = pCell->GetCellPosition();
	return c;

}
//TODO
void Player::SetWallet(int wallet)
{
	if (wallet >= 0)
	{
		this->wallet = wallet;
	}
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}
//TODO
void Player::SetTurnCount(int tcount)//check this function
{
	if (tcount >= 0 && tcount <= 3)
		turnCount = tcount;
}
//TODO
int Player::GetTurnCount() const
{
	return turnCount;
}
//TODO
void Player::SetJustRolledDiceNum(int diceNum)
{
	if (diceNum >= 1 && diceNum <= 6)
	{
		justRolledDiceNum = diceNum;
	}
}
CellPosition Player::getplayercellposition() const
{
	return this->getplayercellposition();
}
int Player::GetJustRolledDiceNum() const
{
	return justRolledDiceNum;
}
int Player::getplayercellnum() 
{
	return getplayercell().GetCellNum();
}
void Player::setifprevented(bool prevented,int count)
{
	Isprevented = prevented;
	preventedcounts = count;
}
bool Player::getifprevented()
{
	return Isprevented;
}

void Player::checkprevented(int pnum)
{
	if (GetPlayerNum() == pnum && preventedcounts==0)
		Isprevented = false;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"

	pOut->DrawPlayer(getplayercell(), GetPlayerNum(), playerColor);

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;


	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(getplayercell(), GetPlayerNum(), cellColor);
}

// ====== Game Functions ======
void Player::Move(Grid* pGrid, int diceNumber)
{
	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int pnum = -1;
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	if (!(pGrid->GetEndGame()))
	{
		// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
		SetTurnCount(GetTurnCount() + 1);
		//Set the justRolledDiceNum with the passed diceNumber
		SetJustRolledDiceNum(diceNumber);

		//to check if the player is prevented from playing by either card4 or card8
		if (!getifprevented())
		{
			// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
			 //    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
			if (GetTurnCount() == 3)
			{
				pOut->PrintMessage("Taking money turn");
				pIn->GetPointClicked(x, y);
				SetWallet(GetWallet() + (10 * diceNumber));
				SetTurnCount(0);
				pOut->ClearStatusBar();
				return;
			}

			//to make the player only move if he has at least 1 coin in his wallet
			if (pGrid->GetCurrentPlayer()->GetWallet() == 0)
			{
				pOut->PrintMessage("No enough money in your wallet , wait until you have coins ..click to continue.");
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				return;     //exits the function , do not move
			}

			// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
			//    Using the appropriate function of CellPosition class to update "pos"
			CellPosition pos = pCell->GetCellPosition();
			int newplayercell = pos.GetCellNum() + diceNumber;

			//checking if the player's cell greater than 99 to put him in 99
			if (newplayercell < NumHorizontalCells * NumVerticalCells)
			{
				// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
				//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
				pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), CellPosition(newplayercell));

				// 6- Apply() the game object of the reached cell (if any) 
				GameObject* G = GetCell()->GetGameObject();
				if (G != NULL)
				{
					G->Apply(pGrid, pGrid->GetCurrentPlayer());
				}
			}
			else
			{
				newplayercell = NumHorizontalCells * NumVerticalCells;
				pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), CellPosition(newplayercell));
			}
		}
		else
		{
			if (GetTurnCount() == 3)
			{
				pOut->PrintMessage("Taking money turn but the current player is prevented");
				pIn->GetPointClicked(x, y);
				SetTurnCount(0);
				pOut->ClearStatusBar();
			}
			pnum = pGrid->GetCurrentPlayer()->GetPlayerNum();
			preventedcounts--;
		}
		// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
		if (getplayercellnum() == (NumVerticalCells * NumHorizontalCells))
		{
			pGrid->SetEndGame(true);
			pOut->PrintMessage("Congratulations, You are the Winner!");
		}
		checkprevented(pnum);
	}
	else
	{

		pOut->PrintMessage("A player reached the end cell ,END OF THE GAME");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
}

void Player::setOwningCards(Card* c) 
{
	Owningcards[Countowning] = c;
	Countowning++;
}

Card* Player::Getmostexpensivecard() 
{
	if (Owningcards[0] != NULL)
	{
		int max = Owningcards[0]->Getcardprice();
		Card* maxcard = Owningcards[0];
		for (int i = 1; i < Countowning; i++) {
			if (max < Owningcards[i]->Getcardprice()) 
			{
				max = Owningcards[i]->Getcardprice();
				maxcard = Owningcards[i];
			}
		}
		return maxcard;
	}
	else return NULL;//it means the player doesnt have any card
}

void Player::deleteowningcard(Card* c) 
{
	if (c != NULL)
		for (int i = 0; i < Countowning; i++)
			if (c == Owningcards[i])
			{
				Owningcards[i] = NULL;
				swap(Owningcards[i], Owningcards[Countowning]);
				Countowning--;
			}
			else	
				return;
}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}