#include "OpenGridAction.h"
#include "Input.h"
#include "Output.h"
#include "GameObject.h"
#include"Grid.h"
#include"Ladder.h"
#include"Card.h"
#include"Snake.h"
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

OpenGridAction::OpenGridAction(ApplicationManager* pApp):Action(pApp)
{
}

void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter the name of file to open it: ");
	Name = pIn->GetSrting(pOut) + ".txt";
	pOut->ClearStatusBar();
}

void OpenGridAction::Execute()
{
	int x, y;
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int num,cardnum;
	GameObject* pObj;
	pGrid->ClearAll();
	inputFile.open(Name);
	if (inputFile.is_open())
	{
		inputFile >> num;
		for (int i = 1; i <= num; i++)
		{
			pObj = new Ladder(0, 0);
			pObj->Load(inputFile);
			pGrid->AddObjectToCell(pObj);
		}
		inputFile >> num;
		for (int i = 1; i <= num; i++)
		{
			pObj = new Snake(0, 0);
			pObj->Load(inputFile);
			pGrid->AddObjectToCell(pObj);
		}
		inputFile >> num;
		for (int i = 1; i <= num; i++)
		{
			inputFile >> cardnum;
			switch (cardnum)
			{
			case 1:
				pObj = new CardOne(0);
				pObj->Load(inputFile);
				pGrid->AddObjectToCell(pObj);
				break;
			case 2:
				pObj = new CardTwo(0);
				pObj->Load(inputFile);
				pGrid->AddObjectToCell(pObj);
				break;
			case 3:
				pObj = new CardThree(0);
				pObj->Load(inputFile);
				pGrid->AddObjectToCell(pObj);
				break;
			case 4:
				pObj = new CardFour(0);
				pObj->Load(inputFile);
				pGrid->AddObjectToCell(pObj);
				break;
			case 5:
				pObj = new CardFive(0);
				pObj->Load(inputFile);
				pGrid->AddObjectToCell(pObj);
				break;
			case 6:
				pObj = new CardSix(0);
				pObj->Load(inputFile);
				pGrid->AddObjectToCell(pObj);
				break;
			case 7:
				pObj = new CardSeven(0);
				pObj->Load(inputFile);
				pGrid->AddObjectToCell(pObj);
				break;
			case 8:
				pObj = new CardEight(0);
				pObj->Load(inputFile);
				pGrid->AddObjectToCell(pObj);
				break;
			case 9:
				pObj = new CardNine(0);
				pObj->Load(inputFile);
				pGrid->AddObjectToCell(pObj);
				break;
			case 10:
				pObj = new CardTen(0);
				pObj->Load(inputFile);
				pGrid->AddObjectToCell(pObj);
				break;
			case 11:
				pObj = new CardEleven(0);
				pObj->Load(inputFile);
				pGrid->AddObjectToCell(pObj);
				break;
			case 12:
				pObj = new CardTwelve(0);
				pObj->Load(inputFile);
				pGrid->AddObjectToCell(pObj);
				break;
			}
		}
		inputFile.close();
	}
	else
	{
		pGrid->PrintErrorMessage("File Does Not Exist!. Click to continue ... ");
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
		return;
	}
}

OpenGridAction::~OpenGridAction()
{
}
