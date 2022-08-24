#include <iostream>
#include <vector>
#include "phone.h"
using namespace std;

int main() {
    Phone* newPhone = new Phone ();
    string command;


    while (command != "exit"){
        cout << ":";
        cin >> command;

        if (command == "add") {
            newPhone ->add ();
        }
        if (command == "call"){
            newPhone ->call ();
        }
        if (command == "sms"){
            newPhone -> sms ();
        }
        if (command == "exit"){
            newPhone -> exit ();
        }
    }
    delete newPhone;
    newPhone = nullptr;
}
