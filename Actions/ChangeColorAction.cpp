#include "ChangeColorAction.h"

#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"








ChangeColorAction::ChangeColorAction(ApplicationManager* pApp, ActionType TheColor) :Action(pApp)
{
	
	
	switch (TheColor)
	{
	case DRW_Red:
		SelectedColor = RED;
		ColorName = "Red";
		break;
	case DRW_Orange:
		SelectedColor = ORANGE;
		ColorName = "Orange";
		break;
	case DRW_Blue:
		SelectedColor = BLUE;
		ColorName = "Blue";
		break;
	case DRW_Yellow:
		SelectedColor = YELLOW;
		ColorName = "Yellow";
		break;
	case DRW_Green:
		SelectedColor = GREEN;
		ColorName = "Green";
		break;
	case DRW_Black:
		SelectedColor = BLACK;
		ColorName = "Black";
		break;
	default:
		break;
	}
	UndoValidity = false;
}

void ChangeColorAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	pOut->PrintMessage("Change the default drawing color to: " + ColorName);

}



void ChangeColorAction::Execute()
{
	ReadActionParameters();
	lastSelectedColor = UI.DrawColor;
	
	UI.DrawColor = SelectedColor;
	SetActionState(true);

}

void ChangeColorAction::undo()
{
	Output* pOut = pManager->GetOutput();
	

	UI.DrawColor = lastSelectedColor;
	pOut->PrintMessage(" ");
	SetActionState(false);
}
