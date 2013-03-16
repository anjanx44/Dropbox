#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    int tc,cas=1,i,j;
    scanf("%d",&tc);
    while(tc--)
    {
        char c[13],h[13];
        scanf("%s",c);

        for(j=0,i=strlen(c)-1;i>=0;i--,j++)
            h[j]=c[i];
        h[j]=NULL;
        //cout<<"\nstring : "<<c<<" "<<h<<endl;
        printf("Case %d: ",cas++);
        if(!strcmp(c,h))
            printf("Yes\n");
        else
            printf("No\n");

    }
    return 0;
}
