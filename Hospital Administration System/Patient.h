#pragma once

#include"Person.h"

class Patient : public Person 
{
public:

	Patient();



	/*
		Name:			Parameterized constructor
		Description:	constructor
		Parameters:		
						@name  patients name
						@dateOfBirth  patients date of birth
						@emergencyContact	patients emergency contact information
						@&contactInfo  the contact information of the patient
						@patientID  the patients identificaton number
						@roomNumber  the patients room number
						@doctorID  the patients doctors identification number
						@nurseID  the patients nurses identification number
						@bill  the patients hospital bill
						@ailment  what the patient is in the hospital for 
						@insurance  the patients medical insurance
		
						
	*/
	Patient(std::string name, std::string dateOfBirth, std::string emergencyContact, ContactInformation &contactInfo, std::string patientID, std::string roomNumber, std::string doctorID, std::string nurseID, double bill, std::string ailment, std::string insurance);
	


	/*
		Name:			operator
		Description:	compares two patients by identification number
		Parameters:		
						@patient  patient being compared
	*/
	bool operator==(const Patient &patient);



	/*
		Name:			getPatientID
		Description:	Returns Patient's ID
	*/
	std::string getPatientID() const;
	


	/*
		Name:			setPatientID
		Description:	Sets The Value Of PatientsID
		Parameters:		
						@patientID  the patients identification number
	*/
	void setPatientID(const std::string patientID);
	


	/*
		Name:			getRoomNumber
		Description:	Returns Patient's ID
	*/
	std::string getRoomNumber() const;
	


	/*
		Name:			setRoomNumber
		Description:	Sets The Value Of RoomNumber
		Parameters:		
						@roomNumber the patients room number
	*/
	void setRoomNumber(const std::string roomNumber);
	


	/*
		Name:			getDoctor
		Description:	Returns the Employee ID of the patients doctor.
	*/
	std::string getDoctor() const;
	


	/*
		Name:			setDoctor
		Description:	Sets the patient to a Doctor
		Parameters:		
						@doctor  The patients doctor's employee ID.
	*/
	void setDoctor(const std::string doctor);
	



	/*
		Name:			getNurse
		Description:	Returns Nurse
	*/
	std::string getNurse() const;
	



	/*
		Name:			setNurse
		Description:	Sets the patient to a Nurse
		Parameters:		
						@nurse the patients nurse
	*/
	void setNurse(const std::string nurse);
	



	/*
		Name:			getBillingInfo
		Description:	Returns BillingInfo
	*/
	double getBillingInfo() const;
	



	/*
		Name:			setBillingInfo
		Description:	Sets the BillingInfo
		Parameters:		
						@bill  the patients hospital bill 
	*/
	void setBillingInfo(const double bill);
	



	/*
		Name:			getAilment
		Description:	Returns Ailment
	*/
	std::string getAilment() const;
	



	/*
		Name:			setAilment
		Description:	Sets the Ailment of patient
		Parameters:		
						@ailment  what the patient is in the hospital for 
	*/
	void setAilment(const std::string ailment);
	



	/*
		Name:			getInsurance
		Description:	Returns Insurance
	*/
	std::string getInsurance() const;
	



	/*
		Name:			setInsurance
		Description:	Sets the Insurance
		Parameters:		
						@insurance  the patients medical insurance
	*/
	void setInsurance(const std::string insurance);

private:
	double bill;
	std::string patientID,
		roomNumber,
		ailment, 
		insurance,
		doctorID,
		nurseID;

};