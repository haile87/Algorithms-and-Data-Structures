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
    int j,k,l;
    string temp;
    vector<string>::iterator siter;
    for(j=0;j<i;j++){
        vstring.push_back(vstring[j]);
    }
    for(l=0;l<i;l++){
        if(l==4){
            temp = vstring[1];
            vstring[1] = vstring[4];
            vstring[4] = temp;
        }
    }
    if(i<5){
        cout << "Element not present. Cannot perform swapping!" << endl;
    }
    int m;
    for(m=0;m<i;m++){
        if(m==i - 1)
            vstring[m] = "???";
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
    cout << endl;
    int y = 0;
    siter=vstring.begin();
    while(siter!=vstring.end()){
            char c = ';';
            cout << *siter;
            siter++;
            y++;
            if(y<i){
                cout << c;
            }
            if(y==i){
                break;
            }

    }
    int z = 0;
    cout << endl;
    cout << "???";
    siter=vstring.end();
    while(siter!=vstring.begin()){
            char c = ' ';
            cout << *siter;
            siter--;
            z++;
            if(z<i){
                cout << c;
            }
            if(z==i){
                break;
            }
    }
    return 0;
}
