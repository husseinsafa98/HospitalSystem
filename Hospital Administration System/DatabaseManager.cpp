#include "DatabaseManager.h"
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

namespace HospitalAdministrationSystem
{
	DatabaseManager::DatabaseManager()
	{
		this->dbOpen = false;

	}
	DatabaseManager::DatabaseManager(String ^ file)
	{
		this->open(file);
	}
	bool DatabaseManager::open(String ^ file)
	{
		if (!this->dbOpen)
		{
			// Initialize database.
			this->sqlLiteDB = gcnew SQLiteConnection(gcnew SQLiteConnection(file));
			// open database.
			this->sqlLiteDB->Open();
			// check if database opened.
			this->dbOpen = (this->sqlLiteDB->State == ConnectionState::Open);
			if (this->dbOpen && !this->tableExists("Patients"))
				this->createTables(); // create tables if table dont exist(all tables should exists).
		}
		return this->dbOpen; // return state.
	}
	bool DatabaseManager::isOpen()
	{
		return this->dbOpen;
	}
	bool DatabaseManager::entryExists(String ^ table, String ^ paramName, String ^ value)
	{
		if (this->dbOpen)
		{
			// if we can read from the table it exists.
			SQLiteCommand ^command = gcnew SQLiteCommand(String::Format("SELECT * FROM {0} WHERE {1}='{2}';", table, paramName, value), this->sqlLiteDB);
			if (command->ExecuteReader()->Read())
				return true;
		}
		return false;
	}
	std::vector<Patient> DatabaseManager::getPatients()
	{
		std::vector<Patient> patients;
		if (this->dbOpen)
		{
			// run sql command to retrieve patients from the database in ascending order.
			SQLiteCommand ^command = gcnew SQLiteCommand("SELECT * FROM Patients ORDER BY name ASC;", this->sqlLiteDB);
			SQLiteDataReader ^reader = command->ExecuteReader();
			while (reader->Read()) // read all rows
			{
				// populate patient with data from the database.
				Patient patient(msclr::interop::marshal_as<std::string>((String^)reader["name"]),
					msclr::interop::marshal_as<std::string>((String^)reader["dateOfBirth"]),
					msclr::interop::marshal_as<std::string>((String^)reader["emergencyContact"]),
					ContactInformation(msclr::interop::marshal_as<std::string>((String^)reader["address"]),
						msclr::interop::marshal_as<std::string>((String^)reader["homePhone"]),
						msclr::interop::marshal_as<std::string>((String^)reader["cellPhone"]),
						msclr::interop::marshal_as<std::string>((String^)reader["workPhone"]),
						msclr::interop::marshal_as<std::string>((String^)reader["fax"]),
						msclr::interop::marshal_as<std::string>((String^)reader["email"])
					),
					msclr::interop::marshal_as<std::string>((String^)reader["patientID"]),
					msclr::interop::marshal_as<std::string>((String^)reader["roomNumber"]),
					msclr::interop::marshal_as<std::string>((String^)reader["doctor"]),
					msclr::interop::marshal_as<std::string>((String^)reader["nurse"]),
					(double)reader["bill"],
					msclr::interop::marshal_as<std::string>((String^)reader["ailment"]),
					msclr::interop::marshal_as<std::string>((String^)reader["insurance"]));

				patients.push_back(patient); // add patient to the vector
			}
		}

		return patients; // return list of patients in the database
	}
	std::vector<MedicalEmployee> DatabaseManager::getDoctors()
	{
		return getMedicalEmployees("Doctors");
	}
	std::vector<MedicalEmployee> DatabaseManager::getNurses()
	{
		return getMedicalEmployees("Nurses");
	}
	std::vector<Employee> DatabaseManager::getOtherEmployees()
	{
		std::vector<Employee> employees;
		if (this->dbOpen)
		{
			// run sql command to retrieve non medical employees from the database in ascending order.
			SQLiteCommand ^command = gcnew SQLiteCommand("SELECT * FROM OtherEmployees ORDER BY name ASC;", this->sqlLiteDB);
			SQLiteDataReader ^reader = command->ExecuteReader();
			while (reader->Read()) // read all the non medical employees from the database.
			{
				// populate employee with data from the database.
				Employee employee(msclr::interop::marshal_as<std::string>((String^)reader["name"]),
					msclr::interop::marshal_as<std::string>((String^)reader["dateOfBirth"]),
					msclr::interop::marshal_as<std::string>((String^)reader["emergencyContact"]),
					ContactInformation(msclr::interop::marshal_as<std::string>((String^)reader["address"]),
						msclr::interop::marshal_as<std::string>((String^)reader["homePhone"]),
						msclr::interop::marshal_as<std::string>((String^)reader["cellPhone"]),
						msclr::interop::marshal_as<std::string>((String^)reader["workPhone"]),
						msclr::interop::marshal_as<std::string>((String^)reader["fax"]),
						msclr::interop::marshal_as<std::string>((String^)reader["email"])
					),
					msclr::interop::marshal_as<std::string>((String^)reader["employeeID"]),
					(int)reader["clockedIn"],
					(double)reader["salary"],
					(int)reader["hoursWorkedPerWeek"],
					(int)reader["experience"]);

				employees.push_back(employee); // add patient to the vector
			}
		}
		return employees; // Return list of non medical employees in the database
	}
	std::vector<MedicalEmployee> DatabaseManager::getMedicalEmployees(String^ employeeType)
	{
		std::vector<MedicalEmployee> employees;
		if (this->dbOpen)
		{
			// retrieve all medical employees from the database. employeeType contains the table name.
			SQLiteCommand ^command = gcnew SQLiteCommand(String::Format("SELECT * FROM {0} ORDER BY name ASC;", employeeType), this->sqlLiteDB);
			SQLiteDataReader ^reader = command->ExecuteReader();
			while (reader->Read()) // read all rows from the database
			{
				// Populate employee with data from the database.
				MedicalEmployee employee(msclr::interop::marshal_as<std::string>((String^)reader["name"]),
					msclr::interop::marshal_as<std::string>((String^)reader["dateOfBirth"]),
					msclr::interop::marshal_as<std::string>((String^)reader["emergencyContact"]),
					ContactInformation(msclr::interop::marshal_as<std::string>((String^)reader["address"]),
						msclr::interop::marshal_as<std::string>((String^)reader["homePhone"]),
						msclr::interop::marshal_as<std::string>((String^)reader["cellPhone"]),
						msclr::interop::marshal_as<std::string>((String^)reader["workPhone"]),
						msclr::interop::marshal_as<std::string>((String^)reader["fax"]),
						msclr::interop::marshal_as<std::string>((String^)reader["email"])
					),
					msclr::interop::marshal_as<std::string>((String^)reader["employeeID"]),
					(int)reader["clockedIn"],
					(double)reader["salary"],
					(int)reader["hoursWorkedPerWeek"],
					(int)reader["experience"],
					msclr::interop::marshal_as<std::string>((String^)reader["degree"]),
					msclr::interop::marshal_as<std::string>((String^)reader["specialization"]));

				// parse the patient identification numbers by new line delimiter.
				array<String^> ^patients = ((String^)reader["patients"])->Split('\n');
				for (int i = 0; i < patients->Length; i++)
				{
					// add patient to the employee class.
					employee.addPatient(getPatient(patients[i]));
				}

				employees.push_back(employee); // add employee to the list of employees.
			}
		}
		return employees; // return list of employees.
	}
	std::vector<Room> DatabaseManager::getRooms()
	{
		std::vector<Room> rooms;
		if (this->dbOpen)
		{
			// retrieve all rooms from the database in ascending order.
			SQLiteCommand ^command = gcnew SQLiteCommand("SELECT * FROM Rooms ORDER BY roomNumber ASC;", this->sqlLiteDB);
			SQLiteDataReader ^reader = command->ExecuteReader();
			while (reader->Read()) // read all rows
			{
				// populate room with data from the database.
				Room room(msclr::interop::marshal_as<std::string>((String^)reader["roomNumber"]),
					(int)reader["maxSize"]);

				// parse patients
				array<String^> ^patients = ((String^)reader["patients"])->Split('\n');
				for (int i = 0; i < patients->Length; i++)
				{
					if(patients[i] != "")
						room.addPatient(getPatient(patients[i])); // add each patient to the room.
				}

				rooms.push_back(room); // Add the room to the list of rooms.
			}
		}
		return rooms; // return list of rooms.
	}
	std::vector<Item> DatabaseManager::getItems()
	{
		std::vector<Item> items;
		if (this->dbOpen)
		{
			// Get all items in the Inventory.
			SQLiteCommand ^command = gcnew SQLiteCommand("SELECT * FROM Inventory ORDER BY itemName ASC;", this->sqlLiteDB);
			SQLiteDataReader ^reader = command->ExecuteReader();
			while (reader->Read())
			{
				// Populate the item with the item information.
				Item item(msclr::interop::marshal_as<std::string>((String^)reader["itemName"]),
					(double)reader["itemPrice"],
					(int)reader["itemQuantity"],
					(int)reader["amountSold"],
					msclr::interop::marshal_as<std::string>((String^)reader["itemDescription"]));

				items.push_back(item); // Add the item to the database.
			}
		}
		return items; // Return the vector containing the items.
	}

	Item DatabaseManager::getItem(String ^ itemName)
	{
		Item item;
		if (this->dbOpen)
		{
			// Get specific item from the database.
			SQLiteCommand ^command = gcnew SQLiteCommand(String::Format("SELECT * FROM Inventory WHERE itemName='{0}'", itemName), this->sqlLiteDB);
			SQLiteDataReader ^reader = command->ExecuteReader();
			if (reader->Read()) // check if we found the item.
			{
				// populate the item class with the data.
				item = Item(msclr::interop::marshal_as<std::string>((String^)reader["itemName"]),
					(double)reader["itemPrice"],
					(int)reader["itemQuantity"],
					(int)reader["amountSold"],
					msclr::interop::marshal_as<std::string>((String^)reader["itemDescription"]));
			}
		}
		return item; // return the item.
	}

	bool DatabaseManager::saveItem(Item &item)
	{
		return saveItem(gcnew String(item.getItemName().c_str()), item);
	}

	bool DatabaseManager::saveItem(String ^itemName, Item & item)
	{
		// check if the item exists in the database.
		SQLiteCommand ^command = gcnew SQLiteCommand(this->sqlLiteDB);
		if (entryExists("Inventory", "itemName", itemName))
			command->CommandText = String::Format("UPDATE Inventory SET itemName='{0}', itemPrice='{1}', itemQuantity='{2}', amountSold='{3}', itemDescription='{4}' WHERE itemName='{5}';", gcnew String(item.getItemName().c_str()), item.getItemPrice(), item.getQuantity(), item.getSold(), gcnew String(item.getDescription().c_str()), itemName);
		else
		{
			// Create new entry
			command->CommandText = String::Format("INSERT INTO Inventory (itemName, itemPrice, itemQuantity, amountSold, itemDescription) VALUES (@itemName, @itemPrice, @itemQuantity, @amountSold, @itemDescription);");
			command->Parameters->AddWithValue("@itemName", gcnew String(item.getItemName().c_str()));
			command->Parameters->AddWithValue("@itemPrice", item.getItemPrice());
			command->Parameters->AddWithValue("@itemQuantity", item.getQuantity());
			command->Parameters->AddWithValue("@amountSold", item.getSold());
			command->Parameters->AddWithValue("@itemDescription", gcnew String(item.getDescription().c_str()));
		}
		return (command->ExecuteNonQuery() > 0); // return true if the table updated successfully.
	}

	bool DatabaseManager::saveRoom(Room & room)
	{
		return saveRoom(gcnew String(room.getRoomNumber().c_str()), room);
	}

	bool DatabaseManager::saveRoom(String ^ roomNumber, Room & room)
	{
		SQLiteCommand ^command = gcnew SQLiteCommand(this->sqlLiteDB);
		String ^patients = "";

		// store all the patients in the room inside the string patients.
		std::vector<Patient> vPatients = room.getPatients();
		for (size_t i = 0;i< vPatients.size();i++)
		{
			patients += gcnew String(vPatients[i].getPatientID().c_str());
			if (i != (vPatients.size() - 1))
				patients += "\n";
		}
		// if the room exists, update the room.
		if (entryExists("Rooms", "roomNumber", roomNumber))
			command->CommandText = String::Format("UPDATE Rooms SET roomNumber='{0}', maxSize='{1}', patients='{2}' WHERE roomNumber='{3}';", gcnew String(room.getRoomNumber().c_str()), room.getMaxSize(), patients, roomNumber);
		else
		{
			// Insert data into new room.
			command->CommandText = String::Format("INSERT INTO Rooms (roomNumber, maxSize, patients) VALUES (@roomNumber, @maxSize, @patients);");
			command->Parameters->AddWithValue("@roomNumber", gcnew String(room.getRoomNumber().c_str()));
			command->Parameters->AddWithValue("@maxSize", room.getMaxSize());
			command->Parameters->AddWithValue("@patients", patients);
		}
		return (command->ExecuteNonQuery() > 0); // Return true if successful.
	}

	bool DatabaseManager::savePatient(Patient & patient)
	{
		return savePatient(gcnew String(patient.getPatientID().c_str()), patient);
	}

	bool DatabaseManager::savePatient(String ^ patientID, Patient & patient)
	{
		SQLiteCommand ^command = gcnew SQLiteCommand(this->sqlLiteDB);

		// if the entry exists, update the patient.
		if (entryExists("Patients", "patientID", patientID))
			command->CommandText = String::Format("UPDATE Patients SET patientID='{0}', name='{1}', dateOfBirth='{2}', address='{3}', homePhone='{4}', cellPhone='{5}', workPhone='{6}', fax='{7}', email='{8}', emergencyContact='{9}', roomNumber='{10}', doctor='{11}', nurse='{12}', bill='{13}', ailment='{14}', insurance='{15}' WHERE patientID='{16}';", 
				gcnew String(patient.getPatientID().c_str()), 
				gcnew String(patient.getName().c_str()),
				gcnew String(patient.getDateOfBirth().c_str()), 
				gcnew String(patient.getContactInfo().getAddress().c_str()),
				gcnew String(patient.getContactInfo().getHomePhone().c_str()), 
				gcnew String(patient.getContactInfo().getCellPhone().c_str()),
				gcnew String(patient.getContactInfo().getWorkPhone().c_str()), 
				gcnew String(patient.getContactInfo().getFaxNumber().c_str()), 
				gcnew String(patient.getContactInfo().getEmail().c_str()), 
				gcnew String(patient.getEmergencyContact().c_str()), 
				gcnew String(patient.getRoomNumber().c_str()),
				gcnew String(patient.getDoctor().c_str()),
				gcnew String(patient.getNurse().c_str()),
				patient.getBillingInfo(), 
				gcnew String(patient.getAilment().c_str()), 
				gcnew String(patient.getInsurance().c_str()), 
				patientID);
		else
		{
			// insert patient data into database.
			command->CommandText = 
				"INSERT INTO Patients (patientID, name, dateOfBirth, address, homePhone, cellPhone, workPhone," \
				" fax, email, emergencyContact, roomNumber, doctor, nurse, bill, ailment, insurance)" \
				" values (@patientID, @name, @dateOfBirth, @address, @homePhone, @cellPhone, @workPhone, @fax, @email, @emergencyContact," \
				" @roomNumber, @doctor, @nurse, @bill, @ailment, @insurance);";
			command->Parameters->AddWithValue("@patientID", gcnew String(patient.getPatientID().c_str()));
			command->Parameters->AddWithValue("@name", gcnew String(patient.getName().c_str()));
			command->Parameters->AddWithValue("@dateOfBirth", gcnew String(patient.getDateOfBirth().c_str()));
			command->Parameters->AddWithValue("@address", gcnew String(patient.getContactInfo().getAddress().c_str()));
			command->Parameters->AddWithValue("@homePhone", gcnew String(patient.getContactInfo().getHomePhone().c_str()));
			command->Parameters->AddWithValue("@cellPhone", gcnew String(patient.getContactInfo().getCellPhone().c_str()));
			command->Parameters->AddWithValue("@workPhone", gcnew String(patient.getContactInfo().getWorkPhone().c_str()));
			command->Parameters->AddWithValue("@fax", gcnew String(patient.getContactInfo().getFaxNumber().c_str()));
			command->Parameters->AddWithValue("@email", gcnew String(patient.getContactInfo().getEmail().c_str()));
			command->Parameters->AddWithValue("@emergencyContact", gcnew String(patient.getEmergencyContact().c_str()));
			command->Parameters->AddWithValue("@roomNumber", gcnew String(patient.getRoomNumber().c_str()));
			command->Parameters->AddWithValue("@doctor", gcnew String(patient.getDoctor().c_str()));
			command->Parameters->AddWithValue("@nurse", gcnew String(patient.getNurse().c_str()));
			command->Parameters->AddWithValue("@bill", patient.getBillingInfo());
			command->Parameters->AddWithValue("@ailment", gcnew String(patient.getAilment().c_str()));
			command->Parameters->AddWithValue("@insurance", gcnew String(patient.getInsurance().c_str()));
		}
		return (command->ExecuteNonQuery() > 0);
	}

	bool DatabaseManager::saveMedicalEmployee(String ^table, MedicalEmployee & employee)
	{
		return saveMedicalEmployee(gcnew String(employee.getEmployeeID().c_str()), table, employee);
	}

	bool DatabaseManager::saveMedicalEmployee(String ^ employeeID, String ^table, MedicalEmployee & employee)
	{
		SQLiteCommand ^command = gcnew SQLiteCommand(this->sqlLiteDB);

		// get all the patients from the medical employee 
		String ^patients = "";
		std::vector<Patient> vPatients = employee.getPatients();
		for (size_t i = 0; i < vPatients.size(); i++)
		{
			if (vPatients[i].getPatientID() == "")
				continue;
			patients += gcnew String(vPatients[i].getPatientID().c_str());
			if (i != (vPatients.size() - 1))
				patients += "\n";
		}

		// if the employee exists, add them to the database.
		if (entryExists(table, "employeeID", employeeID))
			command->CommandText = String::Format("UPDATE {0} SET employeeID='{1}', clockedIn='{2}', salary='{3}', hoursWorkedPerWeek='{4}'," \
				" experience='{5}', degree='{6}', specialization='{7}', patients='{8}', name='{9}', dateOfBirth='{10}', address='{11}'," \
				" homePhone='{12}', cellPhone='{13}', workPhone='{14}', fax='{15}', email='{16}', emergencyContact='{17}'" \
				" WHERE employeeID='{18}';",
				table,
				gcnew String(employee.getEmployeeID().c_str()),
				employee.getClockedIn(),
				employee.getSalary(),
				employee.getHoursWrokedPerWeek(),
				employee.getExperience(),
				gcnew String(employee.getDegree().c_str()),
				gcnew String(employee.getSpecialization().c_str()),
				patients,
				gcnew String(employee.getName().c_str()),
				gcnew String(employee.getDateOfBirth().c_str()),
				gcnew String(employee.getContactInfo().getAddress().c_str()),
				gcnew String(employee.getContactInfo().getHomePhone().c_str()),
				gcnew String(employee.getContactInfo().getCellPhone().c_str()),
				gcnew String(employee.getContactInfo().getWorkPhone().c_str()),
				gcnew String(employee.getContactInfo().getFaxNumber().c_str()),
				gcnew String(employee.getContactInfo().getEmail().c_str()),
				gcnew String(employee.getEmergencyContact().c_str()),
				employeeID);
		else
		{
			// Add employee to the database.
			command->CommandText =
				String::Format("INSERT INTO {0} (employeeID, clockedIn, salary, hoursWorkedPerWeek," \
				" experience, degree, specialization, patients, name, dateOfBirth, address," \
				" homePhone, cellPhone, workPhone, fax, email, emergencyContact) values (@employeeID, @clockedIn, @salary, @hoursWorkedPerWeek," \
				" @experience, @degree, @specialization, @patients, @name, @dateOfBirth, @address," \
				" @homePhone, @cellPhone, @workPhone, @fax, @email, @emergencyContact);"
				, table);
			command->Parameters->AddWithValue("@employeeID", gcnew String(employee.getEmployeeID().c_str()));
			command->Parameters->AddWithValue("@clockedIn", employee.getClockedIn());
			command->Parameters->AddWithValue("@salary", employee.getSalary());
			command->Parameters->AddWithValue("@hoursWorkedPerWeek", employee.getHoursWrokedPerWeek());
			command->Parameters->AddWithValue("@experience", employee.getExperience());
			command->Parameters->AddWithValue("@degree", gcnew String(employee.getDegree().c_str()));
			command->Parameters->AddWithValue("@specialization", gcnew String(employee.getSpecialization().c_str()));
			command->Parameters->AddWithValue("@patients", patients);
			command->Parameters->AddWithValue("@name", gcnew String(employee.getName().c_str()));
			command->Parameters->AddWithValue("@dateOfBirth", gcnew String(employee.getDateOfBirth().c_str()));
			command->Parameters->AddWithValue("@address", gcnew String(employee.getContactInfo().getAddress().c_str()));
			command->Parameters->AddWithValue("@homePhone", gcnew String(employee.getContactInfo().getHomePhone().c_str()));
			command->Parameters->AddWithValue("@cellPhone", gcnew String(employee.getContactInfo().getCellPhone().c_str()));
			command->Parameters->AddWithValue("@workPhone", gcnew String(employee.getContactInfo().getWorkPhone().c_str()));
			command->Parameters->AddWithValue("@fax", gcnew String(employee.getContactInfo().getFaxNumber().c_str()));
			command->Parameters->AddWithValue("@email", gcnew String(employee.getContactInfo().getEmail().c_str()));
			command->Parameters->AddWithValue("@emergencyContact", gcnew String(employee.getEmergencyContact().c_str()));
		}
		return (command->ExecuteNonQuery() > 0); // return true if successful.
	}

	bool DatabaseManager::saveEmployee(Employee & employee)
	{
		return this->saveEmployee(gcnew String(employee.getEmployeeID().c_str()), employee);
	}

	bool DatabaseManager::saveEmployee(String ^ employeeID, Employee & employee)
	{
		SQLiteCommand ^command = gcnew SQLiteCommand(this->sqlLiteDB);

		// check if the entry exists, if so update them.
		if (entryExists("OtherEmployees", "employeeID", employeeID))
			command->CommandText = String::Format("UPDATE OtherEmployees SET employeeID='{0}', clockedIn='{1}', salary='{2}', hoursWorkedPerWeek='{3}'," \
				" experience='{4}', name='{5}', dateOfBirth='{6}', address='{7}'," \
				" homePhone='{8}', cellPhone='{9}', workPhone='{10}', fax='{11}', email='{12}', emergencyContact='{13}'" \
				" WHERE employeeID='{14}';",
				gcnew String(employee.getEmployeeID().c_str()),
				employee.getClockedIn(),
				employee.getSalary(),
				employee.getHoursWrokedPerWeek(),
				employee.getExperience(),
				gcnew String(employee.getName().c_str()),
				gcnew String(employee.getDateOfBirth().c_str()),
				gcnew String(employee.getContactInfo().getAddress().c_str()),
				gcnew String(employee.getContactInfo().getHomePhone().c_str()),
				gcnew String(employee.getContactInfo().getCellPhone().c_str()),
				gcnew String(employee.getContactInfo().getWorkPhone().c_str()),
				gcnew String(employee.getContactInfo().getFaxNumber().c_str()),
				gcnew String(employee.getContactInfo().getEmail().c_str()),
				gcnew String(employee.getEmergencyContact().c_str()),
				employeeID);
		else
		{
			// Create employee and add data.
			command->CommandText =
				"INSERT INTO OtherEmployees (employeeID, clockedIn, salary, hoursWorkedPerWeek," \
					" experience, name, dateOfBirth, address," \
					" homePhone, cellPhone, workPhone, fax, email, emergencyContact) values (@employeeID, @clockedIn, @salary, @hoursWorkedPerWeek," \
					" @experience, @name, @dateOfBirth, @address," \
					" @homePhone, @cellPhone, @workPhone, @fax, @email, @emergencyContact);";
			command->Parameters->AddWithValue("@employeeID", gcnew String(employee.getEmployeeID().c_str()));
			command->Parameters->AddWithValue("@clockedIn", employee.getClockedIn());
			command->Parameters->AddWithValue("@salary", employee.getSalary());
			command->Parameters->AddWithValue("@hoursWorkedPerWeek", employee.getHoursWrokedPerWeek());
			command->Parameters->AddWithValue("@experience", employee.getExperience());
			command->Parameters->AddWithValue("@name", gcnew String(employee.getName().c_str()));
			command->Parameters->AddWithValue("@dateOfBirth", gcnew String(employee.getDateOfBirth().c_str()));
			command->Parameters->AddWithValue("@address", gcnew String(employee.getContactInfo().getAddress().c_str()));
			command->Parameters->AddWithValue("@homePhone", gcnew String(employee.getContactInfo().getHomePhone().c_str()));
			command->Parameters->AddWithValue("@cellPhone", gcnew String(employee.getContactInfo().getCellPhone().c_str()));
			command->Parameters->AddWithValue("@workPhone", gcnew String(employee.getContactInfo().getWorkPhone().c_str()));
			command->Parameters->AddWithValue("@fax", gcnew String(employee.getContactInfo().getFaxNumber().c_str()));
			command->Parameters->AddWithValue("@email", gcnew String(employee.getContactInfo().getEmail().c_str()));
			command->Parameters->AddWithValue("@emergencyContact", gcnew String(employee.getEmergencyContact().c_str()));
		}
		return (command->ExecuteNonQuery() > 0); // return true if successful.
	} 

	void DatabaseManager::removePatientFromRoom(String ^patientID)
	{
		//get patient from id
		Patient patient = getPatient(patientID);

		// get room from patient room number.
		Room room = getRoom(gcnew String(patient.getRoomNumber().c_str()));
		// remove patient from room
		room.removePatient(msclr::interop::marshal_as<std::string>(patientID));
		// clear patient room number.
		patient.setRoomNumber("");
		saveRoom(room); // Save room to database.
		savePatient(patient);// save patient to database.
	}

	void DatabaseManager::removeItem(String ^ itemName)
	{
		(gcnew SQLiteCommand(String::Format("DELETE FROM Inventory WHERE itemName='{0}';", itemName), this->sqlLiteDB))->ExecuteNonQuery();
	}

	void DatabaseManager::removeRoom(String ^ roomNumber)
	{
		clearRoom(roomNumber);
		(gcnew SQLiteCommand(String::Format("DELETE FROM Rooms WHERE roomNumber='{0}';", roomNumber), this->sqlLiteDB))->ExecuteNonQuery();
	}

	void DatabaseManager::removePatient(String ^ patientID)
	{
		//TODO: remove patient from medical employee before deleting.
		(gcnew SQLiteCommand(String::Format("DELETE FROM Patients WHERE patientID='{0}';", patientID), this->sqlLiteDB))->ExecuteNonQuery();
	}

	void DatabaseManager::removeMedicalEmployee(String ^table, String ^ employeeID)
	{
		(gcnew SQLiteCommand(String::Format("DELETE FROM {0} WHERE employeeID='{1}';UPDATE Patients SET {2}='' WHERE {2}='{1}';", table, employeeID, (table == "Doctors") ? "doctor" : "nurse"), this->sqlLiteDB))->ExecuteNonQuery();
	}

	void DatabaseManager::removeEmployee(String ^ employeeID)
	{
		(gcnew SQLiteCommand(String::Format("DELETE FROM OtherEmployees WHERE patientID='{0}';", employeeID), this->sqlLiteDB))->ExecuteNonQuery();
	}

	Patient DatabaseManager::getPatient(String ^ patientID)
	{
		Patient patient;
		// get a patient by their identification number.
		SQLiteCommand ^command = gcnew SQLiteCommand(String::Format("SELECT * FROM Patients WHERE patientID='{0}';",patientID), this->sqlLiteDB);
		SQLiteDataReader ^reader = command->ExecuteReader();
		if (reader->Read()) // check if we found a match
		{
			// populate patient class.
			patient = Patient(msclr::interop::marshal_as<std::string>((String^)reader["name"]),
				msclr::interop::marshal_as<std::string>((String^)reader["dateOfBirth"]),
				msclr::interop::marshal_as<std::string>((String^)reader["emergencyContact"]),
				ContactInformation(msclr::interop::marshal_as<std::string>((String^)reader["address"]),
					msclr::interop::marshal_as<std::string>((String^)reader["homePhone"]),
					msclr::interop::marshal_as<std::string>((String^)reader["cellPhone"]),
					msclr::interop::marshal_as<std::string>((String^)reader["workPhone"]),
					msclr::interop::marshal_as<std::string>((String^)reader["fax"]),
					msclr::interop::marshal_as<std::string>((String^)reader["email"])
				),
				msclr::interop::marshal_as<std::string>((String^)reader["patientID"]),
				msclr::interop::marshal_as<std::string>((String^)reader["roomNumber"]),
				msclr::interop::marshal_as<std::string>((String^)reader["doctor"]),
				msclr::interop::marshal_as<std::string>((String^)reader["nurse"]),
				(double)reader["bill"],
				msclr::interop::marshal_as<std::string>((String^)reader["ailment"]),
				msclr::interop::marshal_as<std::string>((String^)reader["insurance"]));
		}
		return patient; // return patient
	}
	MedicalEmployee DatabaseManager::getDoctor(String ^ employeeID)
	{
		return getMedicalEmployee("Doctors", employeeID);
	}
	MedicalEmployee DatabaseManager::getNurse(String ^ employeeID)
	{
		return getMedicalEmployee("Nurses", employeeID);
	}
	Employee DatabaseManager::getOtherEmployee(String ^ employeeID)
	{
		Employee employee;
		// get employee by their identification number.
		SQLiteCommand ^command = gcnew SQLiteCommand(String::Format("SELECT * FROM OtherEmployees WHERE employeeID='{0}';", employeeID), this->sqlLiteDB);
		SQLiteDataReader ^reader = command->ExecuteReader();
		if (reader->Read()) // check if we found the employee.
		{
			// Populate the employee class.
			employee = Employee(msclr::interop::marshal_as<std::string>((String^)reader["name"]),
				msclr::interop::marshal_as<std::string>((String^)reader["dateOfBirth"]),
				msclr::interop::marshal_as<std::string>((String^)reader["emergencyContact"]),
				ContactInformation(msclr::interop::marshal_as<std::string>((String^)reader["address"]),
					msclr::interop::marshal_as<std::string>((String^)reader["homePhone"]),
					msclr::interop::marshal_as<std::string>((String^)reader["cellPhone"]),
					msclr::interop::marshal_as<std::string>((String^)reader["workPhone"]),
					msclr::interop::marshal_as<std::string>((String^)reader["fax"]),
					msclr::interop::marshal_as<std::string>((String^)reader["email"])
				),
				msclr::interop::marshal_as<std::string>((String^)reader["employeeID"]),
				(int)reader["clockedIn"],
				(double)reader["salary"],
				(int)reader["hoursWorkedPerWeek"],
				(int)reader["experience"]
			);
		}
		return employee; // return employee
	}
	Room DatabaseManager::getRoom(String ^ roomNumber)
	{
		Room room;
		// get room from room number.
		SQLiteCommand ^command = gcnew SQLiteCommand(String::Format("SELECT * FROM Rooms WHERE roomNumber='{0}';", roomNumber), this->sqlLiteDB);
		SQLiteDataReader ^reader = command->ExecuteReader();
		if (reader->Read()) // check if we found the room.
		{
			// populate the room with the data.
			room = Room(msclr::interop::marshal_as<std::string>((String^)reader["roomNumber"]),
				(int)reader["maxSize"]);

			// add all patients to the room.
			array<String^> ^patients = ((String^)reader["patients"])->Split('\n');
			for (int i = 0; i < patients->Length; i++)
			{
				if(patients[i] != "")
					room.addPatient(getPatient(patients[i]));
			}
		}
		return room; // return room.
	}
	void DatabaseManager::clearRoom(String ^roomNumber)
	{
		(gcnew SQLiteCommand(String::Format("UPDATE Patients SET roomNumber='' WHERE roomNumber='{0}';UPDATE Rooms SET patients='' WHERE roomNumber='{0}';", roomNumber), this->sqlLiteDB))->ExecuteNonQuery();
	}
	List<String^> ^DatabaseManager::getNotifications()
	{
		List<String^> ^notifications = gcnew List<String^>();

		SQLiteCommand ^cmd = gcnew SQLiteCommand("SELECT * FROM Notifications ORDER BY priority ASC", this->sqlLiteDB);
		SQLiteDataReader ^reader = cmd->ExecuteReader();
		while (reader->Read())
		{
			notifications->Add((String^)reader["message"]);
		}
		return notifications;
	}
	bool DatabaseManager::addNotification(int priority, String ^notification)
	{
		SQLiteCommand ^cmd = gcnew SQLiteCommand("INSERT INTO Notifications (priority, message) values (@priority, @message)", this->sqlLiteDB);
		cmd->Parameters->AddWithValue("@priority", priority);
		cmd->Parameters->AddWithValue("@message", notification);
		return (cmd->ExecuteNonQuery() > 0);
	}
	bool DatabaseManager::removeNotification(String ^notification)
	{
		return (gcnew SQLiteCommand(String::Format("DELETE FROM Notifications WHERE message='{0}';", notification), this->sqlLiteDB))->ExecuteNonQuery() > 0;
	}
	void DatabaseManager::clearNotifications()
	{
		(gcnew SQLiteCommand("DELETE FROM Notifications", this->sqlLiteDB))->ExecuteNonQuery();
	}
	void DatabaseManager::clearMedicalEmployeeFromPatients(String ^ employeeType, String ^ employeeID)
	{
		(gcnew SQLiteCommand(String::Format("UPDATE Patients set {0}='' WHERE {0}='{1}'", employeeType, employeeID), this->sqlLiteDB))->ExecuteNonQuery();
	}
	SQLiteConnection ^ DatabaseManager::getSqliteDB()
	{
		return this->sqlLiteDB;
	}
	void DatabaseManager::createTables()
	{
		(gcnew SQLiteCommand("CREATE TABLE IF NOT EXISTS Patients (patientID VARCHAR(8), name VARCHAR(32), dateOfBirth VARCHAR(10), address VARCHAR(80), homePhone VARCHAR(10), cellPhone VARCHAR(10), workPhone VARCHAR(10), fax VARCHAR(10), email VARCHAR(320), emergencyContact VARCHAR(32), roomNumber VARCHAR(4), doctor VARCHAR(8), nurse VARCHAR(8), bill DOUBLE, ailment VARCHAR(100), insurance VARCHAR(32));" \
			"CREATE TABLE IF NOT EXISTS Doctors (employeeID VARCHAR(8), clockedIn INT, salary DOUBLE, hoursWorkedPerWeek INT, experience INT, degree VARCHAR(20), specialization VARCHAR(20), patients TEXT, name VARCHAR(32), dateOfBirth VARCHAR(10), address VARCHAR(80), homePhone VARCHAR(10), cellPhone VARCHAR(10), workPhone VARCHAR(10), fax VARCHAR(10), email VARCHAR(320), emergencyContact VARCHAR(32));" \
			"CREATE TABLE IF NOT EXISTS Nurses (employeeID VARCHAR(8), clockedIn INT, salary DOUBLE, hoursWorkedPerWeek INT, experience INT, degree VARCHAR(20), specialization VARCHAR(20), patients TEXT, name VARCHAR(32), dateOfBirth VARCHAR(10), address VARCHAR(80), homePhone VARCHAR(10), cellPhone VARCHAR(10), workPhone VARCHAR(10), fax VARCHAR(10), email VARCHAR(320), emergencyContact VARCHAR(32));" \
			"CREATE TABLE IF NOT EXISTS OtherEmployees (employeeID VARCHAR(8), clockedIn INT, salary DOUBLE, hoursWorkedPerWeek INT, experience INT, name VARCHAR(32), dateOfBirth VARCHAR(10), address VARCHAR(80), homePhone VARCHAR(10), cellPhone VARCHAR(10), workPhone VARCHAR(10), fax VARCHAR(10), email VARCHAR(320), emergencyContact VARCHAR(32));" \
			"CREATE TABLE IF NOT EXISTS Rooms (roomNumber VARCHAR(4), maxSize INT, patients TEXT);" \
			"CREATE TABLE IF NOT EXISTS Inventory (itemName VARCHAR(20), itemPrice DOUBLE, itemDescription VARCHAR(50), itemQuantity INT, amountSold INT);" \
			"CREATE TABLE IF NOT EXISTS Notifications(priority INT, message TEXT);",
			this->sqlLiteDB))->ExecuteNonQuery();
	}
	MedicalEmployee DatabaseManager::getMedicalEmployee(String ^ employeeType, String ^ employeeID)
	{
		MedicalEmployee employee;
		// read the specified employee from the database.
		SQLiteCommand ^command = gcnew SQLiteCommand(String::Format("SELECT * FROM {0} WHERE employeeID='{1}';", employeeType, employeeID), this->sqlLiteDB);
		SQLiteDataReader ^reader = command->ExecuteReader();
		if (reader->Read()) // if we can read, we found the employee.
		{
			// Populate employee with employee information.
			employee = MedicalEmployee(msclr::interop::marshal_as<std::string>((String^)reader["name"]),
				msclr::interop::marshal_as<std::string>((String^)reader["dateOfBirth"]),
				msclr::interop::marshal_as<std::string>((String^)reader["emergencyContact"]),
				ContactInformation(msclr::interop::marshal_as<std::string>((String^)reader["address"]),
					msclr::interop::marshal_as<std::string>((String^)reader["homePhone"]),
					msclr::interop::marshal_as<std::string>((String^)reader["cellPhone"]),
					msclr::interop::marshal_as<std::string>((String^)reader["workPhone"]),
					msclr::interop::marshal_as<std::string>((String^)reader["fax"]),
					msclr::interop::marshal_as<std::string>((String^)reader["email"])
				),
				msclr::interop::marshal_as<std::string>((String^)reader["employeeID"]),
				(int)reader["clockedIn"],
				(double)reader["salary"],
				(int)reader["hoursWorkedPerWeek"],
				(int)reader["experience"],
				msclr::interop::marshal_as<std::string>((String^)reader["degree"]),
				msclr::interop::marshal_as<std::string>((String^)reader["specialization"]));

			// add all patients to the employee.
			array<String^> ^patients = ((String^)reader["patients"])->Split('\n');
			for (int i = 0; i < patients->Length; i++)
			{
				employee.addPatient(getPatient(patients[i]));
			}
		}
		return employee; // return employee.
	}
	bool DatabaseManager::tableExists(String ^table)
	{
		// check if the specified table exists in the database.
		SQLiteCommand ^command = gcnew SQLiteCommand(String::Format("SELECT COUNT(*) FROM sqlite_master WHERE type = 'table' AND name ='{0}'", table), this->sqlLiteDB);
		return (int::Parse(command->ExecuteScalar()->ToString()) != 0);
	}
}