#include "MedicalEmployee.h"
#include <algorithm>

MedicalEmployee::MedicalEmployee() : degree(""), specialization(""),
	Employee("","","", ContactInformation(),"",0,0.0,0,0)
{
}

MedicalEmployee::MedicalEmployee(std::string name, std::string dateOfBirth, std::string emergencyContact, ContactInformation &contactInfo, std::string employeeID, int clockedIn, double salary, int hoursWorkedPerWeek, int experience, std::string degree, std::string specialization) :
	Employee(name, dateOfBirth, emergencyContact, contactInfo, employeeID, clockedIn, salary, hoursWorkedPerWeek, experience)
{
	this->degree = degree;
	this->specialization = specialization;
}

std::string MedicalEmployee::getDegree() const
{
	return this->degree;
}

void MedicalEmployee::setDegree(const std::string degree)
{
	this->degree = degree;
}

std::string MedicalEmployee::getSpecialization() const
{
	return this->specialization;
}

void MedicalEmployee::setSpecialization(std::string specialization)
{
	this->specialization = specialization;
}

Patient MedicalEmployee::getPatient(std::string patientID) const
{
	// check if the patient id exists in this medical employee's vector
	for (Patient p : patients)
	{
		if (p.getPatientID() == patientID) // if we find the patient, return the patient.
			return p;
	}
	return Patient();// return invalid patient
}

bool MedicalEmployee::addPatient(const Patient patient)
{
	if (!this->hasPatient(patient))
	{
		patients.push_back(patient);
		return true;
	}
	return false;
}

bool MedicalEmployee::removePatient(std::string patientID)
{
	size_t index = 0;
	for (Patient p : patients)
	{
		if (p.getPatientID() == patientID) // if we find the patient, return the patient.
		{
			patients.erase(patients.begin() + index);
			return true;
		}
		index++;
	}
	return false;
}

bool MedicalEmployee::hasPatient(const Patient patient)
{
	for (Patient p : patients)
	{
		if (p == patient) // if we find the patient, return the patient.
			return true;
	}
	return false;
}

std::vector<Patient> MedicalEmployee::getPatients() const
{
	return this->patients;
}

void MedicalEmployee::clearPatients()
{
	patients.clear();
}
