#pragma once

namespace BazaOkno {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для HumanCars
	/// </summary>
	public ref class HumanCars : public System::Windows::Forms::Form
	{
	public:
		Changeow *cch;
		Car *cc;
		Owner1 *oo;
	private: System::Windows::Forms::Label^  label1;
	public:
		int id;
		HumanCars(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		HumanCars(Changeow *ch, Car *c, Owner1 *o, Owner1 *g)
		{
			this->cch = ch;
			this->cc = c;
			this->oo = o;
			InitializeComponent();
			this->textBox1->Text = gcnew String(gcnew String(oo->data.surname) + " " + gcnew String(oo->data.name1) + " " + gcnew String(oo->data.patronymic));
			DataTable ^table;
			DataColumn ^column;
			DataRow ^row;
			table = gcnew DataTable();
			String^ nameFirstColumn = "Автомобиль";
			String^ nameSecondColumn = "Дата покупки";
			column = gcnew DataColumn(nameFirstColumn, String::typeid);
			table->Columns->Add(column);
			column = gcnew DataColumn(nameSecondColumn, String::typeid);
			table->Columns->Add(column);
			id = oo->data.id;
			cch = cch->humancars(cch, id);
			Changeow *f = cch;
			while (f!= NULL)
			{
				row = table->NewRow();
				row[nameFirstColumn] = gcnew String(gcnew String(f->data.idcar->data.currentmodel)+" "+ gcnew String (f->data.idcar->data.platecar));
				row[nameSecondColumn] = f->data.day.ToString()+"."+f->data.month.ToString()+"."+f->data.year.ToString();
				table->Rows->Add(row);
				f = f->next;
			}
			//cch->changeowwrf("Result2.txt", cch);
			cch->outputfile(cch, "Result2.txt");
			dataGridView1->DataSource = table;
			cch = cch->changeowr("Changeowner1.txt", g, cc);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~HumanCars()
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
			this->dataGridView1->Location = System::Drawing::Point(16, 135);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(575, 359);
			this->dataGridView1->TabIndex = 0;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(192, 59);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(238, 22);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(40, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Владелец";
			// 
			// HumanCars
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(604, 507);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"HumanCars";
			this->Text = L"Автомобили человека";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
