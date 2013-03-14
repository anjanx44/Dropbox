const i64 INFFF=1e16;
char S[1100];
int a[1000][1000];
int len(int l,int r)
{
    if(l>r) return 0;
    if(l==r) return 1;
    if(a[l][r]) return a[l][r];
    if(S[l]==S[r])
        a[l][r] = 2 + len(l+1,r-1);
    else
        a[l][r] = max(len(l+1,r),len(l,r-1));
    return a[l][r];
}

int main()
{
    READ("in.txt");
    int t;
    cin>>t;getchar();
    while(t--)
    {
        gets(S);
        printf("%d\n",len(0,strlen(S)-1));
        mem(a,0);
    }
    return 0;
}
