#pragma once
#include "VectorCarro.h"

class Juego
{
private:
	VCarros* arrC;
	int tiempoTranscurrido;
public:
	Juego()
	{
		arrC = new VCarros();
		tiempoTranscurrido = 0;
	}

	~Juego()
	{
		delete arrC;
	}

	void agregarCarros(bool carrera, Graphics^ gr) {
		if (carrera == true) {
			int dy = 0;
			arrC->agregarCarro(new Carro1(50,100,0));
			arrC->agregarCarro(new Carro2(50,200,0));
			arrC->agregarCarro(new Carro3(50,300,0));

		}
		else if (carrera == false) {
			Random r;
			arrC->agregarCarro(new Carro1(r.Next(700),r.Next(399), r.Next(15)));
			arrC->agregarCarro(new Carro2(r.Next(700),r.Next(399), r.Next(15)));
			arrC->agregarCarro(new Carro3(r.Next(700),r.Next(399), r.Next(15)));
		}
	}


	bool mover_todo(Graphics^ gr, int meta) {
		arrC->moverTodo(gr);
		return arrC->ganoCarrera(meta);  
	}
	void actualizarJuego(Graphics^ gr) {
	/*	if (carrera ==false) {
			arrC->mover__Todo(gr);
		}*/
		tiempoTranscurrido++;
		if (tiempoTranscurrido == 200 && arrC->getContadorCarros() < 20) {
			tiempoTranscurrido = 0;
					int tipo = 1 + rand() % 3;
				switch (tipo)
				{case 1:
					arrC->agregarCarro(new Carro1(1+ rand() % 500, 1+ rand() % 300, rand() % 3 + 1));
					break;
				case 2: 
					arrC->agregarCarro(new Carro2(1 + rand() % 500, 1 + rand() % 300, rand() % 3 + 1));
					break;
				case 3:
					arrC->agregarCarro(new Carro3(1 + rand() % 500, 1 + rand() % 300, rand() % 3 + 1));
					break;
				}
		}
		arrC->moverTodo(gr);
		//else {
		//	tiempoTranscurrido++;
		//	if (tiempoTranscurrido >=  && arrC->getContadorCarros() < 20) {
		//		tiempoTranscurrido = 0;
		//		int tipo = 1 + rand() % 3;
		//		switch (tipo)
		//		{case 1:
		//			arrC->agregarCarro(new Carro1(rand() % 500, rand() % 400, rand() % 3 + 1));
		//			break;
		//		case 2: 
		//			arrC->agregarCarro(new Carro2(rand() % 500, rand() % 400, rand() % 3 + 1));
		//			break;
		//		case 3:
		//			arrC->agregarCarro(new Carro3(rand() % 500, rand() % 400, rand() % 3 + 1));
		//			break;
		//		default:
		//			break;
		//		}
		//	/*	arrC->agregarCarro(rand() % 500, rand() % 400, rand() % 3 + 1);*/
		//	}
		//	arrC->moverTodo(gr);
		//}
	}
};
