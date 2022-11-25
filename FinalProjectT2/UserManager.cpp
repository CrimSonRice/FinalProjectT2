#pragma once
#include <iostream>
#include "User.cpp"
#include "UserDao.cpp"

using namespace std;

class UserManager : public UserManagerDAO {
private:
	User users[100];
	int count = 0;
public:
	UserManager() {
		User user1("Tola", "123", "ADMIN");
		User user2("Dina", "123", "STAFF");
		users[count++] = user1;
		users[count++] = user2;
	}
	void addUser(User user) {
		users[count] = user;
		count++;
	}
	void viewUser() {
		for (int i = 0; i < count; i++) {
			if (users[i].getRole() == "ADMIN") {
				users[i].outputUser();
				cout << "Type: " << "ADMIN" << endl;
			}
			else if (users[i].getRole() == "STAFF") {
				users[i].outputUser();
				cout << "Type: " << "NORMAL" << endl;
			}


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
	User* getUserByName(string name) {
		User* user = nullptr;
		for (int i = 0; i < count; i++) {
			if (users[i].getUsername() == name) {
				if (users[i].getRole() == "ADMIN") {
					users[i].outputUser();
					cout << "Type: " << "ADMIN" << endl;
				}
				else if (users[i].getRole() == "STAFF") {
					users[i].outputUser();
					cout << "Type: " << "STAFF" << endl;
				}
				return &users[i];
			}
		}
		return user;
	}
	void editUserRole(string name) {
		string role;
		int found = findUserByName(name);
		if (found != -1) {
			cout << "Press 1. ADMIN 2. STAFF " << endl;
			cin >> role;
			users[found].setRole(role);
			cout << "Role has been updated" << endl;
		}
		else {
			cout << "not found" << endl;
		}
	}
	void editUser(string name) {
		string userName;
		string password;
		string role;
		int found = findUserByName(name);
		if (found != -1) {
			cout << "Enter new name: ";
			cin >> userName;
			users[found].setUsername(userName);
			cout << "Enter new password: ";
			cin >> password;
			users[found].setPassword(password);
			cout << "Enter new role: ";
			cin >> role;
			users[found].setRole(role);
			cout << "username has been updated" << endl;
		}
		else {
			cout << "not found" << endl;
		}
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
	void searchUser(string name) {
		int found = findUserByName(name);
		if (found != -1) {
			for (int i = found; i < count; i++) {
				users[i].outputUser();
			}
		}
		else {
			cout << "not found" << endl;
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
	