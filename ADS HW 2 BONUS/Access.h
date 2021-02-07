#ifndef ACCESS_H
#define ACCESS_H
#include <iostream>
#include <set>

using namespace std;

class Access {
    public:
        void activate(unsigned int code);
        void deactivate(unsigned int code);
        bool isactive(unsigned int code) const;
        bool dooropened(unsigned int enteredcode) const;
    private:
        unsigned int code;
};
#endif // ACCESS_H
