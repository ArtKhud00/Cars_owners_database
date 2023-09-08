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
	/// Сводка для FinesAuto
	/// </summary>
	public ref class FinesAuto : public System::Windows::Forms::Form
	{
	public:
		Fine *ff;
		Typesfine *tt;
		Owner1 *oo;
		Car *cc;
	private: System::Windows::Forms::Label^  label1;
	public:
		int id;
		FinesAuto(void)
		{
			InitializeComponent();
			/*dataGridView1->ColumnCount = 5;
			dataGridView1->RowCount = 2;
			dataGridView1->Columns[1]->HeaderCell->Value = "Вид штрафа";*/
			
			//
			//TODO: добавьте код конструктора
			//
		}
		FinesAuto(Fine *f, Typesfine *t, Owner1 *o, Car *c,Car *d)
		{
			this->ff = f;
			this->tt = t;
			this->oo = o;
			this->cc = c;
			InitializeComponent();
			this->textBox1->Text = gcnew String(gcnew String(cc->data.currentmodel)+" " + gcnew String(cc->data.platecar));
			DataTable ^table;
			DataColumn ^column;
			DataRow ^row;
			table = gcnew DataTable();
			String^ nameFirstColumn = "Вид штрафа";
			String^ nameSecondColumn = "Владелец";
			String^ nameThirdColumn = "Дата штрафа";
			String^ nameForthColumn = "Статус";
			column = gcnew DataColumn(nameFirstColumn, String::typeid);
			table->Columns->Add(column);
			column = gcnew DataColumn(nameSecondColumn, String::typeid);
			table->Columns->Add(column);
			column = gcnew DataColumn(nameThirdColumn, String::typeid);
			table->Columns->Add(column); 
			column = gcnew DataColumn(nameForthColumn, String::typeid);
			table->Columns->Add(column);
			id = cc->data.id;
			ff = ff->carfine(ff, id);
			if (ff != NULL)
			{
				Fine *fg = ff;
				while (fg != NULL)
				{
					row = table->NewRow();
					row[nameFirstColumn] = gcnew String(fg->data.idtype->data.typeoffine);
					row[nameSecondColumn] = gcnew String(gcnew String(fg->data.idowner->data.surname) + " " + gcnew String(fg->data.idowner->data.name1) + " " + gcnew String(fg->data.idowner->data.patronymic));
					row[nameThirdColumn] = fg->data.day.ToString() + "." + fg->data.month.ToString() + "." + fg->data.year.ToString();
					row[nameForthColumn] = gcnew String(fg->data.status);
					table->Rows->Add(row);
					fg = fg->next;
				}
				//ff->Finewritef("Result.txt", ff);
				ff->outputfile(ff, "Result.txt");
				dataGridView1->DataSource = table;
				//сделать вывод в поля таблицы
			}
			else
			{
				MessageBox::Show("Штрафы на автомобиле отсутствуют");
			}
			ff = ff->Finereadf("Fines.txt", d, oo, tt);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FinesAuto()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::DataGridView^  dataGridView1;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(191, 43);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(261, 22);
			this->textBox1->TabIndex = 0;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(13, 107);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(748, 262);
			this->dataGridView1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(35, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Автомобиль";
			//this->label1->Click += gcnew System::EventHandler(this, &FinesAuto::label1_Click);
			// 
			// FinesAuto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(774, 382);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"FinesAuto";
			this->Text = L"Штрафы на автомобиле";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	
};
}
