#include <iostream>
#include <vector>
#include "isNum.h"
#include "number.h"
#include <limits>
#pragma once

class Phone {
    Number* contactsBook = new Number();

    vector <string> smsList;

    int findNumOfContact (){
        cout << "Enter number or name of contact: ";
        string tmp;
        {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(std::cin,tmp);
        }
        int nOfContact = -1;
        // проверка ввода на число
        if (isNum(tmp)){
            nOfContact = contactsBook -> findNum(tmp);

        } else { // если не число, то имя
            nOfContact = contactsBook -> findName(tmp);
        }
        return nOfContact;
    }

public:
    // ДОБАВЛЕНИЕ КОНТАКТА
    void add ();
    // ЗВОНОК
    void call ();
    // CMC
    void sms ();
    void exit ();
};