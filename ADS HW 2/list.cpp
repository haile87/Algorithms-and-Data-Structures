#include <iostream>
#include <list>
#include <iterator>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    list<int> A;
    list<int> B;
    int i = 0;
    int x = 0;
    cout << "Enter integer numbers please" << endl;
    cin >> x;
    int count1 = 1;
    if(x>0)
        A.push_back(x);
    for(i=0;x>0;i++){
        cin >> x;
        if(x>0)
            A.push_back(x);
        count1++;
    }
    list<int>::iterator la = A.begin();
    for(la=A.begin();la!=A.end();la++){
        B.push_front(*la);
    }
    list<int>::iterator la2 = A.begin();
    for(la2=A.begin();la2!=A.end();la2++){
        cout << *la2 << ' ';
    }
    cout << endl;
    list<int>::iterator la3 = B.begin();
    la = A.begin();
    ofstream filex;
    filex.open("listB.txt");
    if(!filex){
        cerr << "Unable to open file" << endl;
        exit(1);
    }
    for(la3=B.begin();la3!=B.end();la3++){
        filex << *la3 << ' ';
    }
    cout << '\n';
    la3 = A.begin();
    int temp = *la3;
    A.push_back(temp);
    A.erase(la3);
    la2 = B.begin();
    int temp2 = *la2;
    B.push_back(temp2);
    B.erase(la2);

    list<int>:: iterator lint = A.begin();
    list<int>:: iterator lint2 = B.begin();
    int m = 0;
    for(lint=A.begin();lint!=A.end();lint++){
        cout << *lint;
        m++;
        if(m == count1 - 1){
            break;
        }
        cout << ',';
    }
    cout << endl;
    int z = 0;
    for(lint2=A.begin();lint2!=A.end();lint2++){
        cout << *lint2;
        z++;
        if(z == count1 - 1){
            break;
        }
        cout << ',';
    }
    int e = 0;
    cout << endl;
    cout << endl;
    A.sort();
    B.sort();
    A.merge(B);
    A.sort();
    for (list<int>::iterator it=A.begin(); it!=A.end(); ++it){
        cout << *it;
        e++;
        if(e == 2*count1 - 1)
            break;
        cout << ' ';
    }
    cout << endl;
    return 0;
}
