#include "Snake.h"
#include "Player.h" 
#include "Ladder.h"
#include"Card.h"
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{

	this->endCellPos = endCellPos;

}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click

	pOut->PrintMessage("You have reached a Snake. Click to continue .....");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	// 2- Apply the Snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, GetEndPosition());
	Card* C = pPlayer->GetCell()->HasCard();
	if (C != NULL)
		C->Apply(pGrid, pPlayer);
}


bool Snake::IsOverLapping(GameObject* newobj) const
{
	int oldsnakestart = this->GetPosition().VCell();
	int oldsnakeend = this->GetEndPosition().VCell();
	Snake* s = dynamic_cast<Snake*>(newobj);
	Ladder* l = dynamic_cast<Ladder*>(newobj);

	if (s)
	{

		int newsnakestart = s->GetPosition().VCell();
		int newsnakeend = s->GetEndPosition().VCell();
		if (this->GetPosition().HCell() == s->GetPosition().HCell())
		{
			for (int i = oldsnakestart; i <= oldsnakeend; i++)
			{
				for (int j = newsnakestart; j <= newsnakeend; j++)
				{
					if (i == j)
						return true;

				}
			}
		}

	}
	else if (l)
	{

		if ((l->GetPosition().VCell() == GetEndPosition().VCell()) && (l->GetPosition().HCell() == GetEndPosition().HCell()))
			return true;
	}
	else return false;

	return false;


}

void Snake::Save(ofstream& OutFile, Type gobj)
{
	if (gobj == Type::snake)
	{
		int x = GetPosition().GetCellNum();
		int y = endCellPos.GetCellNum();
		OutFile << x << " " << y << endl;
	}
}

void Snake::Load(ifstream& InFile)
{
	int cellnum1, cellnum2;
	InFile >> cellnum1;
	InFile >> cellnum2;
	this->position = cellnum1;
	this->endCellPos = cellnum2;
}



CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}


Snake::~Snake()
{
}
