#include <iostream>
#include "WindGauge.h"

using namespace std;
WindGauge wobj;

int main()
{
    wobj.currentWindSpeed(15);
    wobj.currentWindSpeed(16);
    wobj.currentWindSpeed(12);
    wobj.currentWindSpeed(15);
    wobj.currentWindSpeed(15);
    int a = wobj.highest();
    int b = wobj.lowest();
    int c = wobj.average();
    wobj.dump(b,a,c);
    cout << endl;
    wobj.currentWindSpeed(16);
    wobj.currentWindSpeed(17);
    wobj.currentWindSpeed(16);
    wobj.currentWindSpeed(16);
    wobj.currentWindSpeed(20);
    wobj.currentWindSpeed(17);
    wobj.currentWindSpeed(16);
    wobj.currentWindSpeed(15);
    wobj.currentWindSpeed(16);
    wobj.currentWindSpeed(20);
    int g = wobj.highest();
    int h = wobj.lowest();
    int k = wobj.average();
    wobj.dump(h,g,k);
    return 0;
}
