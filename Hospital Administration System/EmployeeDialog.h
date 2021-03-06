#pragma once

namespace HospitalAdministrationSystem 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EmployeeDialog
	/// </summary>
	public ref class EmployeeDialog : public System::Windows::Forms::Form
	{
	public:
		EmployeeDialog();
		EmployeeDialog(String ^employeeID);

		String ^getName();
		String ^getEmployeeID();//
		int getClockedIn();//
		double getSalary();//
		int getHoursWorkedPerWeek();//
		int getExperience();//
		String ^getEmail();//
		String ^getFaxNumber();//
		String ^getDateOfBirth();//
		String ^getEmergencyContact();//
		String ^getAddress();//
		String ^getHomePhone();//
		String ^getCellPhone();//
		String ^getWorkPhone();//

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EmployeeDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  textBox_Email;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox_EmergencyContact;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox_Fax;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox_CellPhone;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox_WorkPhone;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox_HomePhone;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox_Address;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker_DOB;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox_Name;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		String ^employeeID;//
		int clockedIn;//
		double salary;//
		int hoursWorkedPerWeek;//
		int experience;//
		String ^email;//
		String ^employeeName;//
		String ^fax;//
		String ^dateOfBirth;//
		String ^emergencyContact;//
		String ^address;//
		String ^homePhone;//
		String ^cellPhone;//
		String ^workPhone;//

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox_EmployeeID;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker_ClockedIn;


	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  textBox_HoursWorked;

	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  textBox_Salary;

	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  textBox_Experience;
	private: System::Windows::Forms::Button^  button_OK;


	private: System::Windows::Forms::Button^  button_Cancel;
	private: System::Windows::Forms::Button^  button_generate;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox_Email = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox_EmergencyContact = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox_Fax = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox_CellPhone = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox_WorkPhone = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox_HomePhone = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_Address = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker_DOB = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_Name = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox_Experience = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox_Salary = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox_HoursWorked = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker_ClockedIn = (gcnew System::Windows::Forms::DateTimePicker());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox_EmployeeID = (gcnew System::Windows::Forms::TextBox());
			this->button_OK = (gcnew System::Windows::Forms::Button());
			this->button_Cancel = (gcnew System::Windows::Forms::Button());
			this->button_generate = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label15);
			this->groupBox1->Controls->Add(this->textBox_Email);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->textBox_EmergencyContact);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->textBox_Fax);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->textBox_CellPhone);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->textBox_WorkPhone);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox_HomePhone);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox_Address);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->dateTimePicker_DOB);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox_Name);
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(338, 299);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Personal Information";
			// 
			// label15
			// 
			this->label15->Location = System::Drawing::Point(9, 238);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(321, 23);
			this->label15->TabIndex = 17;
			this->label15->Text = L"Email";
			this->label15->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_Email
			// 
			this->textBox_Email->Location = System::Drawing::Point(6, 264);
			this->textBox_Email->Name = L"textBox_Email";
			this->textBox_Email->Size = System::Drawing::Size(324, 22);
			this->textBox_Email->TabIndex = 16;
			// 
			// label8
			// 
			this->label8->Location = System::Drawing::Point(121, 187);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(209, 23);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Emergency Contact Name";
			this->label8->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_EmergencyContact
			// 
			this->textBox_EmergencyContact->Location = System::Drawing::Point(118, 213);
			this->textBox_EmergencyContact->Name = L"textBox_EmergencyContact";
			this->textBox_EmergencyContact->Size = System::Drawing::Size(212, 22);
			this->textBox_EmergencyContact->TabIndex = 14;
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(6, 187);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(96, 23);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Fax Number";
			this->label7->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_Fax
			// 
			this->textBox_Fax->Location = System::Drawing::Point(3, 213);
			this->textBox_Fax->Name = L"textBox_Fax";
			this->textBox_Fax->Size = System::Drawing::Size(99, 22);
			this->textBox_Fax->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(234, 136);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(96, 23);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Cell Phone";
			this->label6->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_CellPhone
			// 
			this->textBox_CellPhone->Location = System::Drawing::Point(231, 162);
			this->textBox_CellPhone->Name = L"textBox_CellPhone";
			this->textBox_CellPhone->Size = System::Drawing::Size(99, 22);
			this->textBox_CellPhone->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(121, 136);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 23);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Work Phone";
			this->label5->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_WorkPhone
			// 
			this->textBox_WorkPhone->Location = System::Drawing::Point(118, 162);
			this->textBox_WorkPhone->Name = L"textBox_WorkPhone";
			this->textBox_WorkPhone->Size = System::Drawing::Size(99, 22);
			this->textBox_WorkPhone->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(6, 136);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(96, 23);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Home Phone";
			this->label4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_HomePhone
			// 
			this->textBox_HomePhone->Location = System::Drawing::Point(3, 162);
			this->textBox_HomePhone->Name = L"textBox_HomePhone";
			this->textBox_HomePhone->Size = System::Drawing::Size(99, 22);
			this->textBox_HomePhone->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(9, 75);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(321, 23);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Address";
			this->label3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_Address
			// 
			this->textBox_Address->Location = System::Drawing::Point(6, 101);
			this->textBox_Address->Name = L"textBox_Address";
			this->textBox_Address->Size = System::Drawing::Size(324, 22);
			this->textBox_Address->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(227, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 23);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Date Of Birth";
			this->label2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// dateTimePicker_DOB
			// 
			this->dateTimePicker_DOB->CustomFormat = L"MM/dd/yyyy";
			this->dateTimePicker_DOB->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker_DOB->Location = System::Drawing::Point(227, 44);
			this->dateTimePicker_DOB->Name = L"dateTimePicker_DOB";
			this->dateTimePicker_DOB->Size = System::Drawing::Size(103, 22);
			this->dateTimePicker_DOB->TabIndex = 2;
			this->dateTimePicker_DOB->Value = System::DateTime(1971, 12, 31, 0, 0, 0, 0);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(9, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(193, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Name";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_Name
			// 
			this->textBox_Name->Location = System::Drawing::Point(6, 44);
			this->textBox_Name->Name = L"textBox_Name";
			this->textBox_Name->Size = System::Drawing::Size(196, 22);
			this->textBox_Name->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button_generate);
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->textBox_Experience);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->textBox_Salary);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->textBox_HoursWorked);
			this->groupBox2->Controls->Add(this->dateTimePicker_ClockedIn);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->textBox_EmployeeID);
			this->groupBox2->Location = System::Drawing::Point(347, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(324, 299);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Employee Information";
			// 
			// label13
			// 
			this->label13->Location = System::Drawing::Point(9, 238);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(309, 23);
			this->label13->TabIndex = 12;
			this->label13->Text = L"Years Experience";
			this->label13->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_Experience
			// 
			this->textBox_Experience->Location = System::Drawing::Point(6, 264);
			this->textBox_Experience->Name = L"textBox_Experience";
			this->textBox_Experience->Size = System::Drawing::Size(312, 22);
			this->textBox_Experience->TabIndex = 11;
			// 
			// label12
			// 
			this->label12->Location = System::Drawing::Point(6, 171);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(312, 23);
			this->label12->TabIndex = 10;
			this->label12->Text = L"Salary";
			this->label12->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_Salary
			// 
			this->textBox_Salary->Location = System::Drawing::Point(6, 197);
			this->textBox_Salary->Name = L"textBox_Salary";
			this->textBox_Salary->Size = System::Drawing::Size(312, 22);
			this->textBox_Salary->TabIndex = 9;
			// 
			// label11
			// 
			this->label11->Location = System::Drawing::Point(6, 98);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(312, 23);
			this->label11->TabIndex = 8;
			this->label11->Text = L"Hours Worked";
			this->label11->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_HoursWorked
			// 
			this->textBox_HoursWorked->Location = System::Drawing::Point(6, 124);
			this->textBox_HoursWorked->Name = L"textBox_HoursWorked";
			this->textBox_HoursWorked->Size = System::Drawing::Size(312, 22);
			this->textBox_HoursWorked->TabIndex = 7;
			// 
			// dateTimePicker_ClockedIn
			// 
			this->dateTimePicker_ClockedIn->CustomFormat = L"MM/dd/yyyy";
			this->dateTimePicker_ClockedIn->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker_ClockedIn->Location = System::Drawing::Point(189, 44);
			this->dateTimePicker_ClockedIn->Name = L"dateTimePicker_ClockedIn";
			this->dateTimePicker_ClockedIn->Size = System::Drawing::Size(129, 22);
			this->dateTimePicker_ClockedIn->TabIndex = 6;
			this->dateTimePicker_ClockedIn->Value = System::DateTime(1753, 1, 1, 0, 0, 0, 0);
			// 
			// label10
			// 
			this->label10->Location = System::Drawing::Point(184, 18);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(134, 23);
			this->label10->TabIndex = 5;
			this->label10->Text = L"Clocked In";
			this->label10->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// label9
			// 
			this->label9->Location = System::Drawing::Point(6, 18);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(96, 23);
			this->label9->TabIndex = 3;
			this->label9->Text = L"Employee ID";
			this->label9->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_EmployeeID
			// 
			this->textBox_EmployeeID->Location = System::Drawing::Point(3, 44);
			this->textBox_EmployeeID->Name = L"textBox_EmployeeID";
			this->textBox_EmployeeID->Size = System::Drawing::Size(99, 22);
			this->textBox_EmployeeID->TabIndex = 2;
			// 
			// button_OK
			// 
			this->button_OK->Location = System::Drawing::Point(596, 317);
			this->button_OK->Name = L"button_OK";
			this->button_OK->Size = System::Drawing::Size(75, 34);
			this->button_OK->TabIndex = 3;
			this->button_OK->Text = L"Ok";
			this->button_OK->UseVisualStyleBackColor = true;
			this->button_OK->Click += gcnew System::EventHandler(this, &EmployeeDialog::button_OK_Click);
			// 
			// button_Cancel
			// 
			this->button_Cancel->Location = System::Drawing::Point(501, 317);
			this->button_Cancel->Name = L"button_Cancel";
			this->button_Cancel->Size = System::Drawing::Size(75, 34);
			this->button_Cancel->TabIndex = 4;
			this->button_Cancel->Text = L"Cancel";
			this->button_Cancel->UseVisualStyleBackColor = true;
			this->button_Cancel->Click += gcnew System::EventHandler(this, &EmployeeDialog::button_Cancel_Click);
			// 
			// button_generate
			// 
			this->button_generate->Location = System::Drawing::Point(103, 41);
			this->button_generate->Name = L"button_generate";
			this->button_generate->Size = System::Drawing::Size(75, 29);
			this->button_generate->TabIndex = 13;
			this->button_generate->Text = L"generate";
			this->button_generate->UseVisualStyleBackColor = true;
			this->button_generate->Click += gcnew System::EventHandler(this, &EmployeeDialog::button_generate_Click);
			// 
			// EmployeeDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(680, 362);
			this->Controls->Add(this->button_Cancel);
			this->Controls->Add(this->button_OK);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"EmployeeDialog";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EmployeeDialog";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_OK_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_Cancel_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_generate_Click(System::Object^  sender, System::EventArgs^  e);
};
}
