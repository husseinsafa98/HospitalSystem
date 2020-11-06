#pragma once

#include <string>

class ContactInformation
{
public:
	ContactInformation();


	/*
		Name:			parameterized constructor
		Description:	constructor
		Parameters:
						@address  where the person lives
						@homePhone  the persons home phone number
						@cellphone the persons cellphone number 
						@workPhone  the persons work phone number
						@fax  the persons fax number 
						@email  the persons email address
		
	*/
	ContactInformation(std::string address, std::string homePhone, std::string cellPhone, std::string workPhone, std::string fax, std::string email);


	/*
		Name:			getAddress
		Description:	Returns the persons address
	*/
	std::string getAddress() const;


	/*
		Name:			setAddress
		Description:	sets the persons address
	*/
	void setAddress(const std::string address);


	/*
		Name:			getHomePhone
		Description:	gets the persons home phone number 
	*/
	std::string getHomePhone() const;


	/*
	Name:			setHomePhone
	Description:	sets the persons home phone number 
	Parameters:		
					@homePhone  the persons home phone number 
	*/
	void setHomePhone(const std::string homePhone);


	/*
	Name:			getCellPhone
	Description:	gets the persons cellphone number
	*/
	std::string getCellPhone() const;


	/*
	Name:			setCellPhone
	Description:	sets the persons cellphone number
	Parameters:
					@cellPhone  the persons cellphone number
	*/
	void setCellPhone(const std::string cellPhone);


	/*
	Name:			getWorkPhone
	Description:	gets the persons work phone number
	*/
	std::string getWorkPhone() const;


	/*
	Name:			setWorkPhone
	Description:	sets the persons work phone number 
	Parameters:
					@workPhone  the persons work phone number 
	*/
	void setWorkPhone(const std::string workPhone);


	/*
	Name:			getFaxNumber
	Description:	gets the persons fax number 
	*/
	std::string getFaxNumber() const;


	/*
	Name:			setFaxNumber
	Description:	sets the persons fax number 
	Parameters:
					@fax  the persons fax number 
	*/
	void setFaxNumber(const std::string fax);


	/*
	Name:			getEmail
	Description:	gets the persons email
	*/
	std::string getEmail() const;


	/*
	Name:			setEmail
	Description:	sets the persons email address
	Parameters:
					@email  the persons email address
	*/
	void setEmail(const std::string email);
private:
	std::string address,
		homePhone,
		cellPhone,
		workPhone,
		fax,
		email;
};