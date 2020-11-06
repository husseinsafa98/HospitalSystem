#pragma once

namespace HospitalAdministrationSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ItemDialog
	/// </summary>
	public ref class ItemDialog : public System::Windows::Forms::Form
	{
	public:
		ItemDialog();
		ItemDialog(String ^itemName);

		String ^getItemName();
		double getItemPrice();
		int getItemStock();
		int getItemsSold();
		String ^getItemDescription();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ItemDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox_ItemName;
	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox_ItemPrice;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox_Description;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox_inStock;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox_Sold;
	private: System::Windows::Forms::Button^  button_OK;


	private: System::Windows::Forms::Button^  button_Cancel;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		String ^itemName;
		double itemPrice;
		int itemStock;
		int itemsSold;
		String ^itemDescription;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox_ItemName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox_ItemPrice = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_Description = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox_inStock = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox_Sold = (gcnew System::Windows::Forms::TextBox());
			this->button_OK = (gcnew System::Windows::Forms::Button());
			this->button_Cancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox_ItemName
			// 
			this->textBox_ItemName->Location = System::Drawing::Point(12, 51);
			this->textBox_ItemName->Name = L"textBox_ItemName";
			this->textBox_ItemName->Size = System::Drawing::Size(223, 22);
			this->textBox_ItemName->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(12, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(223, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Item Name";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(241, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 23);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Item Price";
			this->label2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_ItemPrice
			// 
			this->textBox_ItemPrice->Location = System::Drawing::Point(241, 51);
			this->textBox_ItemPrice->Name = L"textBox_ItemPrice";
			this->textBox_ItemPrice->Size = System::Drawing::Size(87, 22);
			this->textBox_ItemPrice->TabIndex = 2;
			this->textBox_ItemPrice->Text = L"0";
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(9, 164);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(319, 23);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Item Description";
			this->label3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_Description
			// 
			this->textBox_Description->Location = System::Drawing::Point(9, 193);
			this->textBox_Description->Multiline = true;
			this->textBox_Description->Name = L"textBox_Description";
			this->textBox_Description->Size = System::Drawing::Size(319, 89);
			this->textBox_Description->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(12, 89);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(97, 23);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Items in stock";
			this->label4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_inStock
			// 
			this->textBox_inStock->Location = System::Drawing::Point(12, 118);
			this->textBox_inStock->Name = L"textBox_inStock";
			this->textBox_inStock->Size = System::Drawing::Size(97, 22);
			this->textBox_inStock->TabIndex = 6;
			this->textBox_inStock->Text = L"0";
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(148, 89);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(87, 23);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Items Sold";
			this->label5->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// textBox_Sold
			// 
			this->textBox_Sold->Location = System::Drawing::Point(148, 118);
			this->textBox_Sold->Name = L"textBox_Sold";
			this->textBox_Sold->Size = System::Drawing::Size(87, 22);
			this->textBox_Sold->TabIndex = 8;
			this->textBox_Sold->Text = L"0";
			// 
			// button_OK
			// 
			this->button_OK->Location = System::Drawing::Point(254, 299);
			this->button_OK->Name = L"button_OK";
			this->button_OK->Size = System::Drawing::Size(75, 32);
			this->button_OK->TabIndex = 10;
			this->button_OK->Text = L"Ok";
			this->button_OK->UseVisualStyleBackColor = true;
			this->button_OK->Click += gcnew System::EventHandler(this, &ItemDialog::button_OK_Click);
			// 
			// button_Cancel
			// 
			this->button_Cancel->Location = System::Drawing::Point(160, 299);
			this->button_Cancel->Name = L"button_Cancel";
			this->button_Cancel->Size = System::Drawing::Size(75, 32);
			this->button_Cancel->TabIndex = 11;
			this->button_Cancel->Text = L"Cancel";
			this->button_Cancel->UseVisualStyleBackColor = true;
			this->button_Cancel->Click += gcnew System::EventHandler(this, &ItemDialog::button_Cancel_Click);
			// 
			// ItemDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(341, 345);
			this->Controls->Add(this->button_Cancel);
			this->Controls->Add(this->button_OK);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox_Sold);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox_inStock);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox_Description);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox_ItemPrice);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox_ItemName);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ItemDialog";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Add Item";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void button_Cancel_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_OK_Click(System::Object^  sender, System::EventArgs^  e);
};
}
