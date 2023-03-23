#include<iostream>
#include<string>
using namespace std;

// The maximum number of people stored in the address book
# define  Max  1000  // Maximum number of people


// Define a contact structure
struct Contacts
{
	string cName;		 // name
	int cGender = 1 ;	 // gender
	int cAge = 0 ;		 // age
	string cPhone;		 // phone number
	string cAdd;		 // Address
};

// Define an address book structure
struct AddressBooks
{
	Contacts contactsArry[Max];	 // Array of address book contact information
	int aCount = 0 ;					 // the number of people in the address book
};

// show the main menu
void showMenu()
{
	cout << "_____________________________________" << endl;
	cout << " ***** Personal Contact Book ***** " << endl;
	cout << "_____________________________________" << endl;
	cout << "1. Add contacts" << endl;
	cout << "2. display contacts" << endl;
	cout << "3. Delete contacts" << endl;
	cout << "4. Find contact" << endl;
	cout << "5. Modify contacts" << endl;
	cout << "6. Clear contacts" << endl;
	cout << "0. exit address book" << endl;
}

// add a contact
void AddContacts(AddressBooks* abs)
{
	// Check if full
	if (abs->aCount == Max)
	{
		cout << " The address book is full and cannot be added! " << endl;
		return;
	}
	else
	{
		// name
		string name;
		cout << " Please enter the name: " << endl;
		cin >> name;
		abs->contactsArry[abs->aCount].cName = name;

		// gender
		int gender;
		cout << " Please enter gender: " << endl;
		cout << "1. Male " << endl;
		cout << "2. Female " << endl;

		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->contactsArry[abs->aCount].cGender = gender;
				break;
			}
			cout << " Input is wrong, please re-enter! " << endl;
		}

		// age
		int age;
		cout << " Please enter age: " << endl;
		cin >> age;
		abs->contactsArry[abs->aCount].cAge = age;

		// phone
		string phone;
		cout << " Please enter the phone number: " << endl;
		cin >> phone;
		abs->contactsArry[abs->aCount].cPhone = phone;

		// address
		string add;
		cout << " Please enter address: " << endl;
		cin >> add;
		abs->contactsArry[abs->aCount].cAdd = add;

		// number plus one
		abs->aCount += 1;
		cout << " Added successfully! " << endl;
		system("pause");
		// Qingping
		system("cls");
	}

}

// display contacts
void ShowContacts(AddressBooks* abs)
{
	if (abs->aCount == 0)
	{
		cout << " No contact, please add it first! " << endl;
	}
	else
	{
		// display all contacts
		for (int i = 0; i < abs->aCount; i++)
		{
			cout<<"_____________________________________"<<endl;
			cout << " Name: " << abs -> contactsArry [i]. cName << "\n"<<"Gender: " << ( abs -> contactsArry [i]. cGender != 2 ? " Male " : " Female " ) <<"\n"<< " Age: " << abs -> contactsArry [i]. cAge <<"\n"<< " Telephone: " << abs ->contactsArry[i].cPhone <<"\n"<< " Address：" << abs->contactsArry[i].cAdd <<"\n_____________________________________"<< endl;
		}
	}
	system("pause");
	system("cls");
}

// Check if someone exists
int IsExit(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->aCount; i++)
	{
		if (abs->contactsArry[i].cName == name)
		{
			return i;
		}
	}
	return -1;
}

// delete contact
void DeleteContacts(AddressBooks* abs)
{
	// Record the name entered by the user
	string name;
	cout << " Please enter the name of the user you want to delete: " << endl;
	cin >> name;
	// Check if the contact exists
	int index = IsExit(abs, name);
	// exists
	if (index > -1)
	{
		for (int i = index; i < abs->aCount - 1; i++)
		{
			// forward shift operation
			Contacts temp = abs->contactsArry[i];
			abs->contactsArry[i] = abs->contactsArry[i + 1];
			abs->contactsArry[i + 1] = temp;
		}
		// Reduce a record
		abs->aCount--;
		cout << " Delete successfully! " << endl;
	}
	else // does not exist
	{
		cout << " No such person found " << endl;
	}
	system("pause");
	system("cls");
}

// find contacts
void GetContacts(AddressBooks* abs)
{
	// Record the name entered by the user
	string name;
	cout << " Please enter the name of the user you are looking for " << endl;
	cin >> name;
	// Check if the contact exists
	int index = IsExit(abs, name);
	if (index > -1)
	{
		// exists
		cout << "Name：" << abs->contactsArry[index].cName << endl;
		cout << "Gender：" << abs->contactsArry[index].cGender << endl;
		cout << "Age：" << abs->contactsArry[index].cAge << endl;
		cout << "PhoneNo.：" << abs->contactsArry[index].cPhone << endl;
		cout << "Address：" << abs->contactsArry[index].cAdd << endl;
	}
	else
	{
		// does not exist
		cout << " No such person found " << endl;
	}
	system("pause");
	system("cls");

}

// Modify the contact
void ModefyContacts(AddressBooks* abs)
{
	// Record the name entered by the user
	string name;
	cout << " Please enter the user name you want to modify " << endl;
	cin >> name;
	// Check if the contact exists
	int index = IsExit(abs, name);
	if (index > -1)
	{
		// exists
		// name
		string name;
		cout << " Please enter the modified name: " << endl;
		cin >> name;
		abs->contactsArry[index].cName = name;

		// gender
		int gender;
		cout << " Please enter the modified gender: " << endl;
		cout << "1 Male " << endl;
		cout << "2 Female " << endl;

		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->contactsArry[index].cGender = gender;
				break;
			}
			cout << " Input is wrong, please re-enter! " << endl;
		}

		// age
		int age;
		cout << " Please enter the modified age: " << endl;
		cin >> age;
		abs->contactsArry[index].cAge = age;

		// phone
		string phone;
		cout << " Please enter the modified phone number: " << endl;
		cin >> phone;
		abs->contactsArry[index].cPhone = phone;

		// address
		string add;
		cout << " Please enter the modified address: " << endl;
		cin >> add;
		abs->contactsArry[index].cAdd = add;
		cout << " Modified successfully! " << endl;
	}
	else
	{
		// does not exist
		cout << " No such person found " << endl;
	}
	system("pause");
	system("cls");
}

// clear contacts
void ClearContacts(AddressBooks* abs)
{
	string choose = "N";
	cout << " Are you sure you want to clear the address book? (Y to confirm/N to cancel) " << endl;

	while (true)
	{
		cin >> choose;
		if (choose == "Y" || choose == "N")
		{
			break;
		}
		else
		{
			cout << " Input is wrong, please re-enter!! " << endl;
		}
	}

	if (choose == "Y")
	{
		abs->aCount = 0;
		cout << " Empty successfully!! " << endl;
	}
	else
	{
		cout << " Operation canceled!! " << endl;
	}
	system("pause");
	system("cls");
}


int main()
{
	// Record the information entered by the user
	int select = 0;
	// Define an address book structure
	AddressBooks abs;
	// Set the current number of people to zero
	abs.aCount = 0;

	while (true)
	{
		// show the main menu
		showMenu();

		cin >> select;
		switch (select)
		{
		case  1 : // 1. Add a contact
			AddContacts (& abs );	 // Address transfer
			break;
		case  2 : // 2. Display contacts
			ShowContacts (& abs ); // Address transfer
			break;
		case  3 : // 3. Delete the contact
			DeleteContacts(&abs);
			break;
		case  4 : // 4. Find contacts
			GetContacts(&abs);
			break;
		case  5 : // 5. Modify the contact
			ModefyContacts(&abs);
			break;
		case  6 : // 6. Clear contacts
			ClearContacts(&abs);
			break;
		case  0 : // 0, exit the address book
			cout << " Welcome to use next time, goodbye! " << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}


	system ( " pause " ); // press any key to continue
	return 0;
}