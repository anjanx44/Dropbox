//@begin_of_source_code
#include<iostream.h>
int main()
{
/*@JUDGE_ID: 12819  350  C++ "Dynamic programming" */
      
      long z,i,l,m;
      long cas=1;
      while(cin>>z>>i>>m>>l&&(z>0&&i>0&&l>0&&m>0))
       {
        int ran[10000]={0};
        long cycle=0;
	int flag=0;
	for(;flag!=1;)
	  {
	  long nr=(z*l+i)%m;
	  l=nr;
	  if(ran[l]==0)
	   {
	    ran[l]=1;
	    cycle++;
	    }
	  else flag=1;
	  }
        cout<<"Case "<<cas<<": "<<cycle<<"\n";
	cas++;
	}
      return 0;
}
//@end_of_source_code