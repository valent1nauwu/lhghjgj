#pragma once
#include "Header.h"

class Carro
{
protected:
	int x, y, dx,dy, ancho, alto;

public:
	Carro(int x, int y,int dy)
	{
		this->x = x;
		this->y = y;
		this->dy = dy;
		this->dx = 1 + rand() % 15;
		this->ancho = 60;
		this->alto = 40;
	}
	~Carro(){}
	int getX() { return this->x; };
	int getY() { return this->y; };
	int getDx() { return this->dx; }
	void setDx(int dx) { this->dx = dx; }

	Rectangle getRectangle() { return Rectangle(x, y, ancho, alto); }

	void mover(Graphics^ gr) {
			borrar(gr);
			if (x + dx < 0 || x + dx + ancho > gr->VisibleClipBounds.Width) dx *= -1;		
			if (y + dy < 0 || y + dy + alto > gr->VisibleClipBounds.Height) dy *= -1; 
			x += dx;
			y += dy;
			dibujar(gr);
	}
	void borrar(Graphics^ gr) {
		Pen^ pen = gcnew Pen(Color::White, 2);
		SolidBrush^ brush = gcnew SolidBrush(Color::White);
		gr->FillRectangle(brush, x, y, 60, 30);
		gr->FillRectangle(gcnew SolidBrush(Color::White), x + 15, y + 5, 30, 10);
		gr->FillEllipse(brush, x + 10, y + 25, 10, 10);
		gr->FillEllipse(brush, x + 40, y + 25, 10, 10);
	}

	virtual void dibujar(Graphics^ gr) {}
	
};
