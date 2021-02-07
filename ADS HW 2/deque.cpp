#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<float> A;
    float x = 0.0;
    int i = 0;
    cout << "Enter floating point numbers please" <<  endl;
    cin >> x;
    int counter = 1;
    if(x!=0.0)
        A.push_back(x);
    for(i=0;x!=0.0;i++){
        cin >> x;
        if(x>0.0){
            A.push_back(x);
            counter++;
        }
        else if(x<0.0){
            A.push_front(x);
            counter++;
        }
    }
    int m = 0;
    deque<float>::iterator dfloat = A.begin();
    for(dfloat=A.begin();dfloat!=A.end();dfloat++){
        cout << *dfloat;
        if(m == counter-1)
            break;
        cout << ' ';
        m++;
    }
    deque<float>::iterator posit;
    posit = A.begin() + counter/2;
    A.insert(posit,0);
    cout << endl;
    cout << endl;
    int r = 0;
    for(dfloat=A.begin();dfloat!=A.end();dfloat++){
        cout << *dfloat;
        if(r == counter)
            break;
        cout << ';';
        r++;
    }
    cout << endl;
    return 0;
}
