#include <iostream>
#define sum(n) n*(n+1)/2
using namespace std;

int f(long int n)
{
if (sum(n)%3) return 0;
else return 1;
}

int main()
{
	int t, i;
	cin >> t;
	int ans;
	long int m, n, temp;
	for (i=1; i<=t; i++)
	{
		cin >> m >> n;

		temp = n - m;

		if (temp%3==0) ans = temp*2/3 + f(n);
		else if (temp%3==1) ans = (temp-1)*2/3 + f(n) + f(n-1);
		else ans = (temp-2)*2/3 + 2;

		cout << "Case "<< i<<": "<< ans << endl;
	}
return 0;
}
