Basically Speaking
/*
Shiakh Shiam Rahman 
UVa : 389 - Basically Speaking
*/

@begin_of_source_code
#include<iostream.h>
#include<math.h>
#include<string.h>
#include<iomanip.h>

char num[16];

int main()
{
/*@JUDGE_ID: 12819  389  C++ "Dynamic programming" */
		long i,j;
		char k;
		for(i=0;i<10;i++)num[i]=i+48;
		for(i=10,k='A';i<16;i++,k++)num[i]=k;
		char n[10000];
		int b1,b2;
		int x;
		while(cin>>n>>b1>>b2)
		 {
		  char res[10000];
		  char fres[10000];
		  unsigned long deci=0;
		  long len=strlen(n);
		  for(int l=len-1,p=0;l>=0;l--,p++)
		  {
		  int n1=0;
		  for(int m=0;m<b1;m++)
		   {
		   if(n[l]==num[m])n1=m;
		   }
		  deci+=n1*pow(b1,p);
		  }
		  if(b2!=10)
		   {
		   i=0;
		   int flag=0;
		   do
			{
			 res[i++]=num[deci%b2];
			 deci=deci/b2;
			 if(i>7){flag=1;break;}
			 }while(deci>0);

		   if(flag==0)
			{
			for(j=i-1,k=0;j>=0;j--,k++)fres[k]=res[j];
			fres[k]='\0';
			cout<<setw(7)<<fres<<"\n";
			}
		   else
			cout<<setw(8)<<"ERROR\n";
		   }
		  else
		  {
		  if(deci<=9999999)
		  cout<<setw(7)<<deci<<"\n";
		  else
		  cout<<setw(8)<<"ERROR\n";
		  }
		 }
		 return 0;
}
@end_of_source_code