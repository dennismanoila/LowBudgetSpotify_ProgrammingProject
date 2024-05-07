
#ifndef LOWBUDGETSPOTIFY_UTILS_H
#define LOWBUDGETSPOTIFY_UTILS_H

#include <cctype>
#include "app.h"

std::string toLower(std::string str);
void nullArr(std::string arr[100]);
int inArr(std::string arr[100], const std::string& str, int size);
void parseAndPrint(const std::string& songString);
bool checkIfSubstr(const std::string& str, const std::string& substr);
void removeDoubleCommas(std::string& str);

#endif //LOWBUDGETSPOTIFY_UTILS_H
