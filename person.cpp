#include "person.h"
#include <string> 
using namespace std;
Person::Person(string fName, string lName, float pay, float hours)
{
	firstName = fName; 
	lastName = lName; 
	payRate = pay; 
	hoursWorked = hours; 
}
string Person::getFirstName()
{
    return firstName;
}
void Person::setLastName(string lName)
{
    lastName = lName;
}
string Person::getLastName()
{
    return lastName;
}
void Person::setFirstName(string fName)
{
    firstName = fName;
}
void Person::setPayRate(float rate)
{
    payRate = rate;
}
float Person::getPayRate()
{
    return payRate;
}
void Person::setHoursWorked(float hours)
{
    hoursWorked = hours;
}
float Person::getHoursWorked()
{
    return hoursWorked;
}
float Person::totalPay()
{
    int total;
    total = hoursWorked * payRate;
    return total;
}
string Person::fullName()
{
    string fullName; 
    fullName = firstName + " " +lastName;
    return fullName;
}
