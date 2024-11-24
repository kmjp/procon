#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        ll E[26][26]={};
        int i,x,y;
        FOR(x,26) FOR(y,26) E[x][y]=(x==y)?0:1LL<<50;
        FOR(x,26) E[x][(x+1)%26]=nextCost[x];
        FOR(x,26) E[x][(x+25)%26]=previousCost[x];
        FOR(i,26) FOR(x,26) FOR(y,26) E[x][y]=min(E[x][y],E[x][i]+E[i][y]);
        ll ret=0;
        FOR(i,s.size()) ret+=E[s[i]-'a'][t[i]-'a'];
        return ret;
    }
};
