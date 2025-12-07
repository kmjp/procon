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

int isp[1<<13];
int dfs[1<<13];
class Solution {
public:
    vector<int> minOperations(vector<int>& nums) {
        
        int i;
        FOR(i,1<<13) {
			int x=i,v=0;
			while(x) {
				v=v*2+x%2;
				x/=2;
			}
			isp[i]=v==i;
			dfs[i]=1<<20;
			if(isp[i]) dfs[i]=0;
		}
		FOR(i,(1<<13)-1) dfs[i+1]=min(dfs[i+1],dfs[i]+1);
		for(i=(1<<13)-2;i>=0;i--) dfs[i]=min(dfs[i],dfs[i+1]+1);
		vector<int> ret;
		FORR(a,nums) ret.push_back(dfs[a]);
		return ret;
        
    }
};
