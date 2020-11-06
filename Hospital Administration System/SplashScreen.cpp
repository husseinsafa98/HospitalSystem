#include "SplashScreen.h"
#include "FormMain.h"

namespace HospitalAdministrationSystem
{
	System::Void SplashScreen::SplashScreen_Load(System::Object^  sender, System::EventArgs^  e)
	{
		fadeTimer = gcnew Timer();
		fadeTimer->Interval = 1000;
		fadeTimer->Tick += gcnew System::EventHandler(this, &HospitalAdministrationSystem::SplashScreen::timer_tick);
		fadeTimer->Start();
	}
	Void SplashScreen::timer_tick(Object ^sender, EventArgs ^e)
	{
		this->time++;
		if (this->time > 1)
		{
			this->Close();
			fadeTimer->Stop();
		}
	}
}