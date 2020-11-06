#include "EmployeeDialog.h"
#include "Globals.h"

namespace HospitalAdministrationSystem
{
	EmployeeDialog::EmployeeDialog()
	{
		InitializeComponent();
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Text = "Add Employee";
	}
	EmployeeDialog::EmployeeDialog(String ^employeeID)
	{
		InitializeComponent();
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Text = "Edit Employee";

		Employee employee = Globals::databaseManager->getOtherEmployee(employeeID);

		textBox_Address->Text = gcnew String(employee.getContactInfo().getAddress().c_str());
		textBox_CellPhone->Text = gcnew String(employee.getContactInfo().getCellPhone().c_str());
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
		
	}
	String ^ EmployeeDialog::getName()
	{
		return this->employeeName;
	}
	String ^ EmployeeDialog::getEmployeeID()
	{
		return this->employeeID;
	}
	int EmployeeDialog::getClockedIn()
	{
		return this->clockedIn;
	}
	double EmployeeDialog::getSalary()
	{
		return this->salary;
	}
	int EmployeeDialog::getHoursWorkedPerWeek()
	{
		return this->hoursWorkedPerWeek;
	}
	int EmployeeDialog::getExperience()
	{
		return this->experience;
	}
	String ^ EmployeeDialog::getEmail()
	{
		return this->email;
	}
	String ^ EmployeeDialog::getFaxNumber()
	{
		return this->fax;
	}
	String ^ EmployeeDialog::getDateOfBirth()
	{
		return this->dateOfBirth;
	}
	String ^ EmployeeDialog::getEmergencyContact()
	{
		return this->emergencyContact;
	}
	String ^ EmployeeDialog::getAddress()
	{
		return this->address;
	}
	String ^ EmployeeDialog::getHomePhone()
	{
		return this->homePhone;
	}
	String ^ EmployeeDialog::getCellPhone()
	{
		return this->cellPhone;
	}
	String ^ EmployeeDialog::getWorkPhone()
	{
		return this->workPhone;
	}
	System::Void EmployeeDialog::button_OK_Click(System::Object^  sender, System::EventArgs^  e)
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
		this->salary = Convert::ToDouble(textBox_Salary->Text);
		this->experience = Convert::ToInt32(textBox_Experience->Text);
		this->hoursWorkedPerWeek = Convert::ToInt32(textBox_HoursWorked->Text);

		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	System::Void EmployeeDialog::button_Cancel_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}
	System::Void EmployeeDialog::button_generate_Click(System::Object^  sender, System::EventArgs^  e)
	{
		textBox_EmployeeID->Text = (gcnew Random())->Next(10000000, 99999999).ToString();
	}
}