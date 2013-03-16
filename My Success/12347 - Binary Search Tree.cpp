/*
Shiakh Shiam Rahman 
UVa : 12347 - Binary Search Tree
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000


using namespace std;

#define READ(filename) freopen(filename, "r", stdin);
#define WRITE(filename) freopen(filename, "w", stdout);
# define ull unsigned long long
# define ll long long
# define u unsigned

void SET(int,int);
void search_left(int);
void search_right(int);

class Node
{
public:
    int left,right,mom;
}node[100000];

int root,value,num,data;


void search_left(int val)
{
    if(node[val].left==-1)
        SET(1,val);
    else
    {
        val=node[val].left;
        if(val>num)
            search_left(val);
        else
            search_right(val);
    }
}

void search_right(int val)
{
    if(node[val].right==-1)
        SET(-1,val);
    else
    {
        val=node[val].right;
        if(val<num)
            search_right(val);
        else
            search_left(val);
    }
}

void SET(int i,int val)
{
    if(i==1)
    {
        node[val].left=num;
        node[num].left=-1;
        node[num].right=-1;
        node[num].mom=val;
    }
    else
    {
        node[val].right=num;
        node[num].left=-1;
        node[num].right=-1;
        node[num].mom=val;
    }

}

void dfs(int src)
{
    if(node[src].left!=-1) {dfs(node[src].left);}
    if(node[src].right!=-1) { dfs(node[src].right);}
    cout<<src<<"\n";
}

int main()
{
    READ("in.txt");

    //queue < int > q;

    scanf("%d",&root);

    //q.push(root);

    value=root;
    node[root].left=-1;
    node[root].right=-1;
    while(scanf("%d",&num)==1)
    {
        //q.push(num);

        if(num<root)
            search_left(root);
        else
            search_right(root);

        //printf("%d : %d\n",num,node[num].mom);
    }

    /*
    printf("fUll tree:\n");
    while(!q.empty())
    {printf("%d : l>%d r>%d\n",q.front(),node[q.front()].left,node[q.front()].right);q.pop();}
    */

    dfs(root);
    return 0;
}
