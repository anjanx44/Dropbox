#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        printf("Case %d: ",cas++);
        if((a+b)%2==(c+d)%2)
        {
            if(abs(a-c)==abs(b-d))
                printf("1\n");
            else
                printf("2\n");
        }
        else printf("impossible\n");
    }
    return 0;
}
