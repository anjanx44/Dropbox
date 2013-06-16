//copied
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <list>
#include <cmath>

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;


int main(){
    string s;
    int n;
    cin >> n;
    getline(cin,s);

    while(n--){
        getline(cin,s);
        int idx = 0;
        int freqx = 0;
        int freqy = 0;
        int freqz = 0;
        bool isT = true;

        // at least 1 ? before M
        while(idx < s.length() && s[idx] == '?'){
            freqx++;
            idx++;
        }
        if(freqx == 0 || idx == s.length() || s[idx] != 'M'){
            isT = false;
            goto end_for_output;
        }
        idx++;

        // at least 1 ? before E
        while(idx < s.length() && s[idx] == '?'){
            freqy++;
            idx++;
        }
        if(freqy == 0 || idx == s.length() || s[idx] != 'E'){
            isT = false;
            goto end_for_output;
        }
        idx++;

        // at least 2 ? before end
        while(idx < s.length() && s[idx] == '?'){
            freqz++;
            idx++;
        }
        if(freqz != freqx + freqy || idx != s.length()){
            isT = false;
            goto end_for_output;
        }

        end_for_output:
        printf("%stheorem\n",isT?"":"no-");
    }

    return 0;
}
