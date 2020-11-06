#pragma once

#include"Person.h"

class Employee : public Person 
{
public:
	Employee();


	/*
		Name:			parameterized constructor
		Description:	constructor
		Parameters:
						@name  the employees name
						@dateOfBirth  the employees date of birth
						@emergencyContact  the employees emergency contact
						@contactInfo  the employees contact information
						@employeeID  the employees identification number 
						@clockedIn  the time the employee clocked in 
						@salary  the amount the employees get paid each year
						@hoursWorkedPerWeek  how many hours the employees work each week
						@experience  the amount of years the employee has worked in their field
	*/
	Employee(std::string name, std::string dateOfBirth, std::string emergencyContact, ContactInformation &contactInfo, std::string employeeID, int clockedIn, double salary, int hoursWorkedPerWeek, int experience);


	/*
		Name:			operator
		Description:	compares two employees by identification number
		Parameters:
						@employee  the employees identity 
	*/
	bool operator==(const Employee &employee);


	/*
		Name:			getEmployeeID
		Description:	Returns employees identification number 
	*/
	std::string getEmployeeID() const;


	/*
		Name:			setEmployeeID
		Description:	sets the employees identification number 
		Parameters:
						@employeeID  the employees identification number
					
	*/
	void setEmployeeID(const std::string employeeID);


	/*
		Name:			getClockedIn
		Description:	Returns the time the employee clocks in 
	*/
	int getClockedIn() const;


	/*
		Name:			setClockedIn
		Description:	sets when the employees clock in
		Parameters:
						@clockedIn  the time the employee clocks in 
	*/
	void setClockedIn(const int clockedIn);


	/*
		Name:			getSalary
		Description:	Returns the amount the employee makes per year
	*/
	double getSalary() const;


	/*
		Name:			setSalary
		Description:	sets the amount the employee makes per year
		Parameters:
						@salary  the amount the employee makes per year
	*/
	void setSalary(const double salary);


	/*
		Name:			getHoursWorkedPerWeek
		Description:	Returns the amount of hours the employee works per week
	*/
	int getHoursWrokedPerWeek() const;


	/*
		Name:			setHoursWorkedPerWeek
		Description:	sets the amount of hours the employee works per week
	*/
	void setHoursWorkedPerWeek(const int hoursWorkedPerWeek);


	/*
		Name:			getExperience
		Description:	Returns the amount of years the employee has worked in their field
	*/
	int getExperience() const;


	/*
		Name:			setExperience
		Description:	sets the amount of years the employee has worked in their field
		Parameters:
						@experience  the amount of years the employee has worked in their field
	*/
	void setExperience(const int experience);
	
private:
	std::string employeeID;
	double salary;
	int clockedIn,
		hoursWorkedPerWeek,
		experience;
};