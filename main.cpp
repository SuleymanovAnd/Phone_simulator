#include <iostream>
#include <vector>
#include <limits>
using namespace std;

bool isNum (string num){
    int i = 0;
    if (num.size() == 12 && num[0] == '+'){
        i = 1;
    }
    for (;i < num.size();i++){
        if (!isdigit(num[i])) return false;
    }
    return true;
}

class number{
   vector <long long> number;
   vector <string> nameOfNumber;
public:

    void addNumber (const string num){
        // если номер из 10 символов
        if(num.size() == 10){
            long long tmp = 70000000000;
            try{
                if (isNum(num)){tmp += stoll(num);}
            }
            catch (const std::exception & obj){
                std::cerr << obj.what();
            }
            number.push_back(tmp);
        } else if (num.size() == 12) { // если номер из 12 символов
            if (num[0] == '+' && num [1] == '7'){
                try {
                    if (isNum(num)) {number.push_back(stoll(num));}
                } catch (const std::exception & obj){
                    std::cerr << obj.what();
                }
            }else {cout << "Invalid number format\n";}
        }
    }

    void addName(const string name){
        nameOfNumber.push_back(name);
    }
    int findNum (string num){
        for (int i = 0; i< number.size();i++){
            if (number[i] == stoll(num)) {
                return i;
            }
        } return -1;
    }

    int findName (string name){
        for (int i = 0; i< nameOfNumber.size();i++){
            if (nameOfNumber[i] == name) {
                return i;
            }
        } return -1;
    }

    long long getNumber (int nOfNumber){
        return number [nOfNumber];
    }

    string getName (int nOfNumber){
        return nameOfNumber [nOfNumber];
    }
};


class phone {
    number* contactsBook = new number();

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
    void add (){
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
    void call (){
        // ищем контакт в книге
        int nOfContact = findNumOfContact();
        // звоним контакту
        if (nOfContact != -1){

            cout << "CALL " << contactsBook ->getName (nOfContact) << " "
                 << contactsBook ->getNumber(nOfContact) <<"!\n";
        } else { cout << "Contact not found!";}
    }
    // CMC
    void sms () {
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
    void exit (){
        delete contactsBook;
        contactsBook = nullptr;
    }
};

int main() {
    phone* newPhone = new phone ();
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
