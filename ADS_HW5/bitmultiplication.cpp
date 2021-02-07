#include <cstdlib>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
/*
   1 is for the right side of the half , -1 for the left side of the half
*/
string stringfill(const string& str, unsigned long long num, char ch, int ret){
    string y(num, ch);
    return ret == -1 ? y + str : str + y;
}

// returns true if the string has only bits that are zeros

bool isZero(const string& str){
    for(unsigned long long  i = 0, l = str.size();i<l;i++)
        if (str[i] != '0')
            return false;
    return true;
}

// returns the sum of numbers represented here as strings
string sumStrings(const string& str1, const string& str2){
    if(str2 == "")
        return str1;
    if(str1 == "")
        return str2;
    string total = "";
    unsigned long long  str1Size =str1.size();
    unsigned long long  str2Size =str2.size();
    unsigned long long  m = max(str1Size, str2Size);
    unsigned int  var = 0;
    for (unsigned int i = 0;i<static_cast<unsigned int>(m);i++) {
        unsigned int  czero = i < str1Size ? str1[str1Size - 1 - i] - '0' : 0;
        unsigned int  c1 = i < str2Size ? str2[str2Size - 1 - i] - '0' : 0;
        unsigned int  c = czero + c1 + var;
        var = c / 2;
        total += (c % 2) + '0';
    }
    if(var)
        total += var + '0';
    reverse(total.begin(), total.end());
    return total;
}

// removes zeros from the left
string removeleftzeros(const string& value){
    if (value.size() > 1 && value[0] == '0')
    {
        for (unsigned long long  i = 0, l = value.size(); i < l; i++)
        {
            if (value[i] == '0')
                continue;
            return value.substr(i, l - i);
        }
    }
    return value;
}

// subtracts strings based on the assumption that the first string is greater than the second one
string substrings(const string& str1, const string& str2){
    if(str2 == "")
        return str1;
    string total = "";
    unsigned long long str1Size = str1.size();
    unsigned long long str2Size = str2.size();
    unsigned int var = 0;
    for(unsigned int i = 0; i < str1Size; i++){
        int czero = str1[str1Size - 1 - i] - '0' - var;
        int c1 = i < str2Size ? str2[str2Size - 1 - i] - '0' : 0;
        var = 0;
        if(czero<c1) {
            var = 1;
            czero += 2;
        }
        total += (czero - c1) + '0';
    }
    reverse(total.begin(), total.end());
    return isZero(total) ? "0" : removeleftzeros(total);
}

string multiplystringchar(const string& str1, const char ch){
    if(ch == '0')
        return "0";
    if(ch == '1')
        return str1;

    int var = 0;
    int dzero = ch - '0';
    string x = "";
    int v = 0;
    for (int j = str1.size() - 1; j >= 0; j--)
    {
        int d1 = str1[j] - '0';
        v = (dzero * d1) + var;
        var = v / 2;
        v %= 2;
        x += v + '0';
    }
    if(var)
        x += var + '0';
    reverse(x.begin(), x.end());
    return x;
}

//brute force implementation
string multiplybruteforce(const string& str1, const string& str2)
{
    list<string> result;
    unsigned int n = 0;
    for (int i = str2.size() - 1;i>=0;i--) {
        result.push_back(stringfill(multiplystringchar(str1, str2[i]), n, '0', 1));
        n++;
    }
    string total = "";
    for(string line : result)
        total = sumStrings(total, line);
    return total;
}

//recursive implementation
string multiply(const string& string1, const string& string2)
{
    if (isZero(string1) || isZero(string2)) {
        return "0";
    }
    string str1 = removeleftzeros(string1);
    string str2 = removeleftzeros(string2);
    unsigned long long m1 = str1.size();
    unsigned long long  m2 = str2.size();

    if (m1 == 1 || m2 == 1)
        return multiplystringchar(m1 == 1 ? str2 : str1, m1 == 1 ? str1[0] : str2[0]);

    unsigned long long n = max(m1, m2);
    n += (n & 1);

    str1 = stringfill(str1, n - m1, '0', -1);
    str2 = stringfill(str2, n - m2, '0', -1);
    unsigned long long t = n / 2;

    string w = str1.substr(0, t);
    string x = str1.substr(t, t);
    string y = str2.substr(0, t);
    string z = str2.substr(t, t);

    string wy = multiply(w, y);
    string xz = multiply(x, z);

    string wx = sumStrings(w, x);
    string yz = sumStrings(y, z);

    string wxyz = multiply(wx, yz);

    wxyz = substrings(wxyz, wy);
    wxyz = substrings(wxyz, xz);

    wy = stringfill(wy, n, '0', 1);
    wxyz = stringfill(wxyz, t, '0', 1);
    string result = sumStrings(wy, wxyz);
    result = sumStrings(result, xz);
    return removeleftzeros(result);
}

int main(){
    cout << multiplybruteforce("11011", "10101") << endl;
    cout << multiply("1011", "1101") << endl;
    return 0;
}
