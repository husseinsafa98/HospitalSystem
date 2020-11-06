#include "ContactInformation.h"

ContactInformation::ContactInformation() : address(""), homePhone(""), cellPhone(""), workPhone(""), fax(""), email("")
{
}

ContactInformation::ContactInformation(std::string address, std::string homePhone, std::string cellPhone, std::string workPhone, std::string fax, std::string email)
{
	this->address = address;
	this->homePhone = homePhone;
	this->cellPhone = cellPhone;
	this->workPhone = workPhone;
	this->fax = fax;
	this->email = email;
}

std::string ContactInformation::getAddress() const
{
	return this->address;
}

void ContactInformation::setAddress(const std::string address)
{
	this->address = address;
}

std::string ContactInformation::getHomePhone() const
{
	return this->homePhone;
}

void ContactInformation::setHomePhone(const std::string homePhone)
{
	this->homePhone = homePhone;
}

std::string ContactInformation::getCellPhone() const
{
	return this->cellPhone;
}

void ContactInformation::setCellPhone(const std::string cellPhone)
{
	this->cellPhone = cellPhone;
}

std::string ContactInformation::getWorkPhone() const
{
	return this->workPhone;
}

void ContactInformation::setWorkPhone(const std::string workPhone)
{
	this->workPhone = workPhone;
}

std::string ContactInformation::getFaxNumber() const
{
	return this->fax;
}

void ContactInformation::setFaxNumber(const std::string fax)
{
	this->fax = fax;
}

std::string ContactInformation::getEmail() const
{
	return this->email;
}

void ContactInformation::setEmail(const std::string email)
{
	this->email = email;
}
