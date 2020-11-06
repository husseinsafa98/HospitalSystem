#include "Patient.h"
#include "MedicalEmployee.h"

Patient::Patient() : patientID(""), roomNumber(""), doctorID(""), nurseID(""), bill(0.0), ailment(""), insurance(""),
	Person("", "", "", ContactInformation())
{
}

Patient::Patient(std::string name, std::string dateOfBirth, std::string emergencyContact, ContactInformation &contactInfo, std::string patientID, std::string roomNumber, std::string doctorID, std::string nurseID, double bill, std::string ailment, std::string insurance) :
	Person(name, dateOfBirth, emergencyContact, contactInfo)
{
	this->patientID = patientID;
	this->roomNumber = roomNumber;
	this->doctorID = doctorID;
	this->nurseID = nurseID;
	this->bill = bill;
	this->ailment = ailment;
	this->insurance = insurance;
}

bool Patient::operator==(const Patient & patient)
{
	return this->patientID == patient.patientID;
}

std::string Patient::getPatientID() const
{
	return this->patientID;
}

void Patient::setPatientID(const std::string patientID)
{
	this->patientID = patientID;
}

std::string Patient::getRoomNumber() const
{
	return this->roomNumber;
}

void Patient::setRoomNumber(const std::string roomNumber)
{
	this->roomNumber = roomNumber;
}

std::string Patient::getDoctor() const
{
	return this->doctorID;
}

void Patient::setDoctor(const std::string doctor)
{
	this->doctorID = doctor;
}

std::string Patient::getNurse() const
{
	return this->nurseID;
}

void Patient::setNurse(const std::string nurse)
{
	this->nurseID = nurse;
}

double Patient::getBillingInfo() const
{
	return this->bill;
}

void Patient::setBillingInfo(const double bill)
{
	this->bill = bill;
}

std::string Patient::getAilment() const
{
	return this->ailment;
}

void Patient::setAilment(const std::string ailment)
{
	this->ailment = ailment;
}

std::string Patient::getInsurance() const
{
	return this->insurance;
}

void Patient::setInsurance(const std::string insurance)
{
	this->insurance = insurance;
}
