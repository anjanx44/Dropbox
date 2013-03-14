
        rep(k,n)
            rep(i,n)
                rep(j,n)
                    d[i][j] = min( d[i][j], d[i][k] + d[k][j] );

repl(k,n) repl(i,n) repl(j,n) G[i][j] = G[i][j] | (G[i][k] & G[k][j]);