#pragma once
#include "Controlador.h"

namespace GameJam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GeneraciónAutomática
	/// </summary>
	public ref class GeneraciónAutomática : public System::Windows::Forms::Form
	{
	public:
		GeneraciónAutomática(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			gr = this->CreateGraphics();
			juego = new Juego();
			carrera = false;
			tiempoRestante = 200;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GeneraciónAutomática()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Graphics^ gr;
		Juego* juego;
		bool carrera;
		float tiempoRestante;
	public: System::Windows::Forms::Timer^ timer1;
	private:

	private: System::Windows::Forms::Label^ lbl_timer;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lbl_timer = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tag = L"Timer";
			this->timer1->Tick += gcnew System::EventHandler(this, &GeneraciónAutomática::timer1_Tick);
			// 
			// lbl_timer
			// 
			this->lbl_timer->AutoSize = true;
			this->lbl_timer->Location = System::Drawing::Point(37, 13);
			this->lbl_timer->Name = L"lbl_timer";
			this->lbl_timer->Size = System::Drawing::Size(42, 16);
			this->lbl_timer->TabIndex = 0;
			this->lbl_timer->Text = L"Presione 'Enter' para comenzar";
			// 
			// GeneraciónAutomática
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 453);
			this->Controls->Add(this->lbl_timer);
			this->Name = L"GeneraciónAutomática";
			this->Text = L"GeneraciónAutomática";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GeneraciónAutomática::GeneraciónAutomática_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GeneraciónAutomática::GeneraciónAutomática_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GeneraciónAutomática_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		gr->Clear(Color::White);
		
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		if (tiempoRestante > 0) {
			tiempoRestante--;
		}
		else {
			tiempoRestante = 200;
		}
		lbl_timer->Text = "Timer: " + tiempoRestante/10 + "s";
		juego->actualizarJuego(gr);

	}
	private: System::Void GeneraciónAutomática_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter) {
			juego->agregarCarros(carrera, gr);
			timer1->Enabled = true;

		}
	}
	};
}
