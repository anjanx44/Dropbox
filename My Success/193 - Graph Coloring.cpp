#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<set>
#include<map>
#include<sstream>
#include<stack>
#include<queue>
#include<cmath>
#include<string.h>
#include<utility>
#include <bitset>
#include <limits>
using namespace std;

#define ff first
#define ss second
#define MP make_pair
#define Pq priority_queue
#define rep(i,  e) for( int i=0; i<(int)e; i++)
#define repr(i, s) for( int i=(int)(s-1); i>=0; i--)
#define Fr(i,s,e) for( int i=(int)s; i<=(int)e; i++)
#define fr(i,s,e) for( int i=(int)s; i>=(int)e; i--)
#define Frall(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define frall(i,c) for(__typeof((c).rbegin()) i=(c).rbegin();i!=(c).rend();++i)
#define pb push_back
#define sqr( n) ( (n)*(n))
#define all(a) (a).begin(), (a).end()
#define srt(a) sort(all(a))
#define ln(a) a.length()
#define N_digit(n) floor(log10(n) +1)
#define rev(a) reverse(a.begin(),a.end() )
#define sz size()
#define NP(a) next_permutation(a.begin(), a.end() )
#define reset(a, value) memset(a,value, sizeof(a))
#define Unq(a) unique(a.begin(), a.end() )
#define pi (2*acos(0.0))
#define last(a) ( a[a.sz-1 ] )
#define ESP 0.00000001
#define MAX 20000
#define INF 999999999
//#define gcd(a,b)   __gcd(a,b)

#define all_bits ((1 << 31) - 1)
#define neg_bits(mask) (mask ^= all_bits)
#define test_bit(mask, i) (mask & (1 << i))
#define on_bit(mask, i) (mask |= (1 << i))
#define off_bit(mask, i) (mask &= neg_bits(1 << i))
#define dist(x1, y1, x2, y2) ( sqr((int)x1 - (int)x2 ) + sqr( (int)y1 - (int)y2)  )

#define UNVISITED 0
#define WHITE 1
#define BLACK 2
#define MAX_NODE 101
#define NCR_range 100

typedef int I;
typedef long long LL;
typedef unsigned long long ULL;
typedef double Db;
typedef string Sr;
typedef stringstream SS;

typedef vector<I> VI;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector< VLL > VVLL;
typedef vector<Db> VD;
typedef vector<VD> VVD;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<Sr> VS;
typedef vector<VS> VVS;
typedef vector<bool> VB;
typedef vector<VB> VVB;

typedef pair< I, I> PII;
typedef vector<PII> VPII;
typedef pair<I, Sr> PIS;
typedef vector<PIS> VPIS;
typedef pair<Sr,Sr> PSS;
typedef vector<PSS> VPSS;


int dx[] = { 0, -1, 1,  0  };                  // traverse for up, left, right, down
int dy[] = { 1,  0, 0, -1  };

int du[] = {-1, 0, 1, -1, 1, -1,  0,  1};                  // traverse for up, left, right, down, diagonally
int dv[] = { 1, 1, 1,  0, 0, -1, -1, -1};
LL ncr[NCR_range+1][NCR_range+1];



template < class T >                                  /// for cheak pallindrome
bool palindrome(T s1) {
    int s=0,e=s1.sz-1;
    while(s<e) {
        if(s1[s]!=s1[e]) return false;
        s++;
        e--;
    }
    return true;
}
bool palindrome(LL n ) {
    LL m=n, i=0;
    while(m!=0) {
        i=i*10 + (m%10);
        m/=10;
    }
    if(i==n) return true;
    return false;
}
bool palindrome(int n) {
    return palindrome( LL(n) );
}

template <class T>
void show(T v) {
    if(v.size())cout<<v[0];
    Fr(i, 1, v.size()-1 ) cout<<" "<<v[i];
    cout<<"\n";
}
void show( int v[], int n) {
    if(n) cout<<v[0];
    Fr(i, 1, n-1) cout<<" "<<v[i];
    cout<<"\n";
}

//template <class T> void print(  T v ) { li i=0; for(i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<"\n"; }    /// for print type;
template <class T> long long GCD (T a, T b) {
    return ( b==0? a:GCD(b, a%b)) ;
}
template <class T> LL LCM (T a, T b) {
    return (a* (b/GCD(a,b)) ) ;
}
template <class T> T Big_mod(T b,T p,T m) {
    if(p==0)return 1;    /// compute (b^p)%m
    else if(p%2==0)return sqr(Big_mod(b,p/2,m))%m;
    else return((b%m)*Big_mod(b,p-1,m))%m;
}

void Cal_NCR() {
    ncr[0][0] = 1;
    Fr(i,1,NCR_range) {
        ncr[i][0] = 1;
        Fr(j,1,NCR_range) ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
    }
}

LL toInt(string s) {
    stringstream in(s, ios_base::in);
    LL result;
    in >> result;
    return result;
}

bool ingrid( I x, I y, I nx, I ny ) {
    if( x>=0&&x<=nx&&y>=0&&y<=ny)return true;
    return false;
}
int node, edges;
VVI G;
struct Scolor {
    int nblack, nwhite;
    int status[MAX_NODE];
} best;

void  Back_Track(Scolor temp, int now ) {
    if( temp.nblack + temp.nwhite == node ) {
        if( temp.nblack > best.nblack  )
            best = temp;
        return;
    }
    int v;
    bool isblackfound;
    Fr(i, now, node) {
        if( temp.status[i] ==0 && G[i].sz > 0 ) {
            Scolor hlp = temp;
            hlp.nblack++;
            hlp.status[i] = BLACK;                       // try to make it black...
            isblackfound = false;
            rep(j, G[i].sz) {
                v = G[i][j];
                if( hlp.status[v]== BLACK ) {            // If its adjacent is black
                    isblackfound = true;
                    break;
                } else if( hlp.status[v] == UNVISITED ) {
                    hlp.nwhite++;
                    hlp.status[v] = WHITE;
                }
            }
            if( !isblackfound && ( node - hlp.nwhite) > best.nblack )
                Back_Track( hlp, now+1 );
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
    int tc, u, v;
    scanf("%d", &tc);
    rep(t, tc) {
        scanf("%d%d", &node, &edges);
        G = VVI(node+1);
        rep(i, edges) {
            scanf("%d%d", &u,&v);
            G[u].pb(v);
            G[v].pb(u);
        }
        memset(&best, UNVISITED, sizeof(best));
        Fr(i, 1, node) {
            if( !G[i].sz ) {
                best.status[i] = BLACK;
                best.nblack++;
            }
        }
        Back_Track(best, 1 );
        bool flag=true;
        printf("%d\n", best.nblack);
        Fr(i, 1, node) {
            if( best.status[i] == BLACK ) {
                if( flag ) {
                    printf("%d", i);
                    flag = false;
                } else {
                    printf(" %d", i);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
