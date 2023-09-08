
#pragma once
#include "TableClass.h"
#include "Cars.h"
#include "Ownerform.h"
#include "Changeownerform.h"
#include "Finesform.h"
#include <fstream>

namespace BazaOkno {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Models *models;
		Owner1 *owner;
		Car *cars;
		Typesfine *types;
		Fine *fine;
		Fine *fine1;
		Changeow *change;
		Changeow *result;
		MyForm(void)
		{
			InitializeComponent();
			models = NULL;
			owner = NULL;
			cars = NULL;
			types = NULL;
			fine = NULL;
			fine1 = NULL;
			change = NULL;
			models = models->inputfile(models, "Models.txt");
			owner = owner->inputfile(owner, "Owners.txt");
			cars = cars->Carreadf("Cars.txt",models, owner);
			types = types->inputfile(types, "Types.txt");
			fine = fine->Finereadf("Fines.txt", cars, owner, types);
			fine1 = fine1->Finereadf("Fines.txt", cars, owner, types);
			change = change->changeowr("Changeowner1.txt", owner, cars);
			result->lastcarowner(change, cars, "Changeowner1.txt", owner);
			change = change->changeowr("Changeowner1.txt", owner, cars);
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;







	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(33, 54);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(408, 73);
			this->button1->TabIndex = 2;
			this->button1->Text = L"¬ладельцы";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(33, 155);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(408, 70);
			this->button2->TabIndex = 3;
			this->button2->Text = L"јвтомобили";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(33, 261);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(408, 82);
			this->button3->TabIndex = 4;
			this->button3->Text = L"—мена владельца авто";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(32, 375);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(409, 76);
			this->button4->TabIndex = 5;
			this->button4->Text = L"¬нести информацию о штрафе";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(485, 489);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"јвтомобили и владельцы";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void заполнить“аблицу»з‘айлаToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	Ownerform ^owner_form = gcnew Ownerform(owner,cars,change);
	owner_form->Show();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	Cars ^cars_form = gcnew Cars(cars,models,owner,fine,types,change);
	cars_form->Show();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	Changeownerform ^change_form = gcnew Changeownerform(cars,owner,change);
	change_form->Show();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	Finesform ^fines_form = gcnew Finesform(cars,owner,types,fine);
	fines_form->Show();
}

};
}
