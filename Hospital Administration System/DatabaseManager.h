#pragma once

#include "Patient.h"
#include "MedicalEmployee.h"
#include "Room.h"
#include "Item.h"
#include <vector>

namespace HospitalAdministrationSystem
{
	using namespace System;
	using namespace System::Data;
	using namespace System::Data::SQLite;
	using namespace System::Collections::Generic;

	public ref class DatabaseManager
	{
	public:
		DatabaseManager();


		/*
			Name:			DatabaseManager
			Description:	Opens or creates database file.
			Parameters:
							@file  the path to the database file.
		
		*/
		DatabaseManager(String ^file);


		/*
			Name:			open
			Description:	Opens the database file, if the file doesn't exist it will be created.
			Parameters:
							@file  the path to the database file.
		
		*/
		bool open(String ^file);


		/*
			Name:			isOpen
			Description:	checks if the file is open
		*/
		bool isOpen();


		/*
			Name:			entryExists
			Description:	checks if the specified entry exists inside the specified table.
			Parameters:
							@table  The table name to search.
							@paramName  The name of the column to search.
							@value  The value to check in the column the column.
		
		*/
		bool entryExists(String ^table, String ^paramName, String ^value);


		/*
			Name:			getPatients
			Description:	returns a vector containing all the patients in the database.
		*/
		std::vector<Patient> getPatients();


		/*
			Name:			getDoctors
			Description:	returns a vector containing all the doctors in the database.
		*/
		std::vector<MedicalEmployee> getDoctors();


		/*
			Name:			getNurses
			Description:  returns a vector containing all the doctors in the database.
		*/
		std::vector<MedicalEmployee> getNurses();


		/*
			Name:			getOtherEmployees
			Description:	returns a vector containing all the non-medical employees in the database.
		*/
		std::vector<Employee> getOtherEmployees();


		/*
			Name:			getRooms
			Description:	returns a vector containing all the non-medical employees in the database.
		*/
		std::vector<Room> getRooms();


		/*
			Name:			getItems
			Description:	returns a vector containing all the items in the database.
		*/
		std::vector<Item> getItems();


		/*
			Name:			getItem
			Description:	returns a vector containing all the items in the database.
			Parameters:
							@itemName  the name of the item to retrieve.
		
		*/
		Item getItem(String ^itemName);

		/*
			Name:			saveItem
			Description:	Stores the inputed item in the database. If the item doesn't exist, it will be created. 
			Parameters:
							@item  The item to store in the database.
	
		*/
		bool saveItem(Item &item);


		/*
			Name:			saveItem
			Description:	Stores the inputed item in the database. If the item doesn't exist, it will be created.
			Parameters:
							@itemName  the name of the item to store.
							@item  The item to store in the database.
		
		*/
		bool saveItem(String ^itemName, Item &item);


		/*
			Name:			saveRoom
			Description:	Stores the inputed room in the database. If the room doesn't exist, it will be created.
			Parameters:
							@room  The room to store in the database.
		
		*/
		bool saveRoom(Room &room);


		/*
			Name:			saveRoom
			Description:	Stores the inputed room in the database. If the room doesn't exist, it will be created.
			Parameters:
							@roomNumber  The room to store in the database
							@room  The room to store in the database.
		
		*/
		bool saveRoom(String ^roomNumber, Room &room);


		/*
			Name:			savePatient
			Description:	Stores the inputed patient in the database. If the patient doesn't exist, they will be created.
			Parameters:
							@patient  The patient to store in the database
		*/
		bool savePatient(Patient &patient);


		/*
			Name:			savePatient
			Description:	Stores the inputed patient in the database. If the patient doesn't exist, they will be created.
			Parameters:
							@patientID  The identification number of the patient to be stored/updated in the database.
							@patient  The patient to store in the database.
		*/
		bool savePatient(String ^patientID, Patient &patient);


		/*
			Name:			saveMedicalEmployee
			Description:	Stores the medical employee in the database. Table can have two values: Doctors, Nurses.
			Parameters:
							@table  The table to store the employee. Can be one of the two values listed above.
							@employee  The employee to store in the database.
		
		*/
		bool saveMedicalEmployee(String ^table, MedicalEmployee &employee);


		/*
			Name:			saveMedicalEmployee
			Description:	Stores the medical employee in the database. Table can have two values: Doctors, Nurses.
			Parameters:
							@employeeID  The identification number of the medical employee.
							@table  The table to store the employee. Can be one of the two values listed above.
							@employee  The employee to store in the database.
		
		*/
		bool saveMedicalEmployee(String ^employeeID, String ^table, MedicalEmployee &employee);


		/*
			Name:			saveEmployee
			Description:	Stores the employee in the database.
			Parameters:
							@employee  The employee to store in the database.
		*/
		bool saveEmployee(Employee &employee);


		/*
			Name:			saveEmployee
			Description:	Stores the employee in the database.
			Parameters:
							@employeeID  The identification number of the employee.
							@employee  The employee to store in the database.
		
		*/
		bool saveEmployee(String ^employeeID, Employee &employee);


		/*
			Name:			removePatientFromRoom
			Description:	Removes a patient from the database based on the inputted identification number.
			Parameters:
							@patientID  The patient identification number of the patient to be removed. 
		*/
		void removePatientFromRoom(String ^patientID);

		/*
			Name:			removeItem
			Description:	Removes the specified item from the database.
			Parameters:
							@itemName  The name of the item to remove.
		
		*/
		void removeItem(String ^itemName);

		/*
			Name:			removeRoom
			Description:	Removes the room from the database.
			Parameters:
							@roomNumber  The room number to remove.
		*/
		void removeRoom(String ^roomNumber);

		/*
			Name:			removePatient
			Description:	Removes the room from the database.
			Parameters:
							@patientID  The patients identification number to remove.
		
		*/
		void removePatient(String ^patientID);

		/*
			Name:			removeMedicalEmployee
			Description:	Removes the medical employee from the database.
			Parameters:
							@table  Can be either Doctors or Nurses.
							@employeeID  employee identification number to remove.
		
		*/
		void removeMedicalEmployee(String ^table, String ^employeeID);



		/*
			Name:			removeEmployee
			Description:	Removes the specified employee from the database.
			Parameters:
							@employeeID  employee identification number to remove.
	
		*/
		void removeEmployee(String ^employeeID);




		/*
			Name:			getPatient
			Description:	Gets the patient from the database specified by the inputted identification
			Parameters:
							@patientID
		
		*/
		Patient getPatient(String ^patientID);

		/*
			Name:			getDoctor
			Description:	gets the doctor from the database. If doctor don;t exist, will return empty class instance.
			Parameters:
							@employeeID  The employee id to search for.
		*/
		MedicalEmployee getDoctor(String ^employeeID);



		/*
			Name:			getNurse
			Description:	gets the nurse from the database. If nurse don't exist, will return empty class instance.
			Parameters:
							@employeeID  The employee id to search for.
		
		*/
		MedicalEmployee getNurse(String ^employeeID);

		/*
			Name:			getOtherEmployee
			Description:	gets non-medical employees from the database. If non-medical employee don't exist, will return empty class instance.
			Parameters:
							@employeeID  The employee id to search for.
		
		*/
		Employee getOtherEmployee(String ^employeeID);

		/*
			Name:			getRoom
			Description:	returns the room from the database.
			Parameters:
							@roomNumber  The number of the room to return.
		*/
		Room getRoom(String ^roomNumber);

		/*
			Name:			clearRoom
			Description:	Clears the patients from the specified room.
			Parameters:
							@roomNumber  The Number of the room to clean.
		*/
		void clearRoom(String ^roomNumber);

		/*
			Name:			getNotifications
			Description:	Gets pending notifications from the database.
		
		*/
		List<String^> ^getNotifications();

		/*
			Name:			addNotification
			Description:	Adds a notification to the notification queue.
			Parameters:
							@priority  The priority of the message. 0 is high priority and higher numbers are lower in the queue.
							@notification  The notification to add.
		
		*/
		bool addNotification(int priority, String ^notification);



		/*
			Name:			removeNotificaiton
			Description:	Removes the notification from the notification queue.
			Parameters:
							@notification  The notification to remove
		*/
		bool removeNotification(String ^notification);

		/*
			Name:			clearNotification
			Description:	Clears all notifications from the notification queue
		*/
		void clearNotifications();

		/*
			Name:			clearMedicalEmployeeFromPatients
			Description:	Clears all patients from the specified medical employee(doctor, nurse).
			Parameters:
							@employeeType  The type of employee to update (Doctors or Nurses).
							@employeeID  The identification number of the medical employee.
		*/
		void clearMedicalEmployeeFromPatients(String ^employeeType, String ^employeeID);

		/*
			Name:			getSqliteDB
			Description:	Returns the SQLiteConnection instance.
		*/
		SQLiteConnection ^getSqliteDB();

	private:
		SQLiteConnection ^sqlLiteDB;
		bool dbOpen;

		/*
			Name:			tableExists
			Description:	Checks if the specified table exists in the database.
			Return:			True if table exists, otherwise returns false.
		*/
		bool tableExists(String ^table);

		/*
			Name:			createTables
			Description:	Creates the tables in the database if they don't exist.
		*/
		void createTables();

		/*
			Name:			getMedicalEmployees
			Description:	Returns a vector containing all the medical employee of the specified type.
			Parameters:
							@employeeType  The employee type to retrieve (Doctors, Nurses).
		*/

		std::vector<MedicalEmployee> getMedicalEmployees(String^ employeeType);

		/*
			Name:			getMedicalEmployee
			Description:	Returns the specified MedicalEmployee by type and identification number.
			Parameters:
							@employeeType  The employee type to retrieve (Doctors, Nurses).
							@employeeID  The identification number of the employee.
		*/
		MedicalEmployee getMedicalEmployee(String^ employeeType, String^ employeeID);
	};
}