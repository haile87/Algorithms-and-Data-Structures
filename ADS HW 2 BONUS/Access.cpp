#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include "Access.h"

using namespace std;

set<unsigned int> saccess;
void Access::activate(unsigned int code){
    saccess.insert(code);
    cout << code << " successfully activated!" << endl;
}
bool Access::isactive(unsigned int code)const{
    if((saccess.find(code))!=(saccess.end()))
        return true;
    return false;
}
bool Access::dooropened(unsigned int enteredcode)const{
    set<unsigned int>::iterator sit = saccess.begin();
    for(sit=saccess.begin();sit!=saccess.end();){
        if(enteredcode==*(sit)){
            cout << "Access Granted! Door opened!" << endl;
            return true;
        }
        sit++;
    }
    cout << "Wrong access code. Please try again." << endl;
    return false;
}
void Access::deactivate(unsigned int code){
    if(isactive(code)){
        saccess.erase(code);
        cout << code << " successfully deactivated!" << endl;
    }
}
