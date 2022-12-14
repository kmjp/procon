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

vector<int> E[101010];

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int i;
        int N=vals.size();
        FOR(i,N) E[i].clear();
        FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		ll ma=-(1LL<<60);
		FOR(i,N) {
			vector<int> V;
			FORR(e,E[i]) if(vals[e]>0) V.push_back(vals[e]);
			sort(ALL(V));
			reverse(ALL(V));
			if(V.size()>k) V.resize(k);
			ll cur=vals[i];
			FORR(v,V) cur+=v;
			ma=max(ma,cur);
		}
		return ma;
    }
};
