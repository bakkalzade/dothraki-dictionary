//
// Created by salih on 22.12.2021.
//

#ifndef ASS4_HELPER_H
#define ASS4_HELPER_H

#include <string>
#include <fstream>
#include "vector"
#include "iostream"
#include "algorithm"


using namespace std;

class Helper {

public:
    static vector<string> readFile(const string& file);

    static vector<string> split (string s, string delimiter);

    static bool contains(vector<string>, string i);

    static void write(string fileName,string message);

    static char* stringToCharArr(string);


};


#endif //ASS4_HELPER_H
