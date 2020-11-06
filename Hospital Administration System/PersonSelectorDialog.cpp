#include "PersonSelectorDialog.h"
#include "Globals.h"

namespace HospitalAdministrationSystem
{
	PersonSelectorDialog::PersonSelectorDialog(String ^personType)
	{
		InitializeComponent();
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->personType = personType;
		if (personType == "Patients")
		{
			for (Person person : Globals::databaseManager->getPatients())
				listBox_People->Items->Add(gcnew String(person.getName().c_str()));
			this->Text = "Select a Patient";
		}
		else if (personType == "Doctors")
		{
			for (Person person : Globals::databaseManager->getDoctors())
				listBox_People->Items->Add(gcnew String(person.getName().c_str()));
			this->Text = "Select a Doctor";
		}
		else if (personType == "Nurses")
		{
			for (Person person : Globals::databaseManager->getNurses())
				listBox_People->Items->Add(gcnew String(person.getName().c_str()));
			this->Text = "Select a Nurse";
		}
		else if (personType == "OtherEmployees")
		{
			for (Person person : Globals::databaseManager->getOtherEmployees())
				listBox_People->Items->Add(gcnew String(person.getName().c_str()));
			this->Text = "Select an Employee";
		}
	}
	PersonSelectorDialog::PersonSelectorDialog(String ^ personType, List<String^> ^items)
	{
		InitializeComponent();
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->personType = personType;
		for (int i = 0; i < items->Count; i++)
			listBox_People->Items->Add(items[i]);
		if (personType == "Patients")
		{
			this->Text = "Select a Patient";
		}
		else if (personType == "Doctors")
		{
			this->Text = "Select a Doctor";
		}
		else if (personType == "Nurses")
		{
			this->Text = "Select a Nurse";
		}
		else if (personType == "OtherEmployees")
		{
			this->Text = "Select an Employee";
		}
	}
	String ^PersonSelectorDialog::getPersonType()
	{
		return this->personType;
	}
	String ^ PersonSelectorDialog::getPersonID()
	{
		return this->ID;
	}
	System::Void PersonSelectorDialog::button_Cancel_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}
	System::Void PersonSelectorDialog::button_OK_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (listBox_People->SelectedItem != nullptr)
		{
			String ^varName;
			if (personType == "Patients")
				varName = "patientID";
			else if (personType == "Doctors" || personType == "Nurses" || personType == "OtherEmployees")
				varName = "employeeID";
			SQLiteCommand ^cmd = gcnew SQLiteCommand(String::Format("SELECT {0} FROM {1} WHERE name='{2}';", varName, personType, listBox_People->SelectedItem->ToString()), Globals::databaseManager->getSqliteDB());
			SQLiteDataReader ^reader = cmd->ExecuteReader();
			if (reader->Read())
			{
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->ID = (String^)reader[varName];
			}

			this->Close();
		}
	}
}