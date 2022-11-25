#pragma once
#include <iostream>
#include "Car.cpp"
#include "CarManager.cpp"
#include "User.cpp"
#include "UserManager.cpp"
using namespace std;


enum MenuType{
	ADD_USER = '1',
	VIEW_USER = '2',
	EDIT_USER = '3',
	DELETE_USER = '4',
	SEARCH_USER = '5',
	EXIT = '0'
};

enum CarType{
	ADD_CAR = '1',
	VIEW_CAR = '2',
	EDIT_CAR ='3',
	DELETE_CAR = '4',
	SEARCH_CAR = '5',
	SORT_CAR = '6',
	LEAVE = '7'
};

class App {
public:
	void RunAdmin() {

		User users;
		char choice;
		int num = 0;
		string username;
		UserManager usermanagement;

		do {
			system("cls");
			cout << "\t\tADMIN MENU";
			cout << "\n\t1. ADD NEW USER";
			cout << "\n\t02. VIEW ALL USERS";
			cout << "\n\t03. EDIT A USER";
			cout << "\n\t04. DELETE A USER";
			cout << "\n\t05. SEARCH A USER";
			cout << "\n\n\t0. EXIT";
			cout << "\n\t\tSelect Your Option (0-4): ";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case MenuType::ADD_USER: 
				
				users.inputUser();
				usermanagement.addUser(users);
				break;
			
			case MenuType::VIEW_USER :
				cout << "\t-USER INFO-" << endl;
				usermanagement.viewUser();
				cout << endl;
				break;
			
			case MenuType::EDIT_USER:
				cout << "Enter username: ";
				cin >> username;
				usermanagement.editUser(username);
				break;
			
			case MenuType::DELETE_USER: 
				cout << "Enter username: ";
				cin >> username;
				usermanagement.deleteUser(username);
				break;
			
			case MenuType::SEARCH_USER: 
				cout << "Enter username: ";
				cin >> username;
				usermanagement.searchUser(username);
				break;

			case MenuType::EXIT:
				break;
			
			default:
				cout << "Invalid";
				break;
			}
			cin.ignore();
			cin.get();
		} while (choice != '0');
	}

	void RunStaff() {
		Car* cars{};
		char choice{};
		int num = 0;
		int id;
		string username;
		CarManager carmanagement;
		int number = 0;
		int key=0;

		do {
			system("cls");
			cout << "\t\t\tStaff Menu" << endl;
			cout << "\t\t1). ADD CAR" <<endl ;
			cout << "\t\t2). VIEW CAR" << endl;
			cout << "\t\t3). EDIT CAR" << endl;
			cout << "\t\t4). DELETE CAR" << endl;
			cout << "\t\t5). SEARCH CAR" << endl;
			cout << "\t\t6). SORT CAR" << endl;
			cout << "\n\t\t0).EXIT" << endl;

			cout << "\n\t\tSelect Your Option (0-4): ";
			cin >> choice;

			system("cls");
			switch (choice) {
			case CarType::ADD_CAR:
				cars = new Car();
				cars->input_car_info();
				carmanagement.AddCar(cars);
				break;
			case CarType::VIEW_CAR:
				cout << "\t\t=== CAR INFO ===" << endl;
				carmanagement.viewAllCar();
				break;

			case CarType::EDIT_CAR:
				cars = new Car();
				cout << "Enter CAR ID: ";
				cin >> id;
				carmanagement.edit_car_info(cars, number, key);
				break;

			case CarType::DELETE_CAR:

				cout<< "Enter CAR ID: ";
				cin >> id;
				carmanagement.deleteCar(cars, number, key);
				break;

			case CarType::SEARCH_CAR:

				cout << "Enter CAR ID: ";
				cin >> id;
				carmanagement.searchCar(cars, number, key);
				break;
			case CarType::SORT_CAR:
				carmanagement.sortCarById();
				cout << "Successfully sorted by ID";
				break;
			case CarType::LEAVE:
				break;
				
			default:
				cout << "Invalid";
				break;
			}
			cin.ignore();
			cin.get();
		} 
		
		while (choice != '0');
	}
};