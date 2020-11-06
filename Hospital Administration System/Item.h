#pragma once

#include <string>

class Item
{
public:
	Item();


	/*
	Name:			parameterized constructor
	Description:	constructor
	Parameters:
					@itemName  the name of an item
					@itemPrice  how much that item costs
					@quantity  how much of that item is in stock
					@sold  how much of that item has been sold
					@description
	*/
	Item(std::string itemName, double itemPrice, int quantity, int sold,  std::string description);


	/*
	Name:			getItemName
	Description:	Returns the name of the item
	*/
	std::string getItemName() const;


	/*
	Name:			setItemName
	Description:	sets the item name
	*/
	void setItemName(const std::string itemName);


	/*
	Name:			getItemPrice
	Description:	Returns the price of the item
	*/
	double getItemPrice() const;


	/*
	Name:			setItemDescription
	Description:	sets the description of the item
	Parameters:
					@itemPrice  the price of the item
	*/
	void setItemDescription(const double itemPrice);


	/*
	Name:			getQuantity
	Description:	Returns the amount of items
	*/
	int getQuantity() const;


	/*
	Name:			setQuantity
	Description:	sets the amount of the item
	Parameters:
					@quantity  how much of that item is in stock
	*/
	void setQuantity(const int quantity);


	/*
	Name:			getSold
	Description:	Returns the amount of the item that has been sold
	*/
	int getSold() const;


	/*
	Name:			setSold
	Description:	sets the amount of the item that has been sold
	Parameters:		
					@sold  how much of the item has been sold
	*/
	void setSold(const int sold);


	/*
	Name:			getDescription
	Description:	Returns the description of the item 
	*/
	std::string getDescription() const;


	/*
	Name:			setDescription
	Description:	sets the description of the item
	*/
	void setDescription(const std::string discription);
private:
	std::string itemName,
		description;
	double itemPrice;
	int quantity,
		sold;
};