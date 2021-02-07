#include <iostream>
#include <map>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    map<string,string> m;
    string s;
    string nums;
    ifstream filex;
    filex.open("data.txt");
    ofstream filey;
    if(filex.is_open()!=true){
        cerr << "Error opening file data.txt" << endl;
        exit(1);
    }
    while(filex.eof()!=true){
        getline(filex,s,'-');
        getline(filex,nums,'\n');
        m.insert(pair<string,string>(s,nums));
    }
    filex.close();
    cout << "Enter a name" << endl;
    string y;
    getline(cin, y);
    if((m.find(y))!=m.end()){
        cout << "The birth date of " << y << " is" << m.at(y) << endl;
    }else
        cout << "Name not found" << endl;
    return 0;
}
