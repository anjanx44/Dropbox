/*
Shiakh Shiam Rahman 
UVa : 755 - 487-3279
*/
#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<cstring>
#include<fstream>

using namespace std;
map < string , int > m1;
map < string , int > :: iterator it;
int main()
{
    freopen("Input.txt","r",stdin);
    //freopen("Output.txt","w",stdout);
	char a[1000000],b[1000];
	int i,j,d,n,m,k,x,y,z=0;
	cin>>n;
	for(x=1;x<=n;x++)
	{
	    if(z==1)
	    cout<<endl;
	    z=1;
	    cin>>m;
	    getchar();
        for(d=0;d<m;d++)
        {
            k=0;
            gets(a);
            for(i=0,j=0;a[i]!='\0';i++,j++)
            {
                if(a[i]>=48&&a[i]<=57)
                b[j]=a[i];
                else if(a[i]=='A'||a[i]=='B'||a[i]=='C')
                b[j]=48+2;
                else if(a[i]=='D'||a[i]=='E'||a[i]=='F')
                b[j]=48+3;
                else if(a[i]=='G'||a[i]=='H'||a[i]=='I')
                b[j]=48+4;
                else if(a[i]=='J'||a[i]=='K'||a[i]=='L')
                b[j]=48+5;
                else if(a[i]=='M'||a[i]=='N'||a[i]=='O')
                b[j]=48+6;
                else if(a[i]=='P'||a[i]=='R'||a[i]=='S')
                b[j]=48+7;
                else if(a[i]=='T'||a[i]=='U'||a[i]=='V')
                b[j]=48+8;
                else if(a[i]=='W'||a[i]=='X'||a[i]=='Y')
                b[j]=48+9;
                else
                j--;
            }
            b[j]='\0';
            string ss(b);
            m1[b]++;
        }
        for(it=m1.begin(),y=0;it!=m1.end();it++)
		{
		    if(it->second>1)
		    {
		        y=1;
		        for(unsigned m=0;m<it->first.size();m++){
                    if(m==3)printf("-");
                    cout<<it->first[m];
                    }
                    //cout<<(it->first/10000)<<"-"<<(it->first)%10000;
		        cout<<" "<<it->second<<endl;
		    }
		}
		if(y==0)
		cout<<"No duplicates."<<endl;
		m1.clear();
		//getchar();
	}
	return 0;
}

