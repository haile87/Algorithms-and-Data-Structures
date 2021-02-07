#ifndef ACCESSMAP_H
#define ACCESSMAP_H

using namespace std;

class Access {
    public:
        void activate(unsigned int code,unsigned int level);
        void deactivate(unsigned int code);
        bool isactive(unsigned int code, unsigned int level) const;
        bool dooropened(unsigned int enteredcode, unsigned int level);
    private:
        unsigned int code;
        unsigned int level;
};

#endif // ACCESSMAP_H
