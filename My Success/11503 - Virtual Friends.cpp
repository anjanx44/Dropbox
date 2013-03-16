/*
Shiakh Shiam Rahman 
UVa : 11503 - Virtual Friends
*/
#include <iostream>
#include "cstdio"
#include "map"
#include "cstring"
#include "string"
using namespace std;

int par[100010];

int find(int r)
{
    if(par[r] < 0)
        return r;
    return par[r]=find(par[r]);
}

int main()
{
    freopen("in.txt","r",stdin);
    map < string , int > man;
    int tc ;

    scanf("%d",&tc);
    while(tc--)
    {
        int cas,i=1;
        memset(par,-1,sizeof(par));
        scanf("%d",&cas);
        while(cas--)
        {
            string s1,s2;
            cin>>s1>>s2;
            if(!man[s1])
                man[s1] = i++;
            if(!man[s2])
                man[s2] = i++;
            int p = find (man[s1]);
            int q = find (man[s2]);

            if ( p == q ) {
                printf ("%d\n", par [p]*-1);
                continue;
            }
            if ( par [p] < par [q] ) {
                par [p] += par [q];
                par [q] = p;
                printf ("%d\n", par [p]*-1);
            }
            else {
                par [q] += par [p];
                par [p] = q;
                printf ("%d\n", par [q]*-1);
            }
        }
        man.clear();
    }
    return 0;
}
