#pragma once
#include "TableClass.h"
namespace BazaOkno {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для OwnerAuto
	/// </summary>
	public ref class OwnerAuto : public System::Windows::Forms::Form
	{
	public:
		Changeow *cch;
		Owner1 *oo;
		Car *cc;
	private: System::Windows::Forms::Label^  label1;
	public:
		int id;
		OwnerAuto(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		OwnerAuto(Changeow *ch, Owner1 *o, Car *c,Car *d)
		{
			this->cc = c;
			this->oo = o;
			this->cch = ch;
			InitializeComponent();
			this->textBox1->Text = gcnew String(gcnew String(cc->data.currentmodel) + " " + gcnew String(cc->data.platecar));
			DataTable ^table;
			DataColumn ^column;
			DataRow ^row;
			table = gcnew DataTable();
			String^ nameFirstColumn = "Владелец";
			String^ nameSecondColumn = "Дата покупки";
			column = gcnew DataColumn(nameFirstColumn, String::typeid);
			table->Columns->Add(column);
			column = gcnew DataColumn(nameSecondColumn, String::typeid);
			table->Columns->Add(column);
			id = cc->data.id;
			cch = cch->carowners(cch, id);
			if (cch != NULL)
			{
				Changeow *cg = cch;
				while (cg != NULL)
				{
					row = table->NewRow();
					row[nameFirstColumn] = gcnew String(gcnew String(cg->data.idow->data.surname) + " " + gcnew String(cg->data.idow->data.name1) + " " + gcnew String(cg->data.idow->data.patronymic));
					row[nameSecondColumn] = cg->data.day.ToString() + "." + cg->data.month.ToString() + "." + cg->data.year.ToString();
					table->Rows->Add(row);
					cg = cg->next;
				}
				//cch->changeowwrf("Result1.txt", cch);
				cch->outputfile(cch, "Result1.txt");
				dataGridView1->DataSource = table;
			}
			cch = cch->changeowr("Changeowner1.txt", oo,d);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~OwnerAuto()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(16, 134);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(629, 299);
			this->dataGridView1->TabIndex = 0;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(221, 57);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(273, 22);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(32, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Автомобиль";
			// 
			// OwnerAuto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(658, 446);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"OwnerAuto";
			this->Text = L"Владельцы автомобиля";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
