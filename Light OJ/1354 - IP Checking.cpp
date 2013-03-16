#include <iostream>
#include <bitset>
#include <cstdio>
using namespace std;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
int main()
{
    bitset<8> x[6];
    int tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        printf("Case %d: ",cas++);
        unsigned a,b,c,d;
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        char ch;
        cin>>x[0]>>ch>>x[1]>>ch>>x[2]>>ch>>x[3];
        if(a==x[0].to_ulong() && b==x[1].to_ulong() && c==x[2].to_ulong() && d==x[3].to_ulong())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
