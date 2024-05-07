
#ifndef LOWBUDGETSPOTIFY_USER_H
#define LOWBUDGETSPOTIFY_USER_H

#include <iostream>
#include <string>
#include <list>
#include <cstring>
#include <fstream>
#include <sstream>

extern std::list<struct User> globalUserList;

struct User {
    std::string name;
    std::string surname;
    std::string password;
};

void loadUsersFromTXT();
int userInput();
void createUser(std::string& name, std::string& surname);
int searchUser(const std::string& name, const std::string& surname);
void addUserToTXT(const std::string& name, const std::string& surname, const std::string& password);


#endif //LOWBUDGETSPOTIFY_USER_H
