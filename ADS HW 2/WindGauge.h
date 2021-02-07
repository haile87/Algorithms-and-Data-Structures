#ifndef WINDGAUGE_H
#define WINDGAUGE_H
#include <iostream>
#include <deque>

using namespace std;

class WindGauge{
    public:
        WindGauge(int period = 12);
        void currentWindSpeed(int speed);
        int highest() const;
        int lowest() const;
        int average() const;
        void dump(int,int,int);
    private:
        int speed;
        int period;
};


#endif // WINDGAUGE_H

