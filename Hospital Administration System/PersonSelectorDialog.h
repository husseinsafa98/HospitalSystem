#pragma once

namespace HospitalAdministrationSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PersonSelectorDialog
	/// </summary>
	public ref class PersonSelectorDialog : public System::Windows::Forms::Form
	{
	public:
		PersonSelectorDialog(String ^personType);
		PersonSelectorDialog(String ^personType, List<String^> ^items);

		String ^getPersonType();
		String ^getPersonID();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PersonSelectorDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox_People;
	protected:

	private: System::Windows::Forms::Button^  button_Cancel;
	private: System::Windows::Forms::Button^  button_OK;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		String ^personType;
		String ^ID;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox_People = (gcnew System::Windows::Forms::ListBox());
			this->button_Cancel = (gcnew System::Windows::Forms::Button());
			this->button_OK = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBox_People
			// 
			this->listBox_People->Dock = System::Windows::Forms::DockStyle::Top;
			this->listBox_People->FormattingEnabled = true;
			this->listBox_People->ItemHeight = 16;
			this->listBox_People->Location = System::Drawing::Point(0, 0);
			this->listBox_People->Name = L"listBox_People";
			this->listBox_People->Size = System::Drawing::Size(451, 276);
			this->listBox_People->TabIndex = 0;
			// 
			// button_Cancel
			// 
			this->button_Cancel->Location = System::Drawing::Point(278, 282);
			this->button_Cancel->Name = L"button_Cancel";
			this->button_Cancel->Size = System::Drawing::Size(75, 32);
			this->button_Cancel->TabIndex = 13;
			this->button_Cancel->Text = L"Cancel";
			this->button_Cancel->UseVisualStyleBackColor = true;
			this->button_Cancel->Click += gcnew System::EventHandler(this, &PersonSelectorDialog::button_Cancel_Click);
			// 
			// button_OK
			// 
			this->button_OK->Location = System::Drawing::Point(372, 282);
			this->button_OK->Name = L"button_OK";
			this->button_OK->Size = System::Drawing::Size(75, 32);
			this->button_OK->TabIndex = 12;
			this->button_OK->Text = L"Ok";
			this->button_OK->UseVisualStyleBackColor = true;
			this->button_OK->Click += gcnew System::EventHandler(this, &PersonSelectorDialog::button_OK_Click);
			// 
			// PersonSelectorDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(451, 319);
			this->Controls->Add(this->button_Cancel);
			this->Controls->Add(this->button_OK);
			this->Controls->Add(this->listBox_People);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"PersonSelectorDialog";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"PersonSelectorDialog";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_Cancel_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_OK_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
