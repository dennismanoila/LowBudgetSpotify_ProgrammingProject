
#ifndef LOWBUDGETSPOTIFY_APP_H
#define LOWBUDGETSPOTIFY_APP_H

#include <iostream>
#include <string>
#include <list>
#include <cstring>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include "user.h"
#include "song.h"
#include "playlist.h"
#include "utils.h"


void display_initialPage();
void display_mainMenu(const std::string& name, const std::string& surname);
void signUpProcess();
void loginProcess();
void exitProcess();

#endif //LOWBUDGETSPOTIFY_APP_H
