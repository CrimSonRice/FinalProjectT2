#pragma once
#include <iostream>
#include "User.cpp"

using namespace std;

class UserManager : User{
private:
	User users[10];
	int count = 0;
public:


	UserManagement() {
		User user1("Tola", "123", "ADMIN");
		User user2("Dina", "456", "STAFF");
		users[count++] = user1;
		users[count++] = user2;
	}

	void addUser(User user) {
		users[count] = user;
		count++;
	}

	void viewUser() {
		for (int i = 0; i < count; i++) {
			users[i].outputUser();
		}
	}

	int findUserByName(string name) {
		for (int i = 0; i < count; i++) {
			if (users[i].getUsername() == name) {
				return i;
			}
		}
		return -1;
	}


	User getUserByName(string name) {
		User user;
		for (int i = 0; i < count; i++) {
			if (users[i].getUsername() == name) {
				return users[i];
			}
		}
		return user;
	}

	void editUser(User users[], string username) {
		string new_username;
		string new_password;
		string new_role;

		int found = findUserByName(username);
		if (found != -1) {
			int choice = 0;
			system("cls");
			cout << "\t================\t EDIT BY \t================" << endl;
			cout << "1) Edit Username.\n2)Edit Password.\n3)Edit Role." << endl;
			cout << "Enter option: ";
			cin >> choice;

			switch (choice) {
			case 1:
				cout << "Enter new username: ";
				cin >> new_username;
				users[found].setUsername(new_username);
				break;
			case 2:
				cout << "Enter new password: ";
				cin >> new_password;
				users[found], setPassword(new_password);
				break;
			case 3:
				cout << "Enter new role: ";
				cin >> new_role;
				users[found].setRole(new_role);
				break;

			}
		}
		else {
			cout << "Not found" << endl;
		}
	}

	void deleteUser(string name) {
		int found = findUserByName(name);
		if (found != -1) {
			for (int i = found; i < count; i++) {
				users[i] = users[i + 1];
			}
			count--;
			cout << "User has been deleted" << endl;
		}
		else {
			cout << "Not found" << endl;
		}
	}


	User* authenticateUser(string username, string password) {
		User* user = nullptr;
		for (int i = 0; i < count; i++) {
			if (users[i].getUsername() == username && users[i].getPassword() == password) {
				return &users[i];
			}
		}
		return user;
	}
};