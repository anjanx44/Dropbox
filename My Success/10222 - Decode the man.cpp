/*
Shiakh Shiam Rahman 
UVa : 10222 - Decode the man
*/
#include <iostream>
#include <string>
using namespace std;

int main() {

    char c,ch;
    string s="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    cin.unsetf(ios::skipws);

    //freopen("Input.txt","r",stdin);
    while(cin >> c) {
        c=toupper(c);
        if(c=='\n')cout<<endl;
        else if (c != ' ' && c != '\n') {
            int k = s.find(c);
            if (k >= 0) {
                ch=tolower(s[k-2]);
                cout << ch;
            }
        } else
            cout << c;
    }
    return 0;
}
