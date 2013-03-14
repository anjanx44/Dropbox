string S;
int a[1000][1000];
int len(int l,int r)
{
    if(l>=r) return 0;
    if(a[l][r]) return a[l][r];
    if(S[l]==S[r])
        a[l][r] = len(l+1,r-1);
    else
        a[l][r] = 1+ min(len(l+1,r-1),min(len(l+1,r),len(l,r-1)));
    return a[l][r];
}

int main()
{
    READ("in.txt");
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        cin>>S;
        printf("Case %d: %d\n",cas++,len(0,S.size()-1));
        mem(a,0);
    }
   return 0;
}
