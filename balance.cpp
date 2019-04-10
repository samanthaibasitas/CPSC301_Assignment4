//Samantha Ibasitas
//Section 2
#include <iostream> 
#include <string> 
#include <cstring> 
#include <fstream> 
#include <iomanip>
using namespace std; 
struct PERSON
{
  char Name[20]; 
  float Balance; 
};
void display(PERSON array[], int num) 
{
  cout << "Name\tBalance" << endl; 
  cout << "------------" << endl; 
  for(int i = 0; i < num; i++) 
  {
	cout << setprecision(2) << fixed; 
    cout << array[i].Name << " " << array[i].Balance << endl;
  }
}
void findRichest(PERSON array[], int num) 
{
  int i; 
  float richest = 0.0; 
  for(i = 0; i < num; i++)
  {
    if(richest < array[i].Balance) 
      richest = array[i].Balance; 
  }
  for(i = 0; i < num; i++) 
  {
     if(richest == array[i].Balance) 
      break; 
  }
  cout << "The customer with maxium balance is " << array[i].Name << endl; 
}
void deposit(PERSON array[], int num, string customerName, int amount) 
{
  int wrong = 1; 
  int i; 
  for(i = 0; i < num; i++) 
  {
    wrong = strcmp(customerName.c_str(), array[i].Name); 
    if(wrong == 0)
    {
		break; 
	}
  }
  if(wrong == 0)
  {
	cout << setprecision(2) << fixed; 
    array[i].Balance = amount + array[i].Balance; 
    cout << "New Balance: " << array[i].Balance << endl; 
  }
}
void newCopy(string file, PERSON array[], int num) 
{
	ofstream filename(file.c_str()); 
	char name[20]; 
	float balance; 
	for(int i = 0; i < num; i++) 
	{
		strcpy(name, array[i].Name); 
		balance = array[i].Balance; 
		filename << name << " " << balance; 
	}
	cout << "File Updated...." << endl; 
	filename.close(); 
}
PERSON * readData(int &N)
{
	string line; 
	string fName; 
	string lName; 
	string tempName; 
	char name[20]; 
	float balance; 
	ifstream file("data.txt"); 
	while(getline(file, line))
	{
		N++;
	} 
	file.close(); 
	PERSON *array = NULL; 
	array = new PERSON[N]; 
	ifstream file2("data.txt"); 
	if(file2.is_open())
	{
		for(int i = 0; i < N; i++)
		{
			file2 >> fName >> lName; 
			tempName = fName + " " + lName; 
			strcpy(array[i].Name, tempName.c_str()); 
			file2 >> array[i].Balance;
		}
	}
	file2.close(); 
	return array; 
}
void print()
{
	cout << "please enter a number choice : " << endl; 
	cout << "1. display records" << endl; 
	cout << "2. find highest balance" << endl; 
	cout << "3. deposit funds" << endl; 
	cout << "4. update records" << endl; 
	cout << "5. exit" << endl; 
}
int main()
{
	int size = 0; 
	string name; 
	int amount; 
	PERSON * people = NULL; 
	people = readData(size); 
	int choice; 
	do
	{
		print(); 
		cin >> choice; 
		switch(choice) 
		{
			case 1: 
				display(people, size); 
				break; 
			case 2: 
				findRichest(people, size); 
				break; 
			case 3: 
				cout << "Enter name: " << endl; 
				cin >> ws; 
				getline(cin, name); 
				cout << "Enter amount: " << endl; 
				cin >> amount; 
				deposit(people, size, name, amount); 
				break; 
			case 4: 
				newCopy("newFile", people, size); 
				break; 
			case 5: 
				cout << "Exiting Now..." << endl; 
				system("PAUSE"); 
				return 0; 
				break; 
			default: 
				cout << "invalid entry" << endl; 
				break; 
		}
		cout << endl; 
	}while(choice!=5);
	return 0; 
}
