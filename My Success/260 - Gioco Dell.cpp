/*
Shiakh Shiam Rahman 
UVa : 260 - Gioco Dell
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long
using namespace std;

int n;
char a [200 + 5] [200 + 5];
bool vis [200 + 5] [200 + 5];
char output;

void dfs (int x, int y, char curr)
{
	if ( x < 0 || y < 0 || x == n || y == n || a [x] [y] != curr || vis [x] [y] ) return;
	if ( y == n - 1 && a [x] [y] == 'w' ) { output = 'W'; return; }
	if ( x == n - 1 && a [x] [y] == 'b' ) { output = 'B'; return; }

	vis [x] [y] = true;

	int dr [] = {-1, -1, 0, 0, 1, 1};
	int dc [] = {-1, 0, -1, 1, 0, 1};

	for ( int i = 0; i < 6; i++ )
		dfs (x + dr [i], y + dc [i], curr);
}

int main(int argc, char **argv) {
    freopen("in.txt","r",stdin);
	int cases = 0;

	while ( scanf ("%d", &n) && n ) {
		for ( int i = 0; i < n; i++ ) scanf ("%s", a [i]);

		memset (vis, false, sizeof (vis));

		for ( int i = 0; i < n; i++ )
			if ( !vis [0] [i] && a [0] [i] == 'b' ) dfs (0, i, 'b');

		for ( int i = 0; i < n; i++ )
			if ( !vis [i] [0] && a [i] [0] == 'w' ) dfs (i, 0, 'w');

		printf ("%d %c\n", ++cases, output);
	}
	return 0;
}
