/*
Shiakh Shiam Rahman 
UVa : 10179 - Irreducible Fractions
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)

using namespace std;

#define READ(filename) freopen(filename, "r", stdin);
#define WRITE(filename) freopen(filename, "w", stdout);
# define ull unsigned long long
# define ll long long
# define u unsigned
#define  MX 1000000000
int N =MX,prime[1000000];
bool  status[MX+100];
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#define For(a) for ( i = 0; i < a; i++ )
#define Rep(a, b) for ( i = a; i <= b; i++ )
#define N 1000000
using namespace std;

int phi (int n)
{
    if ( n == 1 )
        return 0;

    int output = n;

    if ( n % 2 == 0 ) {
        output -= (output / 2);
        while ( n % 2 == 0 )
            n /= 2;
    }

    for ( int i = 3; i * i <= n; i += 2 ) {
        if ( n % i == 0 ) {
            output -= (output / i);
            while ( n % i == 0 )
                n /= i;
        }
    }

    if ( n > 1 )
        output -= (output / n);

    return output;
}

int main ()
{
    int n;
    while ( scanf ("%d", &n) && n ) {
        printf ("%d\n", phi (n));
    }
    return 0;
}
