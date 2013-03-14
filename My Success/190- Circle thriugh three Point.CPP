/*
Shiakh Shiam Rahman 
UVa : 190 - Circle through three point
*/

#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

using namespace std; 

int main()
{
	double a,b,c,d,e,f,x,y,red;
	double A,B,M,C,D,N,CC;
	freopen("Input.txt","r",stdin);
	while(cin>>a>>b>>c>>d>>e>>f)
	{
		A=2*(c-a);
		B=2*(d-b);
		M=(c*c+d*d)-(a*a+b*b);
		C=2*(e-a);
		D=2*(f-b);
		N=(f*f+e*e)-(a*a+b*b);
		if((A*D-C*B)==0)
			x=0;
		else
			x=((M*D-B*N)/(A*D-C*B));
		if((A*D-C*B)==0)
			y=0;
		else
			y=((N*A-M*C)/(A*D-C*B));
		
		red=sqrt((a-x)*(a-x)+(b-y)*(b-y));
		//cout<<x<<" "<<y<<" "<<red<<endl;
		printf("(x ");
		if(x>=0)
			printf("- %.3lf)^2 + (y ",x);
		else
			printf("+ %.3lf)^2 + (y ",x*-1);
		
		if(y>=0)
			printf("- %.3lf)^2",y);
		else
			printf("+ %.3lf)^2",y*-1);
		if(red<0)
			red*=-1;
		printf(" = %.3lf^2",red);
		
		printf("\nx^2 + y^2 ");
		if(x>=0)
			printf("- %.3lfx ",2.0*x);
		else
			printf("+ %.3lfx ",2.0*x*-1);

		if(y>=0)
			printf("- %.3lfy ",2.0*y);
		else
			printf("+ %.3lfy ",2.0*y*-1);
		
		CC=(x*x+y*y)-red*red;
		if(CC>=0)
			printf("+ %.3lf = 0\n\n",CC);
		else
			printf("- %.3lf = 0\n\n",CC*-1);
	}
	
	return 0;
}