#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[101],num[101];
bool dp[100001];
int used[1000101];
int main()
{
    int t,ca=1,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)   scanf("%d",&num[i]);
        memset(dp,0,sizeof(bool) * (m+1));
        dp[0]=true;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            memset(used,0,sizeof(int)*(m+1));
            for(int j=a[i];j<=m;j++)
            {
                if(!dp[j] && dp[j-a[i]] && used[j-a[i]]<num[i])
                {
                    ans++;
                    used[j]=used[j-a[i]]+1;
                    dp[j]=true;
                }
            }
        }
        printf("Case %d: %d\n",ca++,ans);
    }
    return 0;
}
