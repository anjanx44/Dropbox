#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--) {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("Case %d: %d\n",cas++,a+b);
    }
    return 0;
}
