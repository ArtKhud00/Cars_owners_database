#pragma once
#include "TableClass.h"
#include "FinesAuto.h"
#include "OwnerAuto.h"
#include "CarADD.h"
namespace BazaOkno {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Cars
	/// </summary>
	public ref class Cars : public System::Windows::Forms::Form
	{
	public:
		Car *cc;
		Car *k;
		Models *mm;
		Fine *ff;
		Typesfine *tt;
		Changeow *cch;
		Owner1 *oo;
	private: System::Windows::Forms::Button^  button5;

	private: System::Windows::Forms::Button^  button6;

	public:
		
		Cars(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		Cars(Car *c,Models *m, Owner1 *o,Fine *f, Typesfine *t , Changeow *ch)
		{
			this->cc = c;
			this->k = c;
			this->mm = m;
			this->oo = o;
			this->ff = f;
			this->tt = t;
			this->cch = ch;
			InitializeComponent();
			Models *n = mm;
			while (n != NULL)
			{
				this->comboBox1->Items->Add(gcnew String(n->data.Model));
				n = n->next;
			}
			Owner1 *ow = oo;
			while (ow != NULL)
			{
				this->comboBox2->Items->Add(gcnew String(ow->data.surname) + " " + gcnew String(ow->data.name1) + " " + gcnew String(ow->data.patronymic));
				ow = ow->next;
			}
			Models *mod = mm;
			Owner1 *own = oo;
			this->textBox1->ReadOnly = true;
			this->textBox2->ReadOnly = true;
			this->textBox3->ReadOnly = true;
			this->textBox4->ReadOnly = true;
			this->textBox5->ReadOnly = true;
			
			this->comboBox1->Text = gcnew String(cc->data.idmodel->data.Model);
			this->comboBox2->Text = gcnew String(gcnew String(cc->data.id_current_owner->data.surname) + " " + gcnew String(cc->data.id_current_owner->data.name1) + " " + gcnew String(cc->data.id_current_owner->data.patronymic));
			this->textBox1->Text = System::Convert::ToString(cc->data.year_of_issue);
			this->textBox2->Text = gcnew String(cc->data.color);
			this->textBox3->Text = System::Convert::ToString(cc->data.enginepower);
			this->textBox4->Text = gcnew String(cc->data.platecar);
			this->textBox5->Text = gcnew String(cc->data.currentmodel);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Cars()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  comboBox1;
	protected:
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label8;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->AllowDrop = true;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(280, 96);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(160, 24);
			this->comboBox1->TabIndex = 0;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(280, 363);
			this->comboBox2->Margin = System::Windows::Forms::Padding(4);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(324, 24);
			this->comboBox2->TabIndex = 1;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(280, 191);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(105, 22);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(280, 277);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(105, 22);
			this->textBox2->TabIndex = 3;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(280, 320);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(81, 22);
			this->textBox3->TabIndex = 4;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(280, 234);
			this->textBox4->Margin = System::Windows::Forms::Padding(4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(132, 22);
			this->textBox4->TabIndex = 5;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(280, 144);
			this->textBox5->Margin = System::Windows::Forms::Padding(4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(132, 22);
			this->textBox5->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(36, 97);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(190, 25);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Марка автомобиля";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(36, 142);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(205, 25);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Модель автомобиля";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(36, 188);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(126, 25);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Год выпуска";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(36, 234);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(116, 25);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Гос. номер";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(36, 274);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(59, 25);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Цвет";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(36, 318);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(110, 25);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Мощность";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(36, 361);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(104, 25);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Владелец";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(297, 464);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(72, 62);
			this->button1->TabIndex = 14;
			this->button1->Text = L"<--";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Cars::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(403, 464);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(72, 62);
			this->button2->TabIndex = 15;
			this->button2->Text = L"-->";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Cars::button2_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(27, 469);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(215, 57);
			this->button4->TabIndex = 17;
			this->button4->Text = L"Добавить запись";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Cars::button4_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(32, 11);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(272, 52);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Автомобиль";
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(601, 69);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(152, 71);
			this->button5->TabIndex = 19;
			this->button5->Text = L"Штрафы на авто";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Cars::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(601, 164);
			this->button6->Margin = System::Windows::Forms::Padding(4);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(152, 73);
			this->button6->TabIndex = 21;
			this->button6->Text = L"Владельцы авто";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Cars::button6_Click);
			// 
			// Cars
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(779, 545);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Cars";
			this->Text = L"Автомобили";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (cc->next != NULL)
	{
		button1->Visible = true;
		button2->Visible = true;
		cc = cc->next;
		this->comboBox1->Text = gcnew String(cc->data.idmodel->data.Model);
		this->comboBox2->Text = gcnew String(gcnew String(cc->data.id_current_owner->data.surname) + " " + gcnew String(cc->data.id_current_owner->data.name1) + " " + gcnew String(cc->data.id_current_owner->data.patronymic));
		this->textBox1->Text = System::Convert::ToString(cc->data.year_of_issue);
		this->textBox2->Text = gcnew String(cc->data.color);
		this->textBox3->Text = System::Convert::ToString(cc->data.enginepower);
		this->textBox4->Text = gcnew String(cc->data.platecar);
		this->textBox5->Text = gcnew String(cc->data.currentmodel);
	}
	else
	{
		button2->Visible = false;
		button1->Visible = true;
	}
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (cc->prev != NULL)
	{
		button1->Visible = true;
		button2->Visible = true;
		cc = cc->prev;
		this->comboBox1->Text = gcnew String(cc->data.idmodel->data.Model);
		this->comboBox2->Text = gcnew String(gcnew String(cc->data.id_current_owner->data.surname) + " " + gcnew String(cc->data.id_current_owner->data.name1) + " " + gcnew String(cc->data.id_current_owner->data.patronymic));
		this->textBox1->Text = System::Convert::ToString(cc->data.year_of_issue);
		this->textBox2->Text = gcnew String(cc->data.color);
		this->textBox3->Text = System::Convert::ToString(cc->data.enginepower);
		this->textBox4->Text = gcnew String(cc->data.platecar);
		this->textBox5->Text = gcnew String(cc->data.currentmodel);
	}
	else
	{
		button1->Visible = false;
		button2->Visible = true;
	}
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	Car *cf;
	cf = k;
	ff = ff->Finereadf("Fines.txt", cf, oo, tt);
	cc = cc->search_id(cc, cc->data.id);
	FinesAuto ^otchet1 = gcnew FinesAuto(ff,tt,oo,cc,cf);
	otchet1->Show();
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	cch = cch->changeowr("Changeowner1.txt", oo, k);
	cc = cc->search_id(cc, cc->data.id);
	OwnerAuto ^otchet2 = gcnew OwnerAuto(cch,oo,cc,k);
	otchet2->Show();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	
	CarADD ^add = gcnew CarADD(k, oo, mm);
	add->Show();
}
};
}
