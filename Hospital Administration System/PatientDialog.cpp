#include "PatientDialog.h"
#include "Globals.h"

namespace HospitalAdministrationSystem
{
	PatientDialog::PatientDialog()
	{
		InitializeComponent();
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		getInformation();
		
	}
	PatientDialog::PatientDialog(String ^ patientID)
	{
		InitializeComponent();
		this->Text = "Edit Patient";
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		getInformation();

		Patient patient = Globals::databaseManager->getPatient(patientID);
		
		textBox_Address->Text = gcnew String(patient.getContactInfo().getAddress().c_str());
		textBox_Ailment->Text = gcnew String(patient.getAilment().c_str());
		textBox_Bill->Text = patient.getBillingInfo().ToString();
		textBox_CellPhone->Text = gcnew String(patient.getContactInfo().getCellPhone().c_str());
		textBox_Email->Text = gcnew String(patient.getContactInfo().getEmail().c_str());
		textBox_EmergencyContact->Text = gcnew String(patient.getEmergencyContact().c_str());
		textBox_Fax->Text = gcnew String(patient.getContactInfo().getFaxNumber().c_str());
		textBox_HomePhone->Text = gcnew String(patient.getContactInfo().getHomePhone().c_str());
		textBox_Insurance->Text = gcnew String(patient.getInsurance().c_str());
		textBox_Name->Text = gcnew String(patient.getName().c_str());
		textBox_PatientID->Text = gcnew String(patient.getPatientID().c_str());
		textBox_WorkPhone->Text = gcnew String(patient.getContactInfo().getWorkPhone().c_str());
		comboBox_RoomNumber->Text = gcnew String(patient.getRoomNumber().c_str());
		comboBox_Doctor->Text = String::Format("{0} ({1})",gcnew String(Globals::databaseManager->getDoctor(gcnew String(patient.getDoctor().c_str())).getName().c_str()), gcnew String(patient.getDoctor().c_str()));
		comboBox_Nurse->Text = String::Format("{0} ({1})", gcnew String(Globals::databaseManager->getNurse(gcnew String(patient.getNurse().c_str())).getName().c_str()), gcnew String(patient.getNurse().c_str()));
		dateTimePicker_DOB->Text = gcnew String(patient.getDateOfBirth().c_str());
	}
	double PatientDialog::getBill()
	{
		return this->bill;
	}
	String ^ PatientDialog::getPatientID()
	{
		return this->patientID;
	}
	String ^ PatientDialog::getRoomNumber()
	{
		return this->roomNumber;
	}
	String ^ PatientDialog::getAilment()
	{
		return this->ailment;
	}
	String ^ PatientDialog::getInsurance()
	{
		return this->insurance;
	}
	String ^ PatientDialog::getDoctorID()
	{
		return this->doctorID;
	}
	String ^ PatientDialog::getNurseID()
	{
		return this->nurseID;
	}
	String ^ PatientDialog::getName()
	{
		return this->patientName;
	}
	String ^ PatientDialog::getDateOfBirth()
	{
		return this->dateOfBirth;
	}
	String ^ PatientDialog::getEmergencyContact()
	{
		return this->emergencyContact;
	}
	String ^ PatientDialog::getAddress()
	{
		return this->address;
	}
	String ^ PatientDialog::getHomePhone()
	{
		return this->homePhone;
	}
	String ^ PatientDialog::getCellPhone()
	{
		return this->cellPhone;
	}
	String ^ PatientDialog::getWorkPhone()
	{
		return this->workPhone;
	}
	String ^ PatientDialog::getFax()
	{
		return this->fax;
	}
	String ^ PatientDialog::getEmail()
	{
		return this->email;
	}

	System::Void PatientDialog::textBox_HomePhone_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		//TODO block input if its not numeric
	}

	System::Void PatientDialog::button_generate_Click(System::Object^  sender, System::EventArgs^  e)
	{
		textBox_PatientID->Text = (gcnew Random())->Next(10000000, 99999999).ToString();
	}
	System::Void PatientDialog::button_OK_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->address = textBox_Address->Text;
		this->ailment = textBox_Ailment->Text;
		this->bill = Convert::ToDouble(textBox_Bill->Text);
		this->cellPhone = textBox_CellPhone->Text;
		this->email = textBox_Email->Text;
		this->emergencyContact = textBox_EmergencyContact->Text;
		this->fax = textBox_Fax->Text;
		this->homePhone = textBox_HomePhone->Text;
		this->insurance = textBox_Insurance->Text;
		this->patientName = textBox_Name->Text;
		this->patientID = textBox_PatientID->Text;
		this->workPhone = textBox_WorkPhone->Text;
		this->roomNumber = comboBox_RoomNumber->Text;
		this->doctorID = comboBox_Doctor->Text->Split('(')[1]->TrimEnd(')');
		this->nurseID = comboBox_Nurse->Text->Split('(')[1]->TrimEnd(')');
		this->dateOfBirth = dateTimePicker_DOB->Text;


		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	System::Void PatientDialog::button_Cancel_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}
	Void PatientDialog::getInformation()
	{
		std::vector<MedicalEmployee> doctors = Globals::databaseManager->getDoctors();
		std::vector<MedicalEmployee> nurses = Globals::databaseManager->getNurses();
		std::vector<Room> rooms = Globals::databaseManager->getRooms();

		for (MedicalEmployee doctor : doctors)
			comboBox_Doctor->Items->Add(String::Format("{0} ({1})", gcnew String(doctor.getName().c_str()), gcnew String(doctor.getEmployeeID().c_str())));
		for (MedicalEmployee nurse : nurses)
			comboBox_Nurse->Items->Add(String::Format("{0} ({1})", gcnew String(nurse.getName().c_str()), gcnew String(nurse.getEmployeeID().c_str())));
		for (Room room : rooms)
			comboBox_RoomNumber->Items->Add(gcnew String(room.getRoomNumber().c_str()));

	}
}