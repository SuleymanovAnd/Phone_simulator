#include <iostream>
#include <vector>
#include "isNum.h"
#pragma once
using namespace std;

class Number{
    vector <long long> number;
    vector <string> nameOfNumber;
public:

    void addNumber (const string num);

    void addName(const string name);

    int findNum (string num);

    int findName (string name);

    long long getNumber (int nOfNumber);

    string getName (int nOfNumber);
};