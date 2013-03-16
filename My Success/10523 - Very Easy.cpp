/*
Shiakh Shiam Rahman 
UVa : 10523 - Very Easy
*/
#include <iostream>
#include <cstdio>
#include "cstring"
#define MAXC 2600
#define REPR(i, a, b) for(i=b ; i>=a ; i--)
#define REP(i, a, b) for(i=a ; i<b ; i++)
using namespace std;

char pow[20][160][MAXC]={0};
char mls[20][160][MAXC]={0};
char fin[20][160][MAXC]={0};
int RES[MAXC];
char RES2[MAXC];
int NUM, POW;
char NUMS[1023];
char IPOW[100];



int strpow(char *num, char *ml) {
    int SP1 = strlen(num) - 1;
    int SP2 = strlen(ml) - 1;
    int SP3 = 0 ;
    int I, J, K, CUR, CAR;

    REPR(I, 0, SP1) {
        for (K=SP3, J=SP2, CAR=0 ; J>=0 ; J--, K++) {
            CUR = ((num[I]-'0')*(ml[J]-'0')) + RES[K] + CAR;
            CAR = 0;
            if (CUR>9) {
                CAR = CUR/10;
                CUR = CUR%10;
            } else {
                CAR = 0;
            }
            RES[K]=CUR;
        }
        if (CAR!=0) RES[K]=CAR;
        SP3++;
    }

    while (RES[K]==0) K--;

    for (I=0; K>=0 ; K--, I++) {
        pow[NUM][POW][I] = RES[K]+'0';
        RES[K] = 0;
    }
    if (I==0) {
        pow[NUM][POW][I++]='0';
    }
    pow[NUM][POW][I]='\0';

    return 0;
}

int strmls(char *num, char *ml) {
    int SP1 = strlen(num) - 1;
    int SP2 = strlen(ml) - 1;
    int SP3 = 0 ;
    int I, J, K, CUR, CAR;

    REPR(I, 0, SP1) {
        for (K=SP3, J=SP2, CAR=0 ; J>=0 ; J--, K++) {
            CUR = ((num[I]-'0')*(ml[J]-'0')) + RES[K] + CAR;
            CAR = 0;
            if (CUR>9) {
                CAR = CUR/10;
                CUR = CUR%10;
            } else {
                CAR = 0;
            }
            RES[K]=CUR;
        }
        if (CAR!=0) RES[K]=CAR;
        SP3++;
    }

    while (RES[K]==0) K--;

    for (I=0; K>=0 ; K--, I++) {
        mls[NUM][POW][I] = RES[K]+'0';
        RES[K] = 0;
    }
    if (I==0) {
        mls[NUM][POW][I++]='0';
    }
    mls[NUM][POW][I]='\0';

    return 0;
}

int stradd(char *NUM1, char *NUM2) {
    int LN_1 = strlen(NUM1);
    int LN_2 = strlen(NUM2);
    int TEMP, CAR, CUR, I, J, K;
    char num1[MAXC], num2[MAXC];

    strcpy(num1,NUM1);
    strcpy(num2,NUM2);

    if (LN_2 > LN_1) { /*-------Swap routine incase of the reverse------*/
        TEMP = LN_2;
        LN_2 = LN_1;
        LN_1 = TEMP;
        strcpy(RES2, num1);
        strcpy(num1, num2);
        strcpy(num2, RES2);
    }

    for (I=LN_1, CAR=0, J=LN_2, CAR=0, K=0 ; I>0 ; I--, J--, K++) {
        CUR = (num1[I-1]-'0') + (J<1?0:num2[J-1]-'0') + CAR;
        CAR = 0;
        if (CUR>9) {
            CAR = 1;
            CUR = CUR%10;
        } else {
            CAR = 0;
        }
        RES2[K] = CUR + '0';
    }
    if (CAR) RES2[K++] = CAR + '0';

    for (--K, I=0 ; K>=0 ; K--, I++) {
        fin[NUM][POW][I] = RES2[K];
    }
    fin[NUM][POW][I] = '\0';

    return 0;
}

int main() {

    int I, N, A;
    NUM = 1;
    POW = 1;
    for (I=0 ; I<160 ; I++) {
        strcpy(pow[1][I],"1");
        strcpy(pow[0][I],"0");
    }
    REP(NUM, 1, 20) {
        sprintf(NUMS,"%d",NUM);
        strcpy(pow[NUM][0],"0");
        strcpy(pow[NUM][1],NUMS);
        strcpy(mls[NUM][1],NUMS);
        strcpy(fin[NUM][1],NUMS);

        REP(POW, 2, 160) {
            strpow(pow[NUM][POW-1],NUMS);
            sprintf(IPOW,"%d",POW);
            strmls(pow[NUM][POW],IPOW);
            stradd(fin[NUM][POW-1],mls[NUM][POW]);
        }
    }

    while (scanf("%d %d",&N,&A)!=EOF) {
        if (N==0 || A==0) printf("0\n");
        else printf("%s\n",fin[A][N]);
    }
    return 0;
}

/* header files
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
typedef unsigned uu;
using namespace std;

#define READ(filename) freopen(filename, "r", stdin);
#define WRITE(filename) freopen(filename, "w", stdout);

struct Biguu {
    string a; // to store the digits
    int sign; // sign = -1 for negative numbers, sign = 1 otherwise
    Biguu() {} // default constructor
    Biguu( string b ) { (*this) = b; } // constructor for string
    uu size() { // returns number of digits
        return a.size();
    }

    Biguu inverseSign() { // changes the sign

        sign *= -1;

        return (*this);

    }

    Biguu normalize( uu newSign ) { // removes leading 0, fixes sign

        for( uu i = a.size() - 1; i > 0 && a[i] == '0'; i-- )

            a.erase(a.begin() + i);

        sign = ( a.size() == 1 && a[0] == '0' ) ? 1 : newSign;

        return (*this);

    }



    // assignment operator

    void operator = ( string b ) { // assigns a string to Biguu

        a = b[0] == '-' ? b.substr(1) : b;

        reverse( a.begin(), a.end() );

        this->normalize( b[0] == '-' ? -1 : 1 );

    }



    // conditional operators

    bool operator < ( const Biguu &b ) const { // less than operator

        if( sign != b.sign ) return sign < b.sign;

        if( a.size() != b.a.size() )

            return sign == 1 ? a.size() < b.a.size() : a.size() > b.a.size();

        for( uu i = a.size() - 1; i >= 0; i-- ) if( a[i] != b.a[i] )

            return sign == 1 ? a[i] < b.a[i] : a[i] > b.a[i];

        return false;

    }

    bool operator == ( const Biguu &b ) const { // operator for equality

        return a == b.a && sign == b.sign;

    }
    // mathematical operators

    Biguu operator + ( Biguu b ) { // addition operator overloading

        if( sign != b.sign ) return (*this) - b.inverseSign();

        Biguu c;

        for(uu i = 0, carry = 0; i<a.size() || i<b.size() || carry; i++ ) {

            carry+=(i<a.size() ? a[i]-48 : 0)+(i<b.a.size() ? b.a[i]-48 : 0);

            c.a += (carry % 10 + 48);

            carry /= 10;

        }

        return c.normalize(sign);

    }

    Biguu operator - ( Biguu b ) { // subtraction operator overloading

        if( sign != b.sign ) return (*this) + b.inverseSign();

        uu s = sign; sign = b.sign = 1;

        if( (*this) < b ) return ((b - (*this)).inverseSign()).normalize(-s);

        Biguu c;

        for( uu i = 0, borrow = 0; i < a.size(); i++ ) {

            borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);

            c.a += borrow >= 0 ? borrow + 48 : borrow + 58;

            borrow = borrow >= 0 ? 0 : 1;

        }

        return c.normalize(s);

    }

    Biguu operator * ( Biguu b ) { // multiplication operator overloading

        Biguu c("0");

        for( uu i = 0, k = a[i] - 48; i < a.size(); i++, k = a[i] - 48 ) {

            while(k--) c = c + b; // ith digit is k, so, we add k times

            b.a.insert(b.a.begin(), '0'); // multiplied by 10

        }

        return c.normalize(sign * b.sign);

    }

    Biguu operator / ( Biguu b ) { // division operator overloading

        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );

        Biguu c("0"), d;

        for( uu j = 0; j < a.size(); j++ ) d.a += "0";

        uu dSign = sign * b.sign; b.sign = 1;

        for( uu i = a.size() - 1; i >= 0; i-- ) {

            c.a.insert( c.a.begin(), '0');

            c = c + a.substr( i, 1 );

            while( !( c < b ) ) c = c - b, d.a[i]++;

        }

        return d.normalize(dSign);

    }

    Biguu operator % ( Biguu b ) { // modulo operator overloading

        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );

        Biguu c("0");

        b.sign = 1;

        for( uu i = a.size() - 1; i >= 0; i-- ) {

            c.a.insert( c.a.begin(), '0');

            c = c + a.substr( i, 1 );

            while( !( c < b ) ) c = c - b;

        }

        return c.normalize(sign);

    }
    // output method

    void print() {

        if( sign == -1 ) putchar('-');

        for( int i = a.size() - 1; i >= 0; i-- ) putchar(a[i]);

    }

};

Biguu pow[150];
Biguu Sum,A,I,Mul;
uu N;

void power()
{
    Biguu M;
    string m("1");
    M = m;
    uu y=1;
    while(y<=N)
    {
        M = M * A;
        pow[y]= M;
        y++;
    }
}

int main() {
  //  READ("in.txt");
    char a[10],ch[15],ii[10];
    while(gets(ch))
    {
        string sum("0");
        Sum = sum;
        sscanf(ch,"%d %s",&N,a);
        if(a==0)printf("0\n");
        string input(a);
        A = input;
        Mul = A;
        power();
        for(uu i=1;i<=N;i++){
            sprintf(ii,"%d",i);
            string II(ii);
            I = II;
            Sum=I*pow[i]+Sum;
           // Sum.print(); puts("");
        }
        Sum.print(); puts("");
    }
    return 0;

}
*/
