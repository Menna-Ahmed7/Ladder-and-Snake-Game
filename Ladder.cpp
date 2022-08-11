#include "Ladder.h"
#include "Snake.h"
#include"Player.h"
#include"Card.h"
#include <iostream>
using namespace std;

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	///TODO: Do the needed validation
	if (GetPosition().VCell() > GetEndPosition().VCell())
		this->endCellPos = endCellPos;
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	pOut->PrintMessage("You have reached a ladder. Click to continue .....");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, GetEndPosition());
	Card* C = pPlayer->GetCell()->HasCard();
	if (C != NULL)
		C->Apply(pGrid,pPlayer);
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder::Save(ofstream& OutFile, Type gobj)
{	
	if (gobj == Type::ladder)
	{
		int x = GetPosition().GetCellNum();
		int y = endCellPos.GetCellNum();
		OutFile << x << " " << y << endl;
	}
}

void Ladder::Load(ifstream& InFile)
{
	int cellnum1, cellnum2;
	InFile >> cellnum1;
	InFile >> cellnum2;
	this->position = cellnum1;
	this->endCellPos = cellnum2;
}

bool Ladder::IsOverLapping(GameObject* newobj) const
{
	int oldladderstart = this->GetPosition().VCell();
	int oldladderend = this->GetEndPosition().VCell();
	Ladder* l = dynamic_cast<Ladder*>(newobj);
	Snake* s = dynamic_cast<Snake*>(newobj);

	if (l)
	{
		int newladderstart = l->GetPosition().VCell();
		int newladderend = l->GetEndPosition().VCell();
		if (this->GetPosition().HCell() == l->GetPosition().HCell())
		{
			for (int i = oldladderstart; i >= oldladderend; i--)
			{
				for (int j = newladderstart; j >= newladderend; j--)
				{
					if (i == j)
						return true;

				}
			}
		}

	}

	else if (s)
	{
		if ((s->GetPosition().VCell() == GetEndPosition().VCell()) && (s->GetPosition().HCell() == GetEndPosition().HCell()))
			return true;
	}
	else return false;

	return false;


}

Ladder::~Ladder()
{
}
