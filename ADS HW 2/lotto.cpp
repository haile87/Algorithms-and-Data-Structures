#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    set<int> sint;
    srand(time(NULL));
    int y = 0;
    for(y=0;y<6;y++){
        int x = rand() % 49 + 1;
        sint.insert(x);
    }
    set<int>::iterator siter = sint.begin();
    for(siter=sint.begin();siter!=sint.end();siter++){
        if(siter == sint.begin()){
            if(*(sint.begin())<*(siter++))
                continue;
            else{
                int temp = *(sint.begin());
                sint.insert(siter++,temp);
                sint.insert(sint.begin(),*(siter++));
            }
        }
        else{
            if(*(siter)<*(siter++))
                continue;
            else{
                int temp2 = *(siter);
                sint.insert(siter++,temp2);
                sint.insert(siter,*(siter++));
            }
        }
    }
    siter = sint.begin();
    int i = 0;
    for(siter=sint.begin();siter!=sint.end();siter++){
        if(i<6)
            cout << *siter << ' ';
        i++;
    }
    return 0;
}
