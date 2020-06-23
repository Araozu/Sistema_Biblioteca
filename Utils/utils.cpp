//
// Created by Fernando on 22/06/2020.
//
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

std::vector<std::string> splitStr(const std::string &strToSplit, char delimeter) {
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter)) {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}

