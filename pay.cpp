#include "person.cpp"
#include <fstream> 
#include <iostream> 
#include <vector>
#include <string> 
using namespace std; 
int num = 0; 
void readData(vector<Person> &employees)
{
	string fName; 
	string lName; 
	float pay; 
	float hours; 
	string line; 
	int i = 0; 
	ifstream file("input.txt"); 
	if(file.is_open())
	{
		file >> fName; 
		while(!file.eof())
		{
			file >> lName >> pay >> hours; 
			getline(file, line); 
			employees.emplace_back(fName, lName, pay, hours); 
			num++; 
			i++;
			file >> fName; 
		}
	}
	file.close(); 
}
void writeData(vector<Person> &employees)
{
	string fullName; 
	float total; 
	ofstream file("output.txt"); 
	if(file.is_open())
	{
		for(int i = 0; i < employees.size(); i++)
		{
			fullName = employees[i].fullName();  
			total = employees[i].totalPay(); 
			file << fullName << " " << total << endl; 
			cout << fullName << " " << total << endl; 
		}
		file.close(); 
	}
}
int main()
{
	vector<Person> employees; 
	readData(employees); 
	writeData(employees); 
	system("PAUSE"); 
	return 0; 
}
