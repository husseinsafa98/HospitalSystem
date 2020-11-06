#include "Employee.h"

Employee::Employee() :
	Person("", "", "",ContactInformation())
{
}

Employee::Employee(std::string name, std::string dateOfBirth, std::string emergencyContact, ContactInformation &contactInfo, std::string employeeID, int clockedIn, double salary, int hoursWorkedPerWeek, int experience) :
	Person(name,dateOfBirth,emergencyContact,contactInfo)
{
	this->employeeID = employeeID;
	this->clockedIn = clockedIn;
	this->salary = salary;
	this->hoursWorkedPerWeek = hoursWorkedPerWeek;
	this->experience = experience;
}

bool Employee::operator==(const Employee & employee)
{
	return this->employeeID == employee.employeeID;
}

std::string Employee::getEmployeeID() const
{
	return this->employeeID;
}

void Employee::setEmployeeID(const std::string employeeID)
{
	this->employeeID = employeeID;
}

int Employee::getClockedIn() const
{
	return this->clockedIn;
}

void Employee::setClockedIn(const int clockedIn)
{
	this->clockedIn = clockedIn;
}

double Employee::getSalary() const
{
	return this->salary;
}

void Employee::setSalary(const double salary)
{
	this->salary = salary;
}

int Employee::getHoursWrokedPerWeek() const
{
	return this->hoursWorkedPerWeek;
}

void Employee::setHoursWorkedPerWeek(const int hoursWorkedPerWeek)
{
	this->hoursWorkedPerWeek = hoursWorkedPerWeek;
}

int Employee::getExperience() const
{
	return this->experience;
}

void Employee::setExperience(const int experience)
{
	this->experience = experience;
}
