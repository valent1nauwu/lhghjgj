#pragma once
#include "Carro.h"

class Carro3 : public Carro {
private:
	int R, G, B;
public:
    Carro3(int x, int y, int dy) : Carro(x, y, dy) {
		Random r;
		this->R = r.Next(255);
		this->G = r.Next(255);
		this->B = r.Next(255);
	}

    ~Carro3() {}

	virtual void dibujar(Graphics^ gr) {
		Pen^ pen = gcnew Pen(Color::FromArgb(R,G,B),2);
		SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(R, G, B));
		gr->FillRectangle(brush, x, y, 60, 30);
		gr->FillRectangle(gcnew SolidBrush(Color::LightGray), x + 15, y + 5, 30, 10);
		gr->FillEllipse(brush, x + 10, y + 25, 10, 10);
		gr->FillEllipse(brush, x + 40, y + 25, 10, 10);
	}
};