#pragma once
#include"Controlador.h"

namespace GameJam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Carrera
	/// </summary>
	public ref class Carrera : public System::Windows::Forms::Form
	{
	public:
		Carrera(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			juego = new Juego();
			gr = this->CreateGraphics();
			carrera = true;
			tiempoTranscurrido = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Carrera()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Juego* juego;
		Graphics^ gr;
		float tiempoTranscurrido;
		bool carrera;
	private: System::Windows::Forms::Label^ label1;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = false;
			   this->timer1->Tick += gcnew System::EventHandler(this, &Carrera::timer1_Tick);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(308, 54);
			   this->label1->Name = L"label1";
			   this->label1->BackColor = Color::White;
			   this->label1->Size = System::Drawing::Size(262, 16);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Presione \"A\" para que comience la carrera";

			   // 
			   // Carrera
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(982, 453);
			   this->Controls->Add(this->label1);
			   this->Name = L"Carrera";
			   this->Text = L"Carrera";
			   this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Carrera::Carrera_Paint);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Carrera::Carrera_KeyDown);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		int meta = 600;
		tiempoTranscurrido += 1;
		label1->Text = "Tiempo: " + tiempoTranscurrido/10 + "s";
		if (juego->mover_todo(gr, meta)) {
			tiempoTranscurrido++;
			timer1->Enabled = false;  // Detener el Timer
			label1->Text = "Carrera finalizada! Un carro ha llegado a la meta en " + tiempoTranscurrido/10 + " segundos.";
			timer1->Stop();

		}
		

	}
	private: System::Void Carrera_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		gr->Clear(Color::White);
		Pen^ lapicero = gcnew Pen(Color::Black, 5);
		gr->DrawLine(lapicero, 600, 1, 600, 500);

	}
	private: System::Void Carrera_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::A) {
			juego->agregarCarros(carrera, gr);
			timer1->Enabled = true;
		}
	}
	};
}
