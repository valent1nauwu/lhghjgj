#pragma once
#include "Carrera.h"
#include "GeneraciónAutomática.h"

namespace GameJam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbl_menuPrincipal;
	private: System::Windows::Forms::Button^ btn_Carrera;
	private: System::Windows::Forms::Button^ btn_generacionAutomatica;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


	private: System::ComponentModel::IContainer^ components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbl_menuPrincipal = (gcnew System::Windows::Forms::Label());
			this->btn_Carrera = (gcnew System::Windows::Forms::Button());
			this->btn_generacionAutomatica = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbl_menuPrincipal
			// 
			this->lbl_menuPrincipal->AutoSize = true;
			this->lbl_menuPrincipal->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_menuPrincipal->Location = System::Drawing::Point(118, 47);
			this->lbl_menuPrincipal->Name = L"lbl_menuPrincipal";
			this->lbl_menuPrincipal->Size = System::Drawing::Size(501, 72);
			this->lbl_menuPrincipal->TabIndex = 0;
			this->lbl_menuPrincipal->Text = L"Menu Principal";
			this->lbl_menuPrincipal->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_Carrera
			// 
			this->btn_Carrera->Font = (gcnew System::Drawing::Font(L"Yu Gothic Medium", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Carrera->Location = System::Drawing::Point(115, 181);
			this->btn_Carrera->Name = L"btn_Carrera";
			this->btn_Carrera->Size = System::Drawing::Size(250, 75);
			this->btn_Carrera->TabIndex = 1;
			this->btn_Carrera->Text = L"Carrera\r\n";
			this->btn_Carrera->UseVisualStyleBackColor = true;
			this->btn_Carrera->Click += gcnew System::EventHandler(this, &MenuPrincipal::btn_Carrera_Click);
			// 
			// btn_generacionAutomatica
			// 
			this->btn_generacionAutomatica->Font = (gcnew System::Drawing::Font(L"Yu Gothic Medium", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn_generacionAutomatica->Location = System::Drawing::Point(412, 181);
			this->btn_generacionAutomatica->Name = L"btn_generacionAutomatica";
			this->btn_generacionAutomatica->Size = System::Drawing::Size(250, 75);
			this->btn_generacionAutomatica->TabIndex = 2;
			this->btn_generacionAutomatica->Text = L"Generación Automática de Carrtitos";
			this->btn_generacionAutomatica->UseVisualStyleBackColor = true;
			this->btn_generacionAutomatica->Click += gcnew System::EventHandler(this, &MenuPrincipal::btn_generacionAutomatica_Click);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 353);
			this->Controls->Add(this->btn_generacionAutomatica);
			this->Controls->Add(this->btn_Carrera);
			this->Controls->Add(this->lbl_menuPrincipal);
			this->Name = L"MenuPrincipal";
			this->Text = L"MenuPrincipal";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_Carrera_Click(System::Object^ sender, System::EventArgs^ e) {
		Carrera^ frm2 = gcnew Carrera();
		frm2->ShowDialog();

	}
private: System::Void btn_generacionAutomatica_Click(System::Object^ sender, System::EventArgs^ e) {
	GeneraciónAutomática^ frm3 = gcnew GeneraciónAutomática();
	frm3->ShowDialog();
}
};
}
