#pragma once
#include <iostream>
#include "Car.cpp"
#include "CarManager.cpp"
#include "User.cpp"
#include "UserManager.cpp"
using namespace std;


enum {
	ADD_USER =1,
	VIEW_USER,
	EDIT_USER,
	DELETE_USER,
	SEARCH_USER,
	EXIT
};

class App {
public:
	void RunAdmin() {

		User users;
		char choice;
		int num = 0;
		string username;
		UserManager* usermanagement;

		do {
			system("cls");
			cout << "\n\n\n\tADMIN MENU";
			cout << "\n\n\t01. ADD NEW USER";
			cout << "\n\n\t02. VIEW ALL USERS";
			cout << "\n\n\t03. EDIT A USER";
			cout << "\n\n\t04. DELETE A USER";
			/*cout << "\n\n\t05. SEARCH A USER";*/
			cout << "\n\n\t0. EXIT";
			cout << "\n\n\tSelect Your Option (0-4): ";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case ADD_USER: {
				users.inputUser();
				usermanagement->addUser(users);
				break;
			}
			case VIEW_USER: {
				cout << "\t-USER INFO-" << endl;
				usermanagement->viewUser();
				cout << endl;
				break;
			}
			case EDIT_USER: {
				cout << "Enter username: ";
				cin >> username;
				usermanagement->editUser(username);
				break;
			}
			case DELETE_USER: {
				cout << "Enter username: ";
				cin >> username;
				usermanagement->deleteUser(username);

				break;
			}

			default:
				cout << "Invalid";
				break;
			}
			cin.ignore();
			cin.get();
		} while (choice != '0');
	}
};