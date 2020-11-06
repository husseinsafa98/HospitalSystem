#include "ItemDialog.h"
#include "Globals.h"

namespace HospitalAdministrationSystem
{
	ItemDialog::ItemDialog()
	{
		InitializeComponent();
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	}
	ItemDialog::ItemDialog(String ^itemName)
	{
		InitializeComponent();
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		Item item = Globals::databaseManager->getItem(itemName);
		if (itemName == gcnew String(item.getItemName().c_str()))
		{
			textBox_ItemName->Text = itemName;
			textBox_ItemPrice->Text = item.getItemPrice().ToString();
			textBox_Sold->Text = item.getSold().ToString();
			textBox_inStock->Text = item.getQuantity().ToString();
			textBox_Description->Text = gcnew String(item.getDescription().c_str());

			this->Text = "Edit Item";
		}
	}
	String ^ ItemDialog::getItemName()
	{
		return itemName;
	}
	double ItemDialog::getItemPrice()
	{
		return itemPrice;
	}
	int ItemDialog::getItemStock()
	{
		return itemStock;
	}
	int ItemDialog::getItemsSold()
	{
		return itemsSold;
	}
	String ^ ItemDialog::getItemDescription()
	{
		return itemDescription;
	}
	System::Void ItemDialog::button_Cancel_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}
	System::Void ItemDialog::button_OK_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		itemName = textBox_ItemName->Text;
		itemPrice = (textBox_ItemPrice->Text == "") ? 0.0 : Convert::ToDouble(textBox_ItemPrice->Text);
		itemStock = (textBox_ItemPrice->Text == "") ? 0 : Convert::ToInt32(textBox_inStock->Text);
		itemsSold = (textBox_ItemPrice->Text == "") ? 0 : Convert::ToInt32(textBox_Sold->Text);
		itemDescription = textBox_Description->Text;
		this->Close();
	}
}