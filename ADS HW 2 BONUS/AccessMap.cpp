#include <iostream>
#include <map>
#include <iterator>
#include <utility>
#include <algorithm>
#include "AccessMap.h"

using namespace std;

map<unsigned int,unsigned int> maccess;
void Access::activate(unsigned int code,unsigned int level){
    maccess.insert(pair<unsigned int,unsigned int>(code,level));
    cout << code << " successfully activated with access level " << level << endl;
}
bool Access::isactive(unsigned int code,unsigned int level)const{
    if((maccess.find(code))!=(maccess.end()))
        return true;
    return false;
}
bool Access::dooropened(unsigned int enteredcode,unsigned int level){
    map<unsigned int,unsigned int>::iterator mit = maccess.begin();
    for(mit=maccess.begin();mit!=maccess.end();){
        if(level==maccess[enteredcode]){
            cout << "Access Granted! Correct Code Entered! Door opened with Access Level: " << level << endl;
            return true;
        }
        mit++;
    }
    cout << "Wrong access code. Please try again." << endl;
    return false;
}
void Access::deactivate(unsigned int code){
    if(isactive(code,level)){
        maccess.erase(code);
        cout << code << " successfully deactivated!" << endl;
    }
}

