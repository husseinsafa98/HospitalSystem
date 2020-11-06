#pragma once

#include<vector>
#include"Patient.h"

class Room
{
public:
	Room();



	/*
		Name:			Constructor.
		Description:	Initialize instance of Room class.
		Parameters:		
						@roomNumber  the room number the patient is staying in 
						@maxSize  the amount of patients the room can hold
	*/
	Room(std::string roomNumber, size_t maxSize);


	/*
		Name:			operator
		Description:	compares two rooms
		Parameter:		
						@room  room being compared
	*/
	bool operator==(const Room & room);



	/*
		Name:			getRoomNumber
		Description:	Returns the number of the room
	*/
	std::string getRoomNumber() const;


	/*
		Name:			setRoomNumber
		Description:	sets the number of the room 
		Parameters:
						@roomNumber  the number of the room
	*/
	void setRoomNumber(const std::string roomNumber);



	/*
		Name:			getNumPatients
		Description:	Returns the number of patients in the room
	*/
	int getNumPatients() const;



	/*
		Name:			getMaxSize
		Description:	Returns the maximum number of patients a room can hold
	*/
	int getMaxSize() const;



	/*
		Name:			setMaxSize
		Description:	sets how many patients a room can hold
		Parameters:		
						@maxSize  the amount of patients a room can hold
	*/
	void setMaxSize(const int maxSize);



	/*
		Name:			getPatients
		Description:	Returns a list of patients that are currently residing in this room.
	*/
	std::vector<Patient> getPatients() const;


	/*
		Name:			getPatient
		Description:	Returns a patient that is currently residing in this room.
		Parameter:
						@patientID  returns an instance of the patient class
	*/
	Patient getPatient(std::string patientID) const;



	/*
		Name:			addPatient
		Description:	Returns whether or not a patient can be added 
		Parameters:		
						@patient  returns an instance of the patient class 
	*/
	bool addPatient(Patient patient);



	/*
		Name:			removePatient
		Description:	Returns if there is a patient to be removed then removes them
		Parameters:		
						@patientID  The patient to remove
	*/
	bool removePatient(std::string patientID);

	/*
	Name:			clearRoom
	Description:	clears out all patients in the room 
	*/
	void clearRoom();
	
private:
	int maxSize;
	std::string roomNumber;
	std::vector<Patient> patients;
};