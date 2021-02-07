#include <iostream>
#include "WindGauge.h"
#include <algorithm>
#include <deque>
#include <iterator>

using namespace std;

deque<int> windhistory;
WindGauge::WindGauge(int period){
    period = 12;
}
int p = 0, g = 1;
void WindGauge::currentWindSpeed(int speed){
    if(p<12)
        windhistory.push_front(speed);
    else{
        cout << *(windhistory.end() - g)<< " has been erased from history" << endl;
        windhistory.erase(windhistory.end());
        windhistory.push_front(speed);
    }
    p++;
}
int WindGauge::highest()const{
    return *max_element(windhistory.begin(),windhistory.end());
}
int WindGauge::lowest()const{
    return *min_element(windhistory.begin(),windhistory.end());
}
int WindGauge::average()const{
    deque<int>::iterator diter = windhistory.begin();
    int i = 0, sum = 0;
    for(diter=windhistory.begin();diter!=windhistory.end();diter++){
        i++;
        sum  = sum + *diter;
    }
    return sum/i;
}
void WindGauge::dump(int x,int y,int z){
    cout << "The lowest wind speed is " << x << endl;
    cout << "The highest wind speed is " << y << endl;
    cout << "The average wind speed is " << z << endl;
}
