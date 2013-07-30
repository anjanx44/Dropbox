#include<cstdio>
#include<iostream>

using namespace std;

class node
{
public:
	int info;
	node *link;
};

node* search(node *start,int item)
{
	node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->info==item)
			return ptr;
		ptr=ptr->link;
	}
	cout<<"sorry";
	return ptr;
}
node* insertmid(node *start,node *loc,int item)
{
	node *N;
	N=new node;
	N->info=item;
	N->link=loc->link;
	loc->link=N;
	return start;
}
void traverse( node *start)
{
	node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		cout<<ptr->info<<" ";
		ptr=ptr->link;
	}
	cout<<endl;
}

node* insert(node *start,int item)
{
	node *N;
	N=new node;
	N->info=item;
	N->link=start;
	start=N;
	return start;
}
int main()
{
	node *start,*LOC;
	start=NULL;
	int item;
	while(1)
	{
		cin>>item;
		
		if(item==0)
			break;
		else
		{
			start=insert(start,item);
			traverse(start);
		}
	}
	cout<<"Enter the search item:";
	int s,n;
	cin>>s;
	LOC=search(start,s);
	cout<<"Enter the new item:";
	cin>>n;
	start=insertmid(start,LOC,n);
	traverse(start);
	return 0;
}
