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


vector<int> P[30];


class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
		int i,j,N=nums.size();
		FOR(i,30) P[i].clear();
		vector<pair<int,int>> V;
		FOR(i,N) {
			FOR(j,30) if(nums[i]&(1<<j)) P[j].push_back(i);
			V.push_back({nums[i],i});
		}
		set<int> did={-1,N};
		sort(ALL(V));
		reverse(ALL(V));
		ll ret=0;
		FORR2(v,i,V) {
			did.insert(i);
			auto it=did.find(i);
			int L=*prev(it);
			int R=*next(it);
			FOR(j,30) if((v&(1<<j))==0) {
				int x=lower_bound(ALL(P[j]),i)-P[j].begin();
				if(x<P[j].size()) R=min(R,P[j][x]);
				if(x) L=max(L,P[j][x-1]);
			}
			ret+=1LL*(R-i)*(i-L);
			
		}
		return ret;
			
        
    }
};


