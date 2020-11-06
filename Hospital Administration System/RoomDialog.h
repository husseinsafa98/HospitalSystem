#pragma once


namespace HospitalAdministrationSystem 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for RoomDialog
	/// </summary>
	public ref class RoomDialog : public System::Windows::Forms::Form
	{
	public:
		RoomDialog();
		RoomDialog(String ^roomNumber);

		String ^ getRoomNumber();
		int getCapacity();
		List<String^> ^getPatients();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RoomDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox_RoomNumber;
	private: System::Windows::Forms::TextBox^  textBox_Capacity;
	protected:


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox_Patients;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox_Name;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button_Cancel;

	private: System::Windows::Forms::Button^  button_OK;
	private: System::Windows::Forms::Button^  button_SearchOK;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		String ^roomNumber;
		int capacity;
		List<String^> ^patients = gcnew List<String^>();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_RoomNumber = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Capacity = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox_Patients = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_Name = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button_Cancel = (gcnew System::Windows::Forms::Button());
			this->button_OK = (gcnew System::Windows::Forms::Button());
			this->button_SearchOK = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Room Number";
			// 
			// textBox_RoomNumber
			// 
			this->textBox_RoomNumber->Location = System::Drawing::Point(12, 41);
			this->textBox_RoomNumber->Name = L"textBox_RoomNumber";
			this->textBox_RoomNumber->Size = System::Drawing::Size(102, 22);
			this->textBox_RoomNumber->TabIndex = 1;
			// 
			// textBox_Capacity
			// 
			this->textBox_Capacity->Location = System::Drawing::Point(134, 41);
			this->textBox_Capacity->Name = L"textBox_Capacity";
			this->textBox_Capacity->Size = System::Drawing::Size(107, 22);
			this->textBox_Capacity->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(134, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 23);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Room Capacity";
			// 
			// textBox_Patients
			// 
			this->textBox_Patients->Location = System::Drawing::Point(12, 106);
			this->textBox_Patients->Multiline = true;
			this->textBox_Patients->Name = L"textBox_Patients";
			this->textBox_Patients->Size = System::Drawing::Size(229, 135);
			this->textBox_Patients->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(15, 80);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(226, 23);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Patients (patientID)";
			this->label3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_Name
			// 
			this->textBox_Name->Location = System::Drawing::Point(12, 270);
			this->textBox_Name->Name = L"textBox_Name";
			this->textBox_Name->Size = System::Drawing::Size(185, 22);
			this->textBox_Name->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(12, 244);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(185, 23);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Patient ID Search By Name";
			this->label4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button_Cancel
			// 
			this->button_Cancel->Location = System::Drawing::Point(85, 309);
			this->button_Cancel->Name = L"button_Cancel";
			this->button_Cancel->Size = System::Drawing::Size(75, 28);
			this->button_Cancel->TabIndex = 8;
			this->button_Cancel->Text = L"Cancel";
			this->button_Cancel->UseVisualStyleBackColor = true;
			this->button_Cancel->Click += gcnew System::EventHandler(this, &RoomDialog::button_Cancel_Click);
			// 
			// button_OK
			// 
			this->button_OK->Location = System::Drawing::Point(166, 309);
			this->button_OK->Name = L"button_OK";
			this->button_OK->Size = System::Drawing::Size(75, 28);
			this->button_OK->TabIndex = 9;
			this->button_OK->Text = L"Ok";
			this->button_OK->UseVisualStyleBackColor = true;
			this->button_OK->Click += gcnew System::EventHandler(this, &RoomDialog::button_OK_Click);
			// 
			// button_SearchOK
			// 
			this->button_SearchOK->Location = System::Drawing::Point(203, 269);
			this->button_SearchOK->Name = L"button_SearchOK";
			this->button_SearchOK->Size = System::Drawing::Size(35, 23);
			this->button_SearchOK->TabIndex = 10;
			this->button_SearchOK->Text = L"ok";
			this->button_SearchOK->UseVisualStyleBackColor = true;
			this->button_SearchOK->Click += gcnew System::EventHandler(this, &RoomDialog::button_SearchOK_Click);
			// 
			// RoomDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(250, 345);
			this->Controls->Add(this->button_SearchOK);
			this->Controls->Add(this->button_OK);
			this->Controls->Add(this->button_Cancel);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox_Name);
			this->Controls->Add(this->textBox_Patients);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox_Capacity);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox_RoomNumber);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"RoomDialog";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"RoomDialog";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void button_OK_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void button_Cancel_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void button_SearchOK_Click(System::Object^  sender, System::EventArgs^  e);
};
}
