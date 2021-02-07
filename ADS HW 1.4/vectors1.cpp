#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> vstring(100);
    string str;
    int i = 0;
    while(1){
        getline(cin,str);
        if(str=="END"){
            break;
        }
        vstring[i]=str;
        i++;
    }
    int j,k;
    vector<string>::iterator siter;
    for(j=0;j<i;j++){
        vstring.push_back(vstring[j]);
    }
    for(k=0;k<i;k++){
        cout << vstring[k] << ' ';
    }
    int s = 0;
    cout << endl;
    siter=vstring.begin();
    while(siter!=vstring.end()){
            char c = ',';
            cout << *siter;
            siter++;
            s++;
            if(s<i){
                cout << c;
            }
            if(s==i){
                break;
            }

    }
    return 0;
}
