#include <iostream>
#include "Access.h"

using namespace std;

int main()
{
    Access obj;
    unsigned int x = 0, y = 0;
    obj.activate(1234);
    obj.activate(9999);
    obj.activate(9876);
    cout << "Please enter an Access Code" << endl;
    cin >> x;
    bool m = obj.dooropened(x);
    while(!m){
        cin >> x;
        m = obj.dooropened(x);
    }
    cout << endl;
    obj.deactivate(x);
    obj.deactivate(9999);
    obj.activate(1111);
    cout << "Please enter another Access Code" << endl;
    cin >> y;
    bool c = obj.dooropened(y);
    while(!c){
        cin >> y;
        c = obj.dooropened(y);
    }
    return 0;
}
