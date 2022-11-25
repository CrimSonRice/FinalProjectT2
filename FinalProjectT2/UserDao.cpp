#pragma once
#include <iostream>
#include "User.cpp"
using namespace std;

class UserManagerDAO {
public:
	virtual void addUser(User user) = 0;
	virtual void viewUser() = 0;
	virtual int findUserByName(string name) = 0;
	virtual User* getUserByName(string name) = 0;
	virtual void editUserRole(string name) = 0;
	virtual void editUserName(string name) = 0;
	virtual void editUserPassword(string name) = 0;
	virtual void deleteUser(string name) = 0;
	virtual void searchUser(string name) = 0;
};