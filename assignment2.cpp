#include <iostream> 
#include <string> 
#include <cstring> 
#include <fstream> 
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
    cout << array[i].Name << " " << array[i].Balance << endl;
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
void deposit(string customer, PERSON array[], int num) 
{
  float amount = 0.0; 
  int wrong = 1; 
  int i; 
  for(i = 0; i < num; i++) 
  {
    wrong = strcmp(customer.c_str(), array[i].Name); 
    if(wrong == 0)
      break; 
  }
  if(wrong == 0)
  {
    cout << customer << ", how much would you like to deposit?" << endl; 
    cin >> amount; 
    array[i].Balance = amount + array[i].Balance; 
    cout << "Now your new balance is " << array[i].Balance << endl; 
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
	filename.close(); 
}
int main()
{
  int size = 0; 
  string line; 
  string fName; 
  string lName; 
  string tempName; 
  string customerName; 
  char name[20]; 
  float balance; 
  ifstream file("data.txt"); 
  while(getline(file, line))
    size++; 
  PERSON array[size]; 
  file.close(); 
  ifstream file2("data.txt"); 
  if(file2.is_open())
  {
    for(int i = 0; i < size; i++)
    {
      file2 >> fName >> lName >> balance; 
      tempName = fName + " " + lName; 
      strcpy(array[i].Name, tempName.c_str()); 
      array[i].Balance = balance;
    }
  }
  file2.close(); 
  display(array, size); 
  findRichest(array, size); 
  cout << "Enter your full name to deposit money: " << endl; 
  getline(cin, customerName); 
  deposit(customerName, array, size); 
  newCopy("data.txt", array, size); 
  system("PAUSE"); 
  return 0; 
}
