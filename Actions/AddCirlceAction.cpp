#include "AddCircleAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager * pApp):Action(pApp)
{
	UndoValidity = true;//this action is undoable
	Recordable = true;
}

void AddCircleAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetSoundState())
	{
		PlaySound("Circle.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	pOut->PrintMessage("New Circle: Click at the center");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->getValidDrawPoint(P1);
	
	pOut->PrintMessage("New Circle: Click at The Desired Radius");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->getValidDrawPoint(P2);

	CircleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircleAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CCircle*R=new CCircle(P1, P2, CircleGfxInfo);

	//Add the rectangle to the list of figures
	ID = pManager->AddFigure(R);
	R->SetId(ID);
}

void AddCircleAction::undo()
{
	Output* pOut = pManager->GetOutput();
	pManager->DeleteFigure(ID);//in the undo of this acction we delete the figure
	pOut->PrintMessage("the add circle action is undoed ");
	
}

void AddCircleAction::redo()
{
	Output* pOut = pManager->GetOutput();
	CCircle* R = new CCircle(P1, P2, CircleGfxInfo);//in the redo of this action we return the circle with its info
	R->SetId(ID);       //(the same id of the circle before undoing)      
	pManager->AddFigure(R); //adding the figure to the fig list
	pOut->PrintMessage("the add circle action is redoed ");
}