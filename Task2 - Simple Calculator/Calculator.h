#pragma once

#include <cmath>

namespace Calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Calculator
	/// </summary>
	public ref class Calculator : public System::Windows::Forms::Form
	{
	public:
		Calculator(void)
		{
			InitializeComponent();

			this->MaximizeBox = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Calculator()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ resultBox;


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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->resultBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(12, 129);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(162, 34);
			this->textBox1->TabIndex = 1;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Calculator::number_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(180, 129);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(83, 34);
			this->textBox2->TabIndex = 2;
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Calculator::operator_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 106);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Left operand";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(265, 106);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(113, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Right operand";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(176, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Operator";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(269, 129);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(162, 34);
			this->textBox3->TabIndex = 7;
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Calculator::number_KeyPress);
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(12, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(419, 72);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Calculator";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(180, 169);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(83, 33);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Evaluate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Calculator::button1_Click);
			// 
			// resultBox
			// 
			this->resultBox->BackColor = System::Drawing::Color::GhostWhite;
			this->resultBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->resultBox->Enabled = false;
			this->resultBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resultBox->Location = System::Drawing::Point(137, 208);
			this->resultBox->Name = L"resultBox";
			this->resultBox->Size = System::Drawing::Size(177, 30);
			this->resultBox->TabIndex = 10;
			this->resultBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Calculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(443, 253);
			this->Controls->Add(this->resultBox);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"Calculator";
			this->Text = L"Calculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void number_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
			TextBox^ textBox = dynamic_cast<TextBox^>(sender);
			
			// Disallow non-digit, non-backspace, and second decimal point entry
			if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '.' && e->KeyChar != 8)
				e->Handled = true;

			// Disallow a second decimal point
			if (e->KeyChar == '.' && textBox->Text->Contains("."))
				e->Handled = true;

			// Limit length to 16 characters
			if (textBox->Text->Length >= 16 && e->KeyChar != 8)
				e->Handled = true;
		}
		private: System::Void operator_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
			TextBox^ textBox = dynamic_cast<TextBox^>(sender);

			// Disallow input if text length is 0 or if the entered character is not an operator
			if (e->KeyChar != 8 && (textBox->Text->Length > 0 || !IsOperator(e->KeyChar)))
				e->Handled = true;
		}
		// Helper function to check if a character is an operator
		private: bool IsOperator(wchar_t c) {
			return c == '+' || c == '-' ||
				   c == '*' || c == '/' ||
				   c == '%' || c == '^';
		}
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			// Validate input before attempting evaluation
			if (!ValidateInput())
				return;
			
			// Parse and evaluate the expression
			double left = Double::Parse(textBox1->Text);
			char op = textBox2->Text[0];
			double right = Double::Parse(textBox3->Text);

			Evaluate(left, op, right);
		}
		private: bool ValidateInput(void) {
			// Validate left operand
			if (String::IsNullOrEmpty(textBox1->Text)) {
				MessageBox::Show("'Left operand' cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return false;
			}

			// Validate operator
			if (String::IsNullOrEmpty(textBox2->Text)) {
				MessageBox::Show("'Operator' cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return false;
			}

			// Validate right operand
			if (String::IsNullOrEmpty(textBox3->Text)) {
				MessageBox::Show("'Right operand' cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return false;
			}

			return true;
		}
		private: void Evaluate(double left, char op, double right) {
			double result = 0;
			switch (op) {
			case '+':
				result = left + right;
				break;
			case '-':
				result = left - right;
				break;
			case '*':
				result = left * right;
				break;
			case '/':
				result = left / right;
				break;
			case '%':
				result = fmod(left, right);
				break;
			case '^':
				result = pow(left, right);
				break;
			}
			resultBox->Text = result.ToString();
		}
	};
}
