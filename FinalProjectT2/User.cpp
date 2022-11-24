#pragma once
#include <iostream>

using namespace std;

class User {
private:

	string username;
	string password;
	string role;

public:
	~User() {}
	User() : username("Unknown"), password("Unknown"), role("Unknown") {}
	User(string username, string password, string role) :username(username), password(password), role(role) {}


	void setUsername(string username) {
		this->username = username;
	}

	string getUsername() {
		return username;
	}

	void setPassword(string password) {
		this->password = password;
	}

	string getPassword() {
		return password;
	}

	void setRole(string role) {
		this->role = role;
	}

	string getRole() {
		return role;
	}

	void inputUser() {
		system("cls");
		cout << "\t\t=================== ADD USER ===================" << endl;
		cout << "\tEnter username: ";
		cin >> username;
		cout << "\tEnter password: ";
		cin >> password;
		cout << "\tEnter Role: ";
		cin >> role;
	}

	void outputUser() {
		cout << "**************************************************" << endl;
		cout << "Username: " << username << endl;
		cout << "Password: " << password << endl;
		cout << "Type: " << role << endl;
		cout << "**************************************************" << endl;
	}
};