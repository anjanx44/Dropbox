/*
Shiakh Shiam Rahman 
UVa : 484 - TDRD
*/
#include <iostream>
#include <map>
#include <cstdio>
#include <set>
#include <queue>
using namespace std;

#define READ(filename) freopen(filename, "r", stdin);
#define WRITE(filename) freopen(filename, "w", stdout);

int main()
{
    READ("in.txt");
   map<int,int >m;
   set< int > s;
   set< int > :: iterator it;
   queue <int> q;
   int a,size=0;
   //scanf("%d %d",&a,&b);
   while(cin>>a)
   {
       m[a]++;
       s.insert(a);
       if(size<s.size())
       {
            q.push(a);
            size=s.size();
       }

   }
   while( !q.empty() ) {
         cout << q.front() <<" "<<m[q.front()]<<endl;
        q.pop(); // removing that one
    }



    return 0;
}
