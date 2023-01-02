#include<iostream>
#include<fstream>
#include<string>
#include "Header.h"
using namespace std;

int main() {
	load_data();
	login();
}

void login() {
	cout << "---------------------------------\n| CRIMINAL INVESTIGATION SYSTEM |\n---------------------------------" << endl;
	cout << " 1.Login as Admin\n 2.Login as Officer\n\n select your choice, input an integer:\n________________________________________" << endl;
	int choice;
	do {
		cin >> choice;
		switch (choice) {
		case 1:
			admin();
			break;
		case 2:
			officer();
			break;
		default:
			cout << "invalid choice, please try again." << endl;
		}
	} while (choice > 2);
}