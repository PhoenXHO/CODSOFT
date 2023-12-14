#include "Calculator.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ argv) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Calculator::Calculator app;
	Application::Run(% app);

	return 0;
}