#pragma once

#include "Action.h"

class AddCircleAction : public Action {


private :
	Point P1, P2;
	GfxInfo CircleGfxInfo;
	int ID;
public :
	AddCircleAction(ApplicationManager* pApp);
	Action* clone() const { return new AddCircleAction(*this); }

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual void undo();
	virtual void redo();

};
