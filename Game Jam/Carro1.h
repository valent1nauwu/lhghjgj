#pragma once
#include "Carro.h"

class Carro1 : public Carro
{
private:

public:
	Carro1(int x, int y, int dy) : Carro (x,y,dy) {}
	~Carro1(){}
	virtual void dibujar(Graphics^gr) {
		Pen^ pen = gcnew Pen(Color::Black, 2);
		SolidBrush^ brush = gcnew SolidBrush(Color::Black);
		gr->FillRectangle(brush, x, y, 60, 30);
		gr->FillRectangle(gcnew SolidBrush(Color::LightGray), x + 15, y + 5, 30, 10);
		gr->FillEllipse(brush, x + 10, y + 25, 10, 10);
		gr->FillEllipse(brush, x + 40, y + 25, 10, 10);
	}
};
