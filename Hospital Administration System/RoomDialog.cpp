#include "RoomDialog.h"
#include "Globals.h"
#include <vector>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

namespace HospitalAdministrationSystem
{
	RoomDialog::RoomDialog()
	{
		InitializeComponent();
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Text = "Add Room";
	}
	RoomDialog::RoomDialog(String ^roomNumber)
	{
		InitializeComponent();
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Text = "Edit Room";
		
		// gets the room from the database.
		Room room = Globals::databaseManager->getRoom(roomNumber);

		// get all patients from the room and add them to the textbox.
		for (Patient patient : room.getPatients())
		{
			this->textBox_Patients->Text += String::Format("{0} ({1})\r\n", gcnew String(patient.getName().c_str()), gcnew String(patient.getPatientID().c_str()));
		}

		this->textBox_RoomNumber->Text = gcnew String(room.getRoomNumber().c_str());
		this->textBox_Capacity->Text = room.getMaxSize().ToString();
	}
	String ^ RoomDialog::getRoomNumber()
	{
		return this->roomNumber;
	}
	int RoomDialog::getCapacity()
	{
		return this->capacity;
	}
	List<String^>^ RoomDialog::getPatients()
	{
		return patients;
	}
	System::Void RoomDialog::button_OK_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->patients->Clear();
		this->roomNumber = textBox_RoomNumber->Text;
		this->capacity = (textBox_Capacity->Text == "") ? 0 : Convert::ToInt32(textBox_Capacity->Text);
		for (int i = 0; i < textBox_Patients->Lines->Length; i++) // add all patient id's to the list.
		{
			String ^id = textBox_Patients->Lines[i]->Split('(')[1]->TrimEnd(')');
			if(id != "" && id->Length == 8)
				this->patients->Add(id);
		}
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	System::Void RoomDialog::button_Cancel_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Close();
	}
	System::Void RoomDialog::button_SearchOK_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		bool found = false;
		for (Patient patient : Globals::databaseManager->getPatients())
		{
			if (gcnew String(patient.getName().c_str()) == textBox_Name->Text)
			{
				textBox_Name->Text = gcnew String(patient.getPatientID().c_str());
				found = true;
				break;
			}
		}
		if (!found)
			textBox_Name->Text = "Not Found";
	}
}