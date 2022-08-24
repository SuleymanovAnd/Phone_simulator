#include "number.h"

void Number::addNumber (const string num) {
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

void Number::addName(const string name){
    nameOfNumber.push_back(name);
}

int Number::findNum (string num){
    for (int i = 0; i< number.size();i++){
        if (number[i] == stoll(num)) {
            return i;
        }
    } return -1;
}

int Number::findName (string name){
    for (int i = 0; i< nameOfNumber.size();i++){
        if (nameOfNumber[i] == name) {
            return i;
        }
    } return -1;
}
long long Number::getNumber (int nOfNumber){
    return number [nOfNumber];
}

string Number::getName (int nOfNumber){
    return nameOfNumber [nOfNumber];
}