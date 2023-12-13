#pragma once

#include <random>

namespace NumberGuessingGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();

			this->MaximizeBox = false;

			this->MinimumSize = System::Drawing::Size(440, 410);
			this->MaximumSize = System::Drawing::Size(460, 450);

			difficultyPanel->Visible = true;
			mainPanel->Visible = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Panel^ difficultyPanel;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::GroupBox^ container;
	private: System::Windows::Forms::NumericUpDown^ guessBox;
	private: System::Windows::Forms::Label^ message;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ attemptsLabel;
	private: System::Windows::Forms::Panel^ mainPanel;

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
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->difficultyPanel = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->container = (gcnew System::Windows::Forms::GroupBox());
			this->guessBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->message = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->attemptsLabel = (gcnew System::Windows::Forms::Label());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->difficultyPanel->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->container->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guessBox))->BeginInit();
			this->mainPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// difficultyPanel
			// 
			this->difficultyPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->difficultyPanel->Controls->Add(this->groupBox1);
			this->difficultyPanel->Controls->Add(this->button1);
			this->difficultyPanel->Controls->Add(this->label1);
			this->difficultyPanel->Location = System::Drawing::Point(12, 12);
			this->difficultyPanel->Name = L"difficultyPanel";
			this->difficultyPanel->Size = System::Drawing::Size(416, 386);
			this->difficultyPanel->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton4);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(0, 108);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(416, 217);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Select a difficulty:";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(22, 106);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(177, 29);
			this->radioButton3->TabIndex = 8;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Hard (1 - 10000)";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(22, 141);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(205, 29);
			this->radioButton4->TabIndex = 7;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Insane (1 - 100000)";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(22, 71);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(194, 29);
			this->radioButton2->TabIndex = 4;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Medium (1 - 1000)";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(22, 36);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(157, 29);
			this->radioButton1->TabIndex = 3;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Easy (1 - 100)";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(0, 331);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(416, 55);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Confirm";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(0, -2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(416, 107);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Difficulty";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(0, -2);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(416, 107);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Guess the number";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(0, 331);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(416, 56);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Submit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// container
			// 
			this->container->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->container->Controls->Add(this->guessBox);
			this->container->Location = System::Drawing::Point(0, 144);
			this->container->Name = L"container";
			this->container->Size = System::Drawing::Size(416, 148);
			this->container->TabIndex = 10;
			this->container->TabStop = false;
			this->container->Text = L"Your guess:";
			// 
			// guessBox
			// 
			this->guessBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->guessBox->Location = System::Drawing::Point(102, 70);
			this->guessBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->guessBox->Name = L"guessBox";
			this->guessBox->Size = System::Drawing::Size(204, 30);
			this->guessBox->TabIndex = 1;
			// 
			// message
			// 
			this->message->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->message->Location = System::Drawing::Point(0, 295);
			this->message->Name = L"message";
			this->message->Size = System::Drawing::Size(416, 33);
			this->message->TabIndex = 11;
			this->message->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label3->Location = System::Drawing::Point(0, 108);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(155, 25);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Attempts left:";
			// 
			// attemptsLabel
			// 
			this->attemptsLabel->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->attemptsLabel->Location = System::Drawing::Point(155, 108);
			this->attemptsLabel->Name = L"attemptsLabel";
			this->attemptsLabel->Size = System::Drawing::Size(261, 25);
			this->attemptsLabel->TabIndex = 13;
			// 
			// mainPanel
			// 
			this->mainPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->mainPanel->Controls->Add(this->attemptsLabel);
			this->mainPanel->Controls->Add(this->label3);
			this->mainPanel->Controls->Add(this->message);
			this->mainPanel->Controls->Add(this->container);
			this->mainPanel->Controls->Add(this->button2);
			this->mainPanel->Controls->Add(this->label2);
			this->mainPanel->Location = System::Drawing::Point(12, 12);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(416, 386);
			this->mainPanel->TabIndex = 14;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(440, 410);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->difficultyPanel);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MainForm";
			this->Text = L"Number Guessing Game";
			this->difficultyPanel->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->container->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guessBox))->EndInit();
			this->mainPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		private: int max, ran, allowed_attempts;

		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			array<RadioButton ^> ^ difficultyRadios = {radioButton1, radioButton2, radioButton3, radioButton4};

			// Loop through the difficulty radio buttons
			for (int i = 0; i < difficultyRadios->Length; i++)
			{
				// Check if the current radio button is checked
				if (difficultyRadios[i]->Checked)
				{
					// Hide difficulty panel and show main game panel
					difficultyPanel->Visible = false;
					mainPanel->Visible = true;

					// Set max based on difficulty
					// Easy (1) -> 100
					// Medium (2) -> 1000
					// Hard (3) -> 10000
					// Insane (4) -> 100000
					max = pow(10, i + 2);

					// Calculate allowed attempts based on max
					allowed_attempts = 10 * (log10(max) - 1);
					attemptsLabel->Text = allowed_attempts.ToString();

					// Generate random number between 1 and max
					std::random_device rd;
					std::mt19937 gen(rd());
					ran = gen() % max + 1;

					// Update text to show new max
					container->Text = "Guess a number between 1 and " + max + " (inclusive): ";
					break;
				}
			}
		}
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			// Get the user's guess from the textbox
			int guess = Decimal::ToInt32(guessBox->Value);

			// Initialize attempt counter
			static int attempts = 1;

			// Calculate threshold for hints
			int threshold = max / 10;

			// If guess matches random number
			if (guess == ran)
			{
				// Update attempts
				attemptsLabel->Text = (allowed_attempts - attempts).ToString();

				// Show win message
				MessageBox::Show(
					"You guessed it! The number was " + ran + ".\nNumber of attempts: " + attempts,
					"You Win!", MessageBoxButtons::OK);

				// Reset attempt counter
				attempts = 1;
				// Offer to play again
				PlayAgain();
				return;
			}
			// If guess is too low
			else if (0 <= guess && guess < ran)
			{
				// Show hint based on closeness to answer
				message->Text = (guess < ran - threshold ? "Too low. " : "Close. ") + "Try again a higher number.";
			}
			// If guess is too high
			else if (max >= guess && guess > ran)
			{
				// Show hint based on closeness to answer
				message->Text = (guess > ran + threshold ? "Too high. " : "Close. ") + "Try again a lower number.";
			}
			// If guess is invalid
			else
			{
				// Show error message
				message->Text = "Invalid guess. Try again.";
				return;
			}

			// Update attempts counter
			attemptsLabel->Text = (allowed_attempts - attempts).ToString();
			attempts++;

			// Check if attempts exceeded
			if (attempts > allowed_attempts)
			{
				// Show lose message
				MessageBox::Show(
					"You lose! The number was " + ran,
					"You Lose!", MessageBoxButtons::OK);

				// Reset attempt counter
				attempts = 1;
				// Offer to play again
				PlayAgain();
			}
		}
		private:
		void PlayAgain(void)
		{
			// Show a simple message box asking if the user wants to play again
			auto result = MessageBox::Show(
				"Do you want to play again?",
				"Play Again?",
				MessageBoxButtons::YesNo);

			// If yes, create new form and show it
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				MainForm ^ newForm = gcnew MainForm;

				// Hide current form
				this->Hide();

				// Show new form
				newForm->ShowDialog();

				// Close current form
				this->Close();
			}
			// If no, just close current form and terminate the program
			else
			{
				this->Close();
			}
		}
	};
}
