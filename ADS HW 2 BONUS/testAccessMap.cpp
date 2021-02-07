#include <iostream>
#include "AccessMap.h"

using namespace std;

int main()
{
    Access mobj;
    mobj.activate(1234,1);
    mobj.activate(9999,5);
    mobj.activate(9876,9);
    unsigned int x = 0, y = 0;
    cout << "Please enter an Access Code" << endl;
    cin >> x;
    bool v = mobj.dooropened(x,5);
    while(!v){
        cin >> x;
        v = mobj.dooropened(x,5);
    }
    cout << endl;
    mobj.deactivate(x);
    mobj.activate(9999,8);
    mobj.activate(1111,7);
    cout << "Please enter an Access Code" << endl;
    cin >> y;
    bool r = mobj.dooropened(y,7);
    while(!r){
        cin >> y;
        r = mobj.dooropened(y,7);
    }
    return 0;
}
