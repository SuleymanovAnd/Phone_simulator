#include <iostream>
bool isNum (std::string num){
    int i = 0;
    if (num.size() == 12 && num[0] == '+'){
        i = 1;
    }
    for (;i < num.size();i++){
        if (!isdigit(num[i])) return false;
    }
    return true;
}