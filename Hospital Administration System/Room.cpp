#include "Room.h"

Room::Room() : maxSize(0)
{
}

Room::Room(std::string roomNumber, size_t maxSize)
{
	this->roomNumber = roomNumber;
	this->maxSize = maxSize;
}

bool Room::operator==(const Room & room)
{
	return this->roomNumber == room.roomNumber;
}

std::string Room::getRoomNumber() const
{
	return this->roomNumber;
}

void Room::setRoomNumber(const std::string roomNumber)
{
	this->roomNumber = roomNumber;
}

int Room::getNumPatients() const
{
	return this->patients.size();
}

int Room::getMaxSize() const
{
	return this->maxSize;
}

void Room::setMaxSize(const int maxSize)
{
	this->maxSize = maxSize;
}

std::vector<Patient> Room::getPatients() const
{
	return patients;
}

Patient Room::getPatient(std::string patientID) const
{
	// loops through all patients
	for (Patient p : patients)
	{
		//if p = patientID
		if (p.getPatientID() == patientID)
			//return p
			return p;
	}
	return Patient();
}

bool Room::addPatient(Patient patient)
{
	// loop through all patients
	for (Patient p : patients)
	{
		// if p equals patient returns false
		if (p == patient)
			return false;
	}
	// add patient to patients vector
	patients.push_back(patient);
	return true;
}
// removes a patient from room
bool Room::removePatient(std::string patientID)
{
	// sets size index to 0
	size_t index = 0;
	// loops through all patients
	for (Patient p : patients)
	{
		//if p equals patient ID
		if (p.getPatientID() == patientID)
		{
			// removes patient from list of patients
			patients.erase(patients.begin() + index);
			return true;
		}
		index++;
	}
	return false;
}

void Room::clearRoom()
{
	
	patients.clear();
}
