#include "CCircle.h"
#include <cmath>
#include <fstream>
int CCircle::CircCount = 0;
int CCircle::GetCircCount()
{
	return CircCount;
}
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	this->P1= P1;
	this->P2 = P2;
	CircCount++;
}
CCircle::CCircle(int id) : CFigure(id) {}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawCircle(P1, P2, FigGfxInfo, Selected);
}

bool CCircle::PointBelong(int x, int y)
{
	float Radius = sqrt(pow((P1.x) - (P2.x), 2) + pow((P1.y) - (P2.y), 2));

	x -= P1.x;
	y -= P1.y;

	if ((float)(pow(x, 2) + pow(y, 2)) <= (float)pow(Radius, 2))
		return true;
	return false;
}

void CCircle::Move(Point NewLocation)
{
	double DiffrenceX = NewLocation.x - P1.x;
	double DiffrenceY = NewLocation.y - P1.y;
	P1.x = NewLocation.x;
	P1.y = NewLocation.y;
	P2.x += DiffrenceX;
	P2.y += DiffrenceY;

	


}

string CCircle::GetName() const {
	return "CIRC";
}


void CCircle::Save(ofstream &file) {
	SavePoint(file, P1);
	SavePoint(file, P2);
	CFigure::Save(file);
}

void CCircle::Load(ifstream& file) {
	LoadPoint(file, P1);
	LoadPoint(file, P2);
	CFigure::Load(file);
}

CCircle::~CCircle()
{
	CircCount--;
}
