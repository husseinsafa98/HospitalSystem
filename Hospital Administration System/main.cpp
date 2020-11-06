#include "FormMain.h"
#include "SplashScreen.h"

namespace HospitalAdministrationSystem 
{
	using namespace System;
	using namespace System::Windows::Forms;

	[STAThread]
	int Main(array<System::String ^> ^args)
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);

		// display splash screen.
		SplashScreen ^ss = gcnew SplashScreen;
		ss->ShowDialog();

		// run the main form.
		Application::Run(gcnew FormMain());
		return 0;
	}
}