#include "SaveGridAction.h"
#include "Input.h"
#include "Output.h"
#include "GameObject.h"
#include"Grid.h"

SaveGridAction::SaveGridAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter the name of file to save in: ");
	Name=pIn->GetSrting(pOut)+".txt";
	pOut->ClearStatusBar();
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
	outputFile.open(Name);
	Grid* pGrid = pManager->GetGrid();
	outputFile<<pGrid->count(ladder)<<endl;
	pGrid->SaveAll(outputFile, ladder);
	outputFile<<pGrid->count(snake)<<endl;
	pGrid->SaveAll(outputFile, snake);
	outputFile << pGrid->count(card)<<endl;
	pGrid->SaveAll(outputFile, card);
	outputFile.close();
}

SaveGridAction:: ~SaveGridAction()
{
}