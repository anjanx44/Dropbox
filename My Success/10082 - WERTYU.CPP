/*
Shiakh Shiam Rahman 
UVa : 10082 - WERTYU
*/
#include <iostream>
#include <string>
using namespace std;

int main() {

    char c;
    string s="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    cin.unsetf(ios::skipws);

    freopen("Input.txt","r",stdin);
    while(cin >> c) {
        if(c=='\n')cout<<endl;
        else if (c != ' ' && c != '\n') {
            int k = s.find(c);
            if (k >= 0)
                cout << s[k-1];
        } else
            cout << c;
    }
    return 0;
}
