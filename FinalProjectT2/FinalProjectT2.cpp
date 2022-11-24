#pragma once
#include <iostream>
#include "App.cpp"
#include "User.cpp"
#include "UserManager.cpp"

using namespace std;

int main()
{
	App app;
	UserManager usermanagement;
	string username;
	string password;
	do {
		system("cls");
		cout << "\t=======================\tLOGIN MENU\t=======================" << endl;
		cout << "\t=========================================================" << endl;
		cout << "\t\tEnter username: ";
		cin >> username;
		cout << "\t\tPassword: ";
		cin >> password;
		User* user = usermanagement.authenticateUser(username, password);
		if (user != nullptr) {
			if (user->getRole() == "ADMIN") {
				app.RunAdmin();
			}
			else if (user->getRole() == "STAFF") {
				app.RunStaff();
			}
		}
		else {
			cout << "Invalid user" << endl;
		}
	} while (true);

	return 0;
}

