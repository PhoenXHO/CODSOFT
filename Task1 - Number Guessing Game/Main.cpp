#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

// Main entry point for the application
int main(array<String^>^ args)
{
	// Enable visual styles for controls
	Application::EnableVisualStyles();
	// Use GDI+ text rendering
	Application::SetCompatibleTextRenderingDefault(false);
	// Create main form object
	NumberGuessingGame::MainForm form;
	// Run the main form to start the application
	Application::Run(% form);
}