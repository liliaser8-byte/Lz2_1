#pragma once

namespace Lz2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
    private: System::Windows::Forms::ComboBox^ comboBox1;
    protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            this->listBox1 = (gcnew System::Windows::Forms::ListBox());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->SuspendLayout();
            // 
            // listBox1
            // 
            this->listBox1->FormattingEnabled = true;
            this->listBox1->ItemHeight = 16;
            this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
                L"0 Лінія", L"1 Прямокутник", L"2 Зафарбований прямокутник",
                    L"3 Еліпс", L"4 Зафарбований еліпс", L"5 Сектор", L"6 Зірка", L"7 Трикутник ", L"8 Будинок"
            });
            this->listBox1->Location = System::Drawing::Point(397, 60);
            this->listBox1->Name = L"listBox1";
            this->listBox1->Size = System::Drawing::Size(247, 164);
            this->listBox1->TabIndex = 0;
            this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
            // 
            // comboBox1
            // 
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Червоний", L"Зелений", L"Синій", L"Жовтий", L"Чорний" });
            this->comboBox1->Location = System::Drawing::Point(397, 266);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(121, 24);
            this->comboBox1->TabIndex = 1;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(764, 478);
            this->Controls->Add(this->comboBox1);
            this->Controls->Add(this->listBox1);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->ResumeLayout(false);

        }
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        Graphics^ graf = CreateGraphics();
        graf->Clear(Color::White);


        Color userColor = Color::Black;

        if (comboBox1->SelectedItem != nullptr) {
            String^ colorName = comboBox1->SelectedItem->ToString();
            if (colorName == "Червоний") userColor = Color::Red;
            else if (colorName == "Зелений") userColor = Color::Green;
            else if (colorName == "Синій") userColor = Color::Blue;
            else if (colorName == "Блакитний") userColor = Color::LightBlue;
            else if (colorName == "Жовтий") userColor = Color::Yellow;
            else if (colorName == "Чорний") userColor = Color::Black;
        }


        Pen^ userPen = gcnew System::Drawing::Pen(userColor, 3);
        Brush^ userBrush = gcnew System::Drawing::SolidBrush(userColor);


        switch (listBox1->SelectedIndex)
        {
        case 0: graf->DrawLine(gcnew Pen(Color::Green, 8), 50, 40, 250, 160);
            break;

        case 1:  graf->DrawRectangle(gcnew Pen(Color::Red, 3), 40, 40, 150, 80);
            break;

        case 2: graf->FillRectangle(userBrush, 40, 40, 150, 80);
            break;

        case 3: graf->DrawEllipse(userPen, 40, 40, 200, 140);
            break;

        case 4: graf->FillEllipse(Brushes::LightBlue, 40, 40, 200, 140);
            break;

        case 5: graf->FillPie(userBrush, 40, 40, 200, 200, 180, 90);
            break;

        case 6: 
        {
            cli::array<Point>^ starPoints = gcnew cli::array<Point>{
                Point(120, 30), Point(145, 100), Point(215, 100),
                    Point(155, 150), Point(180, 230), Point(120, 180),
                    Point(60, 230), Point(85, 150), Point(25, 100), Point(95, 100)
            };
            graf->FillPolygon(Brushes::Yellow, starPoints);
            graf->DrawPolygon(Pens::Yellow, starPoints);
        }
        break;

        case 7: 
        {
            cli::array<Point>^ triangle = gcnew cli::array<Point>{
                Point(150, 40),   
                    Point(50, 200),   
                    Point(250, 200)   
            };

            graf->DrawPolygon(userPen, triangle);
        }
        break;

        case 8: 
        {
           
            Pen^ pen = gcnew Pen(Color::Black, 2);

            graf->DrawRectangle(pen, 100, 150, 160, 120);

            cli::array<Point>^ roof = gcnew cli::array<Point>{
                Point(80, 150), 
                    Point(180, 70), 
                    Point(280, 150) 
            };
            graf->DrawPolygon(pen, roof);

            graf->DrawRectangle(pen, 150, 190, 40, 80);
        }
        break;
        }
	}
	};
}
