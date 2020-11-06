#pragma once

#include "Employee.h"
#include "Patient.h"
#include <vector>

class MedicalEmployee : public Employee 
{
public:
	/*
		Name:			MedicalEmployee
		Description
	*/
	MedicalEmployee();


	/*
		Name:			MedicalEmployee
		Description:	constructor
		Parameters:		
						@name  the medical employees name
						@dateOfBirth  the medical employees date of birth
						@emergencyContact  the medical employees emergency contact information
						@contactInfo  the medical employees contact information
						@employeeID  the medical employees identification number
						@clockedIn  the time the medical employee clocked in to work 
						@salary  the amount the medical employee gets paid per year
						@hoursWorkedPerWeek  the amount of hours the medical employee works per week
						@experience  the amount of years the medical employee has worked in that field 
						@degree  the level of education the medical employee has 
						@specialization  the specific field the medical employee works in


	*/
	MedicalEmployee(std::string name, std::string dateOfBirth, std::string emergencyContact, ContactInformation &contactInfo, std::string employeeID, int clockedIn, double salary, int hoursWorkedPerWeek, int experience, std::string degree, std::string specialization);


	/*
	Name:			getDegree
	Description:	Returns medical employees degree

	*/
	std::string getDegree() const;


	/*
	Name:			setDegree
	Description:	sets the medical employees degree
	Parameters:		
					@degree  the level of education the medical employee has 
	*/
	void setDegree(const std::string degree);


	/*
	Name:			getSpecialization
	Description:	Returns the medical employees specialization
	*/
	std::string getSpecialization() const;


	/*
	Name:			setSpecialization
	Description:	sets the medical employees specialization
	Parameters:		
					@specialization  the specific field the medical employee works in
	*/
	void setSpecialization(std::string specialization);


	/*
	Name:			getPatient
	Description:	Returns the patients identification number 
	Parameters:		
					@patientID  returns an instance of Patient class
	*/
	Patient getPatient(std::string patientID) const;


	/*
	Name:			addPatient
	Description:	assigns patient to a medical employee
	Parameters:		
					@patient adds an instance of the patient class
	*/
	bool addPatient(const Patient patient);


	/*
	Name:			removePatient
	Description:	removes patient from a medical employee
	Parameters:		
					patientID  patients identification number 
	*/
	bool removePatient(std::string patientID);


	/*
	Name:			hasPatient
	Description:	
	Parameters:		
					@patient  checks for an instance of class patient
	*/
	bool hasPatient(const Patient patient);


	/*
	Name:			getPatients
	Description:
	*/
	std::vector<Patient> getPatients() const;


	/*
	Name:			clearPatients
	Description:	clears all of the patients assigned to a medical employee
	*/
	void clearPatients();

private:
	std::string degree,
		specialization;
	std::vector<Patient> patients;
};