int cal[1000000];

void compute_prefix_function(string pattern) {
    int m = pattern.size();
    int k=0;
    cal[1] = k;
    FOR(i,2,m) {
        while( k>0 and pattern[k+1] != pattern[i])
            k = cal[k];
        if(pattern[k+1] == pattern[i])
            k++;
        cal[i] = k;
    }
}

void KMP(string str,string pattern) {
    compute_prefix_function(pattern);
    int n = str.size();
    int m = pattern.size();
    int q  = 0;
    repl(i,n) {
        while ( q>0 and pattern[q+1] != str[i])
            q = cal[q];
        if ( pattern[q+1] == str[i])
            q++;
        if(q == m-1) {
            pf("%d ",i-m+1);
            q = cal[q];
        }
    }
}

int main() {
    //READ("in.txt");
    int tc = 1,cas=1;
    //cin>>tc;
    while(tc--) {
        //pf("Case %d: ",cas++);
        memca(cal);
        /**** NOtice the Star at the begining ****/
        KMP("*abcabcabcabc","*abc");
    }
    return 0;
}
