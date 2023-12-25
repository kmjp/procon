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


ll C[26][26];

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
		int x,y,z,i;
		FOR(x,26) FOR(y,26) C[x][y]=(x==y)?0:1LL<<40;
		FOR(i,original.size()) {
			int a=original[i]-'a';
			int b=changed[i]-'a';
			C[a][b]=min(C[a][b],(ll)cost[i]);
		}
		FOR(z,26) FOR(x,26) FOR(y,26) C[x][y]=min(C[x][y],C[x][z]+C[z][y]);
		ll ret=0;
		FOR(i,source.size()) {
			int a=source[i]-'a';
			int b=target[i]-'a';
			if(C[a][b]>=1LL<<40) return -1;
			ret+=C[a][b];
		}
        return ret;
    }
};
