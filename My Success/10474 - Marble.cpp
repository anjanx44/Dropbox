/*
Shiakh Shiam Rahman 
UVa : 10474 - Marble
*/
#include <iostream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define READ(filename) freopen(filename, "r", stdin);
#define WRITE(filename) freopen(filename, "w", stdout);
#define max 100000

void binary(int arr[],int m,int item)
{
	int beg=1,end=m-1,mid,flag=0,count=1;
	mid=(beg+end)/2;
	if(item==arr[mid])
	{
		cout<<" found at "<<mid+1<<endl;
		flag=1;
	}
	while(beg<=end && item!=arr[mid])
	{
		if(item>arr[mid])
			beg=mid+1;
		else
			end=mid-1;
		mid=(beg+end)/2;
		count++;
		if(item==arr[mid])
		{
			cout<<" found at "<<mid+1<<endl;
			flag=1;
			break;
		}

	}
	if(flag==0)
		cout<<" not found"<<endl;
	//cout<<"Move :"<<count<<endl;
}

int main()
{
    READ("in.txt");
    int kase=1;
    int arr[max];
    int a,b,c;
    while(cin>>a>>b)
    {
        if(a==0 && b==0)break;
        cout<<"CASE# "<<kase++<<":\n";
        for(int i=0;i<a;i++)
        cin>>arr[i];

        sort(arr,arr+a);
        while(b--)
        {
            cin>>c;
            cout<<c;
            binary(arr,a,c);
            //printf("\n");
        }
    }

    return 0;
}
