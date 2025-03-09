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
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
		set<pair<int,int>> R;
		map<int,set<int>> L;
		int i;
		int num=conflictingPairs.size();
		FOR(i,num) {
			auto& e=conflictingPairs[i];
			e[0]--,e[1]--;
			if(e[0]>e[1]) swap(e[0],e[1]);
			R.insert({e[1],i});
			L[e[0]].insert(i);
		}
		R.insert({n,num});
		R.insert({n,num+1});
		vector<ll> gain(num+1);
		ll ret=0;
		FOR(i,n) {
			auto p=*R.begin();
			auto q=*next(R.begin());
			ret+=p.first-i;
			gain[p.second]+=q.first-p.first;
			FORR(a,L[i]) R.erase({conflictingPairs[a][1],a});
		}
		ll ma=0;
		FOR(i,num) ma=max(ma,gain[i]);
		return ret+ma;
        
    }
};


