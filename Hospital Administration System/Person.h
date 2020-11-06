#pragma once

#include <string>
#include "ContactInformation.h"

class Person 
{
public:

	/*
	Name:			Parameterized constructor
	Description:	constructor
	Parameters:		
					@name  the patients name
					@dateOfBirth  the persons date of birth
					@emergencyContact  the persons emergency contact information
	*/
	Person(std::string name, std::string dateOfBirth, std::string emergencyContact, ContactInformation contactInfo);




	/*
		Name:			getName
		Description:	Returns persons name
	*/
	std::string getName() const;



	/*
		Name:			setName
		Description:	sets the value of person name
		Parameters:		
						@name  the persons name
	*/
	void setName(const std::string name);



	/*
		Name:			getDateOfBirth
		Description:	Returns persons date of birth
	*/
	std::string getDateOfBirth() const;



	/*
		Name:			setDateOfBirth
		Description:	sets the persons date of birth
		Parameters:		
						@dateOfBirth  the persons date of birth
	*/
	void setDateOfBirth(const std::string dateOfBirth);



	/*
		Name:			getEmergencyConctact
		Description:	Returns the persons emergency contact information 
	*/
	std::string getEmergencyContact() const;



	/*
		Name:			setEmergencyContact
		Description:	sets the persons emergancy contact information
		Parameters:		
						@emergencyContact  the persons emergency contact information 
	*/
	void setEmergencyContact(const std::string emergencyContact);



	/*
		Name:			getContactInfo
		Description:	Returns the persons contact information
		Return:			returns an instance of ContactInformation class
	*/
	ContactInformation getContactInfo() const;



	/*
		Name:			setContactInfo
		Description:	sets the persons contact information 
		Parameters:		
						@contactInfo  the persons contact information
	*/
	void setContactInfo(const ContactInformation &contactInfo);

private:
	std::string name,
		dateOfBirth,
		emergencyContact;

	ContactInformation contactInfo;
};