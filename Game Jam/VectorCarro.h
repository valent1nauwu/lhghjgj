#pragma once
#include "Carro1.h"
#include "Carro2.h"
#include "Carro3.h"

class VCarros
{
private:

	vector <Carro*>* arrC;
	int contadorCarros;
public:
	VCarros()
	{
		arrC = new vector <Carro*>();
		this->contadorCarros = 0;
	}

	~VCarros()
	{
		delete[] arrC;
	}

	void agregarCarro(Carro* obj) {
		arrC->push_back(obj);
		contadorCarros++;
	}
	void eliminarCarro() {
		for (int i = 0; i < arrC->size(); i++) {
			arrC->erase(arrC->begin() + i);
		}
	}
	void moverTodo(Graphics^ gr) {
		for (int i = 0; i < arrC->size(); i++) {
			SolidBrush^ brush = gcnew SolidBrush(Color::Cyan);
			gr->FillEllipse(brush, 50, 50, 60, 30);
			for (int i = 0; i < arrC->size(); i++) {
				for (int j = i + 1; j < arrC->size(); j++) {

					// Verifica si los rectángulos de los carros colisionan
					if (arrC->at(i)->getRectangle().IntersectsWith(arrC->at(j)->getRectangle())) {


						// Chocan Carro 3 con Carro 2 -> eliminar ambos
						if ((dynamic_cast<Carro3*>(arrC->at(i)) && dynamic_cast<Carro2*>(arrC->at(j))) ||
							(dynamic_cast<Carro2*>(arrC->at(i)) && dynamic_cast<Carro3*>(arrC->at(j)))) {
							delete arrC->at(i);
							delete arrC->at(j);
							// Borramos el carro con el índice más alto primero
							if (i > j) {
								arrC->erase(arrC->begin() + i); // Borrar el primero (mayor índice)
								arrC->erase(arrC->begin() + j); // Borrar el segundo
							}
							else {
								arrC->erase(arrC->begin() + j); // Borrar el segundo (menor índice)
								arrC->erase(arrC->begin() + i); // Borrar el primero
							}
							contadorCarros -= 2;
						}
						// Chocan Carro 3 con Carro 1 -> invertir dirección
						else if ((dynamic_cast<Carro3*>(arrC->at(i)) && dynamic_cast<Carro1*>(arrC->at(j))) ||
							(dynamic_cast<Carro1*>(arrC->at(i)) && dynamic_cast<Carro3*>(arrC->at(j)))) {

							arrC->at(i)->setDx(-arrC->at(i)->getDx()); // Invertir dirección del carro 3
							arrC->at(j)->setDx(-arrC->at(j)->getDx()); // Invertir dirección del carro 1
						}
						// Chocan Carro 2 con Carro 1 o viceversa -> generar nuevo Carro1
						else if ((dynamic_cast<Carro2*>(arrC->at(i)) && dynamic_cast<Carro1*>(arrC->at(j))) ||
							(dynamic_cast<Carro1*>(arrC->at(i)) && dynamic_cast<Carro2*>(arrC->at(j)))) {

							arrC->push_back(new Carro1(rand() % 500, rand() % 400, rand() % 3 + 1));
							contadorCarros++;
						}
					}
				}
			}
				arrC->at(i)->mover(gr);
		}
		
	}
	bool ganoCarrera(int meta) {
		for (int i = 0; i < arrC->size(); i++) {
			if (arrC->at(i)->getX() >= meta) {
				return true;  
			}
		}
		return false;
	}

	void mover__Todo(Graphics^ gr) {
		for (int i = 0; i < arrC->size(); i++) {
			arrC->at(i)->mover(gr);
		}
		/*verificarColisiones();*/
	}

	int getContadorCarros() { return this->contadorCarros; }

};
