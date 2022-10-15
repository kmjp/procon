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

vector<int> V;
vector<int> E[202020];

class Solution {
public:
	ll dfs(int cur,int pre,ll v) {
		ll sum=V[cur];
		FORR(e,E[cur]) if(e!=pre) {
			sum+=dfs(e,cur,v);
		}
		if(sum==v) sum=0;
		return sum;
	}

    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
		V=nums;
		int i;
		ll sum=0;
		FOR(i,V.size()) {
			E[i].clear();
			sum+=nums[i];
		}
		FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
        for(i=sum;i>=1;i--) if(sum%i==0) {
			if(dfs(0,0,sum/i)==0) {
				cout<<sum/i-1<<endl;
				return i-1;
			}
		}
        return 0;
        
    }
};