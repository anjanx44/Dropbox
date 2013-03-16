#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--) {
        int b;
        scanf("%d",&b);
        if(b>10)
            printf("%d 10\n",b-10);
        else
            printf("0 %d\n",b);
    }
    return 0;
}

