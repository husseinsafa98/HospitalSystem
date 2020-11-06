#include "Person.h"

Person::Person(std::string name, std::string dateOfBirth, std::string emergencyContact, ContactInformation contactInfo)
{
	this->name = name;
	this->dateOfBirth = dateOfBirth;
	this->contactInfo = contactInfo;
	this->emergencyContact = emergencyContact;
}

std::string Person::getName() const
{
	return this->name;
}

void Person::setName(const std::string name)
{
	this->name = name;
}


std::string Person::getDateOfBirth() const
{
	return this->dateOfBirth;
}

void Person::setDateOfBirth(const std::string dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}

ContactInformation Person::getContactInfo() const
{
	return this->contactInfo;
}

void Person::setContactInfo(const ContactInformation & contactInfo)
{
	this->contactInfo = contactInfo;
}

std::string Person::getEmergencyContact() const
{
	return this->emergencyContact;
}

void Person::setEmergencyContact(const std::string emergencyContact)
{
	this->emergencyContact = emergencyContact;
}