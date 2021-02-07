#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<int> vint;
    int i = 1;
    for(i=1;i<=30;i++){
        vint.insert(vint.begin(),i);
    }
    vint.insert(vint.end(),5);
    vector<int>::iterator vit;
    vector<int>::reverse_iterator vitr1;
    vector<int>::reverse_iterator vitr2;
    reverse(vitr1,vitr2);
    vector<int>::iterator vit3 = vint.begin();
    for(vit3 = vint.begin();vit3!=vint.end();vit3++){
        cout << *vit3 << endl;
    }
    cout << endl;
    vit = vint.begin();
    vector<int>::iterator vit2 = vint.end();
    replace(vint.begin(),vint.end(),5,129);
    for(vit = vint.begin();vit!=vint.end();vit++){
        cout << *vit << endl;
    }
    return 0;
}
