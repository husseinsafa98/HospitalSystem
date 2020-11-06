#include "MedicalEmployeeDialog.h"
#include "Globals.h"

namespace HospitalAdministrationSystem
{
	MedicalEmployeeDialog::MedicalEmployeeDialog(MedicalEmployeeType employeeType)
	{
		InitializeComponent();
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->employeeType = employeeType;
		this->Text = (this->employeeType == EMPLOYEE_TYPE_DOCTOR) ? "Add Doctor" : "Add Nurse";
	}
	MedicalEmployeeDialog::MedicalEmployeeDialog(MedicalEmployeeType employeeType, String ^employeeID)
	{
		InitializeComponent();
		MedicalEmployee employee;
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->employeeType = employeeType;
		if (this->employeeType == EMPLOYEE_TYPE_DOCTOR)
		{
			
			employee = Globals::databaseManager->getDoctor(employeeID);
			this->Text = "Edit Doctor";
		}
		else
		{
			employee = Globals::databaseManager->getNurse(employeeID);
			this->Text = "Edit Nurse";
		}

		textBox_Address->Text = gcnew String(employee.getContactInfo().getAddress().c_str());
		textBox_CellPhone->Text = gcnew String(employee.getContactInfo().getCellPhone().c_str());
		/*if(employee.getClockedIn() != 0)*/
		dateTimePicker_ClockedIn->Value = (DateTime(1970, 1, 1, 0, 0, 0, 0, System::DateTimeKind::Utc)).AddSeconds(employee.getClockedIn()).ToLocalTime();
		textBox_Email->Text = gcnew String(employee.getContactInfo().getEmail().c_str());
		textBox_EmergencyContact->Text = gcnew String(employee.getEmergencyContact().c_str());
		textBox_Fax->Text = gcnew String(employee.getContactInfo().getFaxNumber().c_str());
		textBox_HomePhone->Text = gcnew String(employee.getContactInfo().getHomePhone().c_str());
		textBox_Name->Text = gcnew String(employee.getName().c_str());
		textBox_EmployeeID->Text = gcnew String(employee.getEmployeeID().c_str());
		textBox_WorkPhone->Text = gcnew String(employee.getContactInfo().getWorkPhone().c_str());
		dateTimePicker_DOB->Text = gcnew String(employee.getDateOfBirth().c_str());
		textBox_Salary->Text = employee.getSalary().ToString();
		textBox_Experience->Text = employee.getExperience().ToString();
		textBox_HoursWorked->Text = employee.getHoursWrokedPerWeek().ToString();

		textBox_Degree->Text = gcnew String(employee.getDegree().c_str());
		textBox_Specialization->Text = gcnew String(employee.getSpecialization().c_str());
		for (Patient patient : employee.getPatients())
			richTextBox_Patients->Text += String::Format("{0} ({1})\r\n", gcnew String(patient.getName().c_str()), gcnew String(patient.getPatientID().c_str()));
	}
	String ^ MedicalEmployeeDialog::getName()
	{
		return this->employeeName;
	}
	String ^ MedicalEmployeeDialog::getEmployeeID()
	{
		return this->employeeID;
	}
	int MedicalEmployeeDialog::getClockedIn()
	{
		return this->clockedIn;
	}
	double MedicalEmployeeDialog::getSalary()
	{
		return this->salary;
	}
	int MedicalEmployeeDialog::getHoursWorkedPerWeek()
	{
		return this->hoursWorkedPerWeek;
	}
	int MedicalEmployeeDialog::getExperience()
	{
		return this->experience;
	}
	String ^ MedicalEmployeeDialog::getEmail()
	{
		return this->email;
	}
	String ^ MedicalEmployeeDialog::getFaxNumber()
	{
		return this->fax;
	}
	String ^ MedicalEmployeeDialog::getDateOfBirth()
	{
		return this->dateOfBirth;
	}
	String ^ MedicalEmployeeDialog::getEmergencyContact()
	{
		return this->emergencyContact;
	}
	String ^ MedicalEmployeeDialog::getAddress()
	{
		return this->address;
	}
	String ^ MedicalEmployeeDialog::getHomePhone()
	{
		return this->homePhone;
	}
	String ^ MedicalEmployeeDialog::getCellPhone()
	{
		return this->cellPhone;
	}
	String ^ MedicalEmployeeDialog::getWorkPhone()
	{
		return this->workPhone;
	}
	String ^ MedicalEmployeeDialog::getDegree()
	{
		return this->degree;
	}
	String ^ MedicalEmployeeDialog::getSpecialization()
	{
		return this->specialization;
	}
	List<String^>^ MedicalEmployeeDialog::getPatients()
	{
		return this->patients;
	}
	System::Void MedicalEmployeeDialog::button_generate_Click(System::Object^  sender, System::EventArgs^  e)
	{
		textBox_EmployeeID->Text = (gcnew Random())->Next(10000000, 99999999).ToString();
	}
	System::Void MedicalEmployeeDialog::button_Cancel_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}
	System::Void MedicalEmployeeDialog::button_OK_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->address = textBox_Address->Text;
		this->cellPhone = textBox_CellPhone->Text;
		this->clockedIn = Convert::ToInt32(dateTimePicker_ClockedIn->Value.UtcNow.Subtract(DateTime(1970, 1, 1)).TotalSeconds);
		this->email = textBox_Email->Text;
		this->emergencyContact = textBox_EmergencyContact->Text;
		this->fax = textBox_Fax->Text;
		this->homePhone = textBox_HomePhone->Text;
		this->employeeName = textBox_Name->Text;
		this->employeeID = textBox_EmployeeID->Text;
		this->workPhone = textBox_WorkPhone->Text;
		this->dateOfBirth = dateTimePicker_DOB->Text;
		this->salary = (textBox_Salary->Text == "") ? 0.0 : Convert::ToDouble(textBox_Salary->Text);
		this->experience = (textBox_Experience->Text == "") ? 0 : Convert::ToInt32(textBox_Experience->Text);
		this->hoursWorkedPerWeek = (textBox_HoursWorked->Text == "") ? 0 : Convert::ToInt32(textBox_HoursWorked->Text);

		this->degree = textBox_Degree->Text;
		this->specialization = textBox_Specialization->Text;

		this->patients = gcnew List<String^>();
		//= gcnew List<String^>(richTextBox_Patients->Lines);
		for (int i = 0; i < richTextBox_Patients->Lines->Length; i++)
		{
			if (richTextBox_Patients->Lines[i] == "")
				continue;
			String ^id = richTextBox_Patients->Lines[i]->Split('(')[1]->TrimEnd(')');
			if (id != "" || id->Length == 8)
				this->patients->Add(id);
		}

		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}

	System::Void MedicalEmployeeDialog::button_SearchOK_Click(System::Object^  sender, System::EventArgs^  e)
	{
		bool found = false;
		for (Patient patient : Globals::databaseManager->getPatients())
		{
			if (gcnew String(patient.getName().c_str()) == textBox_PatientIDSearch->Text)
			{
				textBox_PatientIDSearch->Text = gcnew String(patient.getPatientID().c_str());
				found = true;
				break;
			}
		}
		if (!found)
			textBox_PatientIDSearch->Text = "Not Found";
	}
}