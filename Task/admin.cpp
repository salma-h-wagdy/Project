
#include<iostream>
#include<fstream>
#include<string>
#include <stdlib.h>
#include "Header.h"
#include "var.h"
using namespace std;

//var 
string name, criminal_ID, type, status, age, date, nationality, crime_ID, birth_day, birth_month, birth_year, crime_day, crime_month, crime_year;

//structs 
struct DMY {
	int day{ 0 };
	int month{ 0 };
	int year{ 0 };
};
struct criminal {
	string name{ 0 };
	string criminal_ID{ 0 };
	DMY birth_date{ 0 };
	int age{ 0 };
	string nationality;
}criminals[num_of_criminals];

struct crime {
	string crime_ID{ 0 };
	string type{ 0 };
	string status{ 0 };
	DMY crime_date{ 0 };
}crimes[num_of_crimes];

//load data
void load_data() {

	ifstream criminal_load("C:/Users/Salma/source/repos/Task/Criminal.txt");  //opens criminal file
	if (criminal_load.is_open()) {
		while (criminal_load.peek() != EOF) {
			getline(criminal_load, criminal_ID);
			getline(criminal_load, name);
			getline(criminal_load, age);
			getline(criminal_load, birth_day);
			getline(criminal_load, birth_month);
			getline(criminal_load, birth_year);
			getline(criminal_load, nationality);
			criminals[num_criminals].criminal_ID = criminal_ID;
			criminals[num_criminals].name = name;
			criminals[num_criminals].age = stoi(age);
			criminals[num_criminals].birth_date.day = stoi(birth_day);
			criminals[num_criminals].birth_date.month = stoi(birth_month);
			criminals[num_criminals].birth_date.year = stoi(birth_year);
			criminals[num_criminals].nationality = nationality;
			num_criminals++;

		}
		criminal_load.close();
	}
	ifstream crime_load("C:/Users/Salma/source/repos/Task/Crime.txt");   //opens crime file
	if (crime_load.is_open()) {
		while (crime_load.peek() != EOF) {
			getline(crime_load, crime_ID);
			getline(crime_load, type);
			getline(crime_load, status);
			getline(crime_load, crime_day);
			getline(crime_load, crime_month);
			getline(crime_load, crime_year);
			crimes[num_crimes].crime_ID = crime_ID;
			crimes[num_crimes].type = type;
			crimes[num_crimes].status = status;
			crimes[num_crimes].crime_date.day = stoi(crime_day);
			crimes[num_crimes].crime_date.month = stoi(crime_month);
			crimes[num_crimes].crime_date.year = stoi(crime_year);
			num_crimes++;

		}
		crime_load.close();
	}

}
//save data
void save_data() {
	ofstream criminal_delete("C:/Users/Salma/source/repos/Task/Criminal.txt", std::ofstream::out | std::ofstream::trunc); //clears data in criminal file
	criminal_delete.close();
	ofstream criminal_s("C:/Users/Salma/source/repos/Task/Criminal.txt", ios::app); //saves data to criminal file
	for (int x = 0;x < num_criminals;x++) {
		criminal_s << criminals[x].criminal_ID << endl;
		criminal_s << criminals[x].name << endl;
		criminal_s << criminals[x].age << endl;
		criminal_s << criminals[x].birth_date.day << endl;
		criminal_s << criminals[x].birth_date.month << endl;
		criminal_s << criminals[x].birth_date.year << endl;
		criminal_s << criminals[x].nationality << endl;
	}
	criminal_s.close();

	ofstream crime_delete("C:/Users/Salma/source/repos/Task/Crime.txt", std::ofstream::out | std::ofstream::trunc); //clears data in crime file
	crime_delete.close();
	ofstream crime_save("C:/Users/Salma/source/repos/Task/Crime.txt", ios::app); //saves data to crime file
	for (int x = 0;x < num_crimes;x++) {
		crime_save << crimes[x].crime_ID << endl;
		crime_save << crimes[x].type << endl;
		crime_save << crimes[x].status << endl;
		crime_save << crimes[x].crime_date.day << endl;
		crime_save << crimes[x].crime_date.month << endl;
		crime_save << crimes[x].crime_date.year << endl;
	}
	crime_save.close();

}

void main_screen() {
	while (1)
	{
		int a;
		cout << "Choose an action:\n 1.Add Record\n 2.Delete record \n 3.Display Record\n 4.update\n 5.search\n 6.Save and Exit" << endl;
		cin >> a;
		cout << "------------------" << endl;
		switch (a) {
		case 1:
			add_record();
			break;
		case 2:
			delete_record();
			break;
		case 3:
			display_record();
			break;
		case 4:
			update_record();
			break;
		case 5:
			search_record();
			break;
		case 6:
			save_data();
			cout << "\n Data Saved.\n Exiting...\n____________________________________" << endl;
			exit(0);
			break;
		}
	}
}


void admin() {   //admin login
	string username, pass, u, p;
	cout << "Enter your username:"; cin >> username;
	cout << "Enter your password:"; cin >> pass;
	ifstream read("C:/Users/Salma/source/repos/Task/Admin.txt"); //reads admin data from file
	while (read >> u >> p) {

		if (u == username && p == pass) {
			cout << "------------------------------------------\nLogin succesful.\n------------------------------------------" << endl;
			main_screen();
		}
	}
	read.close();
	cout << "------------------------------------------\nLogin error, try again.\n------------------------------------------" << endl;
	admin();
}



//after login

void add_record() {
	int p = 1;
	do {
		int x;
		cout << " Press (1) to add new criminal\n Press (2) to add new crime " << endl;
		cin >> x;
		cout << "-------------------------------" << endl;
		if (x != 1 && x != 2)
		{
			cout << "invalid option,please try again ";
			add_record();
		}
		if (x == 1) // todo write func
		{
			cout << " Enter the ID: ";
			cin >> criminals[num_criminals].criminal_ID;
			cout << endl;
			cout << " Enter the criminal name (First name_Last name): ";
			cin >> criminals[num_criminals].name;
			cout << endl;
			cout << " Enter the criminal age: ";
			cin >> criminals[num_criminals].age;
			cout << endl;
			cout << " Enter the criminal's birth date (dd/mm/yy)" << endl;
			cout << "Enter the day: ";
			cin >> criminals[num_criminals].birth_date.day;
			cout << endl;
			cout << "Enter the month: ";
			cin >> criminals[num_criminals].birth_date.month;
			cout << endl;
			cout << "Enter the year: ";
			cin >> criminals[num_criminals].birth_date.year;
			cout << endl;
			cout << " Enter the criminal nationality: ";
			cin >> criminals[num_criminals].nationality;
			cout << endl;
			num_criminals++;
			cout << "------------------------------------------\ncriminal record succesfully saved\n------------------------------------------" << endl;

		}
		else if (x == 2)
		{
			cout << " Enter the crime ID: ";
			cin >> crimes[num_crimes].crime_ID;
			cout << endl;
			cout << " Enter the type of crime (Burglary/Fruad/Arson/Violence/Murder...etc) : ";
			cin >> crimes[num_crimes].type;
			cout << endl;
			cout << " Enter Case status(closed/ongoing/unassigned): " << endl;
			cin >> crimes[num_crimes].status;
			cout << endl;
			cout << " Enter the crime date (dd/mm/yy)" << endl;
			cout << "Enter the crime day: ";
			cin >> crimes[num_crimes].crime_date.day;
			cout << endl;
			cout << "Enter the crime month: ";
			cin >> crimes[num_crimes].crime_date.month;
			cout << endl;
			cout << "Enter the crime year: ";
			cin >> crimes[num_crimes].crime_date.year;
			cout << endl;
			num_crimes++;
			cout << "------------------------------------------\ncrime record succesfully saved\n------------------------------------------" << endl;
		}
		int y;
		cout << "Would you like to add another Criminal Record?\n 1.Yes \n2.No " << endl;
		cin >> y;
		if (y == 1) {
			add_record();
		}
		else {
			cout << "------------------------------------------" << endl;
			p = 0;
			main_screen();
		}
	} while (p);
}

void delete_record() {

	int index, delete_option;
	cout << "Do you want to delete \n 1. criminal \n 2. crime \n" << endl;
	cin >> delete_option;
	while (delete_option != 1 && delete_option != 2)
	{
		cout << "invaild option" << endl;
		delete_record();
	}
	system("cls");
	if (delete_option == 1)
	{
		index = search_criminal();
		display_criminal(index);
		int d;
		cout << "Do you want to delete this criminal's information? \n 1. Yes \n 2. No" << endl;
		cin >> d;
		while (d != 1 && d != 2)
		{
			cout << "Invalid option" << endl;
			cin >> d;
			break;
		}
		if (d == 1)

		{
			for (int i = index; i < num_criminals - 1; i++)
			{

				criminals[i].criminal_ID = criminals[i + 1].criminal_ID;
				criminals[i].name = criminals[i + 1].name;
				criminals[i].age = criminals[i + 1].age;
				criminals[i].birth_date.day = criminals[i + 1].birth_date.day;
				criminals[i].birth_date.month = criminals[i + 1].birth_date.month;
				criminals[i].birth_date.year = criminals[i + 1].birth_date.year;
				criminals[i].nationality = criminals[i + 1].nationality;
			}
			num_criminals--;
			cout << "----------------------------------" << endl;
			cout << "Data has been deleted successfully" << endl;
			cout << "----------------------------------" << endl;
		}
	}
	else
	{
		int e;
		index = search_crime();
		display_crime(index);
		cout << "Do you want to delete this crime's information? \n 1. Yes \n 2. No" << endl;
		cin >> e;
		while (e != 1 && e != 2)
		{
			cout << "Invalid option" << endl;
			cin >> e;
			break;
		}
		if (e == 1)
		{
			for (int i = index; i < num_crimes - 1; i++)
			{
				crimes[i].crime_ID = crimes[i + 1].crime_ID;
				crimes[i].type = crimes[i + 1].type;
				crimes[i].status = crimes[i + 1].status;
				crimes[i].crime_date.day = crimes[i + 1].crime_date.day;
				crimes[i].crime_date.month = crimes[i + 1].crime_date.month;
				crimes[i].crime_date.year = crimes[i + 1].crime_date.year;
			}
			num_crimes--;
			cout << "----------------------------------" << endl;
			cout << "Data has been deleted successfully" << endl;
			cout << "----------------------------------" << endl;
		}
	}
	int y;
	cout << "Would you like to delete another Criminal Record?\n 1.Yes \n2.No " << endl;
	cin >> y;
	if (y != 1 && y != 2)
		cout << "invalid option,try again..." << endl;
	else if (y == 1)
		delete_record();
	else {
		cout << "------------------------------------------" << endl;
		main_screen();
	}
}

//display record
void display_record()
{
	int x;
	cout << " press [1] to display all Criminals \n Press [2] to display all Crimes \n Press [3] for displaying Both " << endl;;
	cin >> x;
	cout << "-----------------------------------" << endl;
	if (x != 1 && x != 2 && x != 3) {
		cout << "invalid option,please try again." << endl;
		display_record();
	}
	system("cls");
	if (x == 1)
	{
		for (int i = 0; i < num_criminals; i++)
		{
			display_criminal(i);
		}
	}
	else if (x == 2)
	{
		for (int i = 0; i < num_crimes; i++)
		{
			display_crime(i);
		}
	}
	else if (x == 3)
	{
		cout << "---------" << endl;
		cout << "criminals:" << endl;
		cout << "---------" << endl;
		cout << "\n";
		int j = 0;
		while (j < num_criminals)
		{
			display_criminal(j);
			j++;
		}
		cout << "\n";
		cout << "------" << endl;
		cout << "crimes:"<<endl;
		cout << "------" << endl;
		cout << "\n";
		int i = 0;
		while (i < num_crimes)
		{
			display_crime(i);
			i++;
		}
	}
	//main_screen();
}
void display_criminal(int criminalindex)
{
	cout << "Criminal ID: " << criminals[criminalindex].criminal_ID << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Name:" << criminals[criminalindex].name << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Age:" << criminals[criminalindex].age << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Date of birth:" << criminals[criminalindex].birth_date.day << "/" << criminals[criminalindex].birth_date.month << "/" << criminals[criminalindex].birth_date.year << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Nationality:" << criminals[criminalindex].nationality << endl;
	cout << "-----------------------------------------" << endl;

}
void display_crime(int crime_num)
{
	cout << "Crime_ID:" << crimes[crime_num].crime_ID << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Crime type:" << crimes[crime_num].type << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Crime status:" << crimes[crime_num].status << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Date of crime:" << crimes[crime_num].crime_date.day << "/" << crimes[crime_num].crime_date.month << "/" << crimes[crime_num].crime_date.year << endl;
	cout << "-----------------------------------------" << endl;
}





void update_record() {
	int f = 1;
	do {
		int updatecriminal, updatecrime, updateoption;
		cout << "Do you want to update? \n 1. criminal \n 2. crime" << endl;
		cin >> updateoption;
		cout << "----------------------" << endl;
		while (updateoption != 1 && updateoption != 2)
		{
			cout << "Invaild option";
			update_record();
			break;
		}
		system("cls");
		if (updateoption == 1)
		{
			updatecriminal = search_criminal();
			string criminalID, newname;
			int criminalage, criminaloption, newday, newmonth, newyear , newnationality;
			display_criminal(updatecriminal);
			cout << "Please enter number that you wanted to modify \n 1. criminal ID \n 2.criminal name \n 3. criminal age\n 4.criminal date of birth\n 5.nationality" << endl;
			cin >> criminaloption;
			cout << "----------------------------------------------"<<endl;
			switch (criminaloption)
			{
			case 1:
			{
				cout << "please enter the new criminal ID" << endl;
				cin >> criminalID;
				criminals[updatecriminal].criminal_ID = criminalID;
				cout << "-----------------------------------" << endl;
				cout << "Data has been modified successfully" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			case 2:
			{
				cout << "please enter the new criminal name" << endl;
				cin >> newname;
				criminals[updatecriminal].name = newname;
				cout << "-----------------------------------" << endl;
				cout << "Data has been modified successfully" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			case 3:
			{
				cout << "please enter the new criminal age" << endl;
				cin >> criminalage;
				criminals[updatecriminal].age = criminalage;
				cout << "-----------------------------------" << endl;
				cout << "Data has been modified successfully" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			case 4: {
				cout << "please enter the new criminal date of birth (dd/mm/yy)" << endl;
				cout << "Enter the day: ";
				cin >> newday;
				criminals[updatecriminal].birth_date.day = newday;
				cout << "Enter the month: ";
				cin >> newmonth;
				criminals[updatecriminal].birth_date.month = newmonth;
				cout << "Enter the year: ";
				cin >> newyear;
				criminals[updatecriminal].birth_date.year = newyear;
				cout << "-----------------------------------" << endl;
				cout << "Data has been modified successfully" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			case 5: {
				cout << " Enter the criminal nationality: ";
				cin >> newnationality;
				criminals[updatecriminal].nationality = newnationality;
				cout << "-----------------------------------" << endl;
				cout << "Data has been modified successfully" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}

			default:
			{
				cout << " Invaild option" << endl;
				display_criminal(updatecriminal);
			}
			}
		}
		else
		{
			updatecrime = search_crime();
			string crimetype, crimestatus, CrimeID;
			int crimeoption, Crime_day, Crime_month, Crime_year;
			display_crime(updatecrime);
			cout << "Please enter the number that you want to modify \n 1. crime type \n 2. crime status \n 3. crime ID \n 4. the crime day" << endl;
			cin >> crimeoption;
			cout << "------------------------------------------------"<<endl;
			switch (crimeoption)
			{
			case 1:
			{
				cout << "Please enter the new crime type" << endl;
				cin >> crimetype;
				crimes[updatecrime].type = crimetype;
				cout << "-----------------------------------";
				cout << "Data has been modified successfully" << endl;
				cout << "-----------------------------------";
				break;
			}
			case 2:
			{
				cout << "Please enter the new crime status" << endl;
				cin >> crimestatus;
				crimes[updatecrime].status = crimestatus;
				cout << "-----------------------------------" << endl;
				cout << "Data has been modified successfully" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			case 3:
			{
				cout << "Please enter the new crime ID" << endl;
				cin >> CrimeID;
				crimes[updatecrime].crime_ID = CrimeID;
				cout << "-----------------------------------" << endl;
				cout << "Data has been modified successfully" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			case 4:
			{
				cout << "please enter the new date of crime (dd/mm/yy)" << endl;
				cout << "Enter the day: ";
				cin >> Crime_day;
				crimes[updatecrime].crime_date.day = Crime_day;
				cout << "Enter the month: ";
				cin >> Crime_month;
				crimes[updatecrime].crime_date.month = Crime_month;
				cout << "Enter the year: ";
				cin >> Crime_year;
				crimes[updatecrime].crime_date.year = Crime_year;
				cout << "-----------------------------------" << endl;
				cout << "Data has been modified successfully" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			default:
			{
				cout << " Invaild option" << endl;
				display_crime(updatecrime);
			}
			}
		}
		int y;
		cout << "Would you like to update another Criminal Record?\n 1.Yes \n2.No " << endl;
		cin >> y;
		if (y != 1 && y != 2)
			cout << "invalid option,try again..." << endl;
		else if (y == 1)
			update_record();
		else {
			cout << "------------------------------------------" << endl;
			f = 0;
		}
	} while (f == 1);
}


// search record
void search_record() {

	int displayindex, searchoption;
	int z = 1;
	do
	{
		cout << "Are you looking for \n 1. criminal \n 2. crime \n " << endl;
		cin >> searchoption;
		cout << "--------------------";
		while (searchoption != 1 && searchoption != 2)
		{
			cout << "Invaild option" << endl;
			search_record(); // here 
			break;
		}
		system("cls");
		if (searchoption == 1)
		{
			displayindex = search_criminal();
			if (displayindex == -1)
				break;
			else
				display_criminal(displayindex);
		}
		else
		{
			displayindex = search_crime();
			if (displayindex == -1)
				break;
			else
				display_crime(displayindex);
		}
		int y;
		cout << "Would you like to search for another Criminal Record?\n 1.Yes \n2.No " << endl;
		cin >> y;
		if (y != 1 && y != 2)
			cout << "invalid option,try again..." << endl;
		else if (y == 1)
			search_record();
		else
			cout << "------------------------------------------" << endl;
		z = 0;


	} while (z == 1);
}
int search_criminal() {  //searches for crime
	string searchcriminal;
	int sendback = -1;
	cout << "Please enter the criminal ID:";
	cin >> searchcriminal;
	for (int i = 0; i < num_criminals; i++)
	{
		if (searchcriminal == criminals[i].criminal_ID)
		{
			sendback = i;
		}

	}
	if (sendback == -1)
	{
		cout << "Invaild criminal ID" << endl;
		search_criminal();
	}
	return sendback;

}
int search_crime() //searches for crime
{
	string searchcrime;
	int sendback = -1;
	cout << "Please enter the crime ID:";
	cin >> searchcrime;
	for (int i = 0; i < num_crimes; i++)
	{
		if (searchcrime == crimes[i].crime_ID)
			sendback = i;
	}
	if (sendback == -1)
	{
		cout << "Invalid crime ID" << endl;
		search_crime();
	}

	return sendback;
}
