#include "Item.h"

Item::Item() : itemName(""), itemPrice(0.0), quantity(0), description("")
{
}

Item::Item(std::string itemName, double itemPrice, int quantity, int sold, std::string discription)
{
	this->itemName = itemName;
	this->itemPrice = itemPrice;
	this->quantity = quantity;
	this->description = discription;
	this->sold = sold;
}

std::string Item::getItemName() const
{
	return this->itemName;
}

void Item::setItemName(const std::string itemName)
{
	this->itemName = itemName;
}

double Item::getItemPrice() const
{
	return this->itemPrice;
}

void Item::setItemDescription(const double itemPrice)
{
	this->itemPrice = itemPrice;
}

int Item::getQuantity() const
{
	return this->quantity;
}

void Item::setQuantity(const int quantity)
{
	this->quantity = quantity;
}

int Item::getSold() const
{
	return this->sold;
}

void Item::setSold(const int sold)
{
	this->sold = sold;
}

std::string Item::getDescription() const
{
	return this->description;
}

void Item::setDescription(const std::string discription)
{
	this->description = discription;
}
