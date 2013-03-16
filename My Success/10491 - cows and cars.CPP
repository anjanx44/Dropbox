/*
Shiakh Shiam Rahman 
UVa : 10491 - cows and cars
*/
#include"stdio.h"
#include"iostream"

using namespace std;

int main()
{
	double ans,ncows,ncars,nshow;
	//freopen("Input.txt","r",stdin);
	while(cin>>ncows>>ncars>>nshow)
	{
		ans=(1.0*(ncows*ncars+ncars*(ncars-1))/(ncows+ncars-nshow-1))/(ncows+ncars);
		printf("%.5lf\n",ans);
	}
	return 0;
}