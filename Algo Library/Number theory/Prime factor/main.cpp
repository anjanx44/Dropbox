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
//#define N 1000000
#define ll long long

using namespace std;

int List[128];  // saves the List
int listSize;   // saves the size of List

int N = 5000;
int status[5001];
int prime[5001];

void primeFactorize() {
    ll n = 6857;
    listSize = 0;   // Initially the List is empty, we denote that size = 0
    int sqrtN = int( sqrt(n) ); // find the sqrt of the number
    for( int i = 0; prime[i] <= sqrtN; i++ ) { // we check up to the sqrt
        if( n % prime[i] == 0 ) { // n is multiple of prime[i]
            // So, we continue dividing n by prime[i] as long as possible
            while( n % prime[i] == 0 ) {
                n /= prime[i]; // we have divided n by prime[i]
                List[listSize] = prime[i]; // added the ith prime in the list
                listSize++; // added a prime, so, size should be increased
                printf("%d ",prime[i]);
            }
            // we can add some optimization by updating sqrtN here, since n
            // is decreased. think why it's important and how it can be added
        }
    }
    if( n > 1 ) {
        // n is greater than 1, so we are sure that this n is a prime
        List[listSize] = n; // added n (the prime) in the list
        listSize++; // increased the size of the list
    }
}
int main() {
    int i,j;
        for( i = 2; i <= N; i++ )
    status[i] = 0;
    for( i = 2; i <= N; i++ ) {
        if( status[i] == 0 ) {
            // so, i is a prime, so, discard all the multiples
            // j = 2 * i is the first multiple, then j += i, will find the
            // next multiple
            for( j = 2 * i; j <= N; j += i )
                status[j] = 1; // status of the multiple is 1
        }
    }
    // print the primes
    for( i = 2,j=0; i <= N; i++ ) {
        if( status[i] == 0 ) {
            // so, i is prime
            //printf("%d ", i);
            prime[j++] = i;
        }
    }
    primeFactorize();
    for( int i = 0; i < listSize; i++ ) // traverse the List array
        printf("%d ", List[i]);
    return 0;
}
