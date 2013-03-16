/*
Shiakh Shiam Rahman 
UVa : 10282 - BabelFish
*/
#include <iostream>
#include <map>
#include<stdio.h>

using namespace std;
#define READ(filename) freopen(filename, "r", stdin);
#define WRITE(filename) freopen(filename, "w", stdout);

int main()
{
   map<string,string> m;
   //map<,int> m

   READ("in.txt");

   string goru;
   char ch1[20],ch2[20],ch[100];
    int t;
    bool b;
    /*
    while( cin >> goru )
    {
        if( goru == "moro" ) break;
        m[ goru ] ++;
        cout << goru <<" ase " << m[ goru ] << " ta :D " << endl;
    }
    while(cin>>goru){cout<<m[goru]<<"\n";}
    */

    while(1)
    {
        gets(ch);
        //cin>>ch2>>ch1;
        t=sscanf(ch,"%s %s",&ch1,&ch2);
        //sprintf(ch1,"%s",ch2);
        if(t<=0)
            break;
        goru=string(ch2);
        m[goru]=string(ch1);

    }

    while(cin>>goru)
    {
        b=m[goru].empty();
        if(!b)
            cout<<m[goru]<<"\n";
        else
            printf("eh\n");
    }

    return 0;
}
