#include <limits>
#include <iostream>
#include "phone.h"
using namespace std;



// ДОБАВЛЕНИЕ КОНТАКТА
void Phone::add (){
    cout << "Enter the name: ";
    string tmp;
    {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(std::cin,tmp);
    }
    contactsBook -> addName (tmp);
    cout << "Enter the number: ";
    cin >> tmp;
    contactsBook -> addNumber(tmp);
}

// ЗВОНОК
void Phone::call (){
    // ищем контакт в книге
    int nOfContact = findNumOfContact();
    // звоним контакту
    if (nOfContact != -1){

        cout << "CALL " << contactsBook ->getName (nOfContact) << " "
             << contactsBook ->getNumber(nOfContact) <<"!\n";
    } else { cout << "Contact not found!";}
}
// CMC
void Phone::sms () {
    // ищем контакт в книге
    int nOfContact = findNumOfContact();
    // пишем смс
    if (nOfContact != -1){
        cout << "Enter massage: ";
        string tmp;
        {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(std::cin,tmp);
        }
        smsList.push_back (tmp);
        cout << "Message sent.\n";
    }else { cout << "Contact not found!";}
}

void Phone::exit (){
    delete contactsBook;
    contactsBook = nullptr;
}