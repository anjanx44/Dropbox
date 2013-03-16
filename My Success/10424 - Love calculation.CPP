/*
Shiakh Shiam Rahman 
UVa : 10424 - Love calculation
*/
#include<stdio.h>
int calcu(char a[],int n);
int add(int d);
int main() {
    int c,d;
    float res;
    char a[50],b[50];
    while(gets(a)&&gets(b)) {
        c=calcu(a,50);
        d=calcu(b,50);
        if(c<d)
            res=c/(float)d*100;
        else
            res=d/(float)c*100;
        printf("%.2f %%\n",res);
    }
    return 0;
}



int calcu(char a[],int n) {
    int c,d=0,i;
    for(i=0; a[i]!='\0'; i++) {
        if(a[i]>=65&&a[i]<=90) {
            c=a[i]-64;
            d+=c;
        } else if(a[i]>=97&&a[i]<=122) {
            c=a[i]-96;
            d+=c;
        }
    }
    while(d>9)
        d=add(d);


    return(d);
}


int add(int d) {
    int e,f=0;
    while(d!=0) {
        e=d%10;
        d/=10;
        f+=e;
    }
    return(f);
}

