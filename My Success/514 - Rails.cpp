/*
Shiakh Shiam Rahman 
UVa : 514 - Rails
*/

#include <iostream>
#include <iostream>
#include "cstdio"
#include "stack"
#include "queue"
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    stack< int > s;
    queue< int > q;
    int i,j,a,n;
    while(scanf("%d",&n)&&n)
    {
        B : ;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(a==0){puts(""); goto A;}
            q.push(a);
        }
        for(j=1;j<=n;)
        {
            if(j==q.front()){ j++; q.pop();}
            else if(!s.empty()&&s.top()==q.front())
            {
                s.pop();
                q.pop();
            }
            else
            {
                s.push(j);
                j++;
            }
        }
        while(!s.empty())
        {
            if(s.top()==q.front())
            {
                s.pop();
                q.pop();
            }
            else break;
        }
        if(s.empty())
            puts("Yes");
        else puts("No");
        while(!s.empty()) s.pop();
        while(!q.empty()) q.pop();
        goto B;
        A: ;
    }
    return 0;
}
