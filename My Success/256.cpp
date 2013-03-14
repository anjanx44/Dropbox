#include<iostream.h>
#include<fstream.h>
#include<math.h>
#include<string.h>




//NB.: input file name is in.txt
class qs
{

public:

private:
	long input(char str[])
	{
		long man=0,i=0;
		while(str[i]!=NULL)
		{
			man=man*10 + (str[i]-'0');
			i++;
		}
		return man;
	}

	bool check(unsigned long value,long len)
	{
		unsigned long dev,a,b,sole;
		dev=(long)pow(10,(len/2));
		a=(long)value/dev;
		b=value%dev;
		sole=(long)pow((a+b),2);
		if(sole==value)return true;
		else return false;
	}

	void output(unsigned long val,long len)
	{
		char *str;
		str=new char[len+1];
		for(long i=len-1;i>=0;i--)
		{
			str[i]=(char)(val%10)+'0';
			val=val/10;
		}
		str[len]=NULL;
		cout<<str<<endl;
		delete [] str;
	}

	bool quirks(long len)
	{
		unsigned long max;
		max=(long)pow(10,len);
		for(unsigned long i=0;i<max;i++)
		{
			if(check(i,len))output(i,len);
		}
		return true;
	}
public:
	void machine()
	{
		char n[7];
		while(!cin.eof())
		{
		cin>>n;
		quirks(input(n));
		//cout<<n;
		}
	}

};

int main()
{
	qs b;
	b.machine();
	return 0;
}