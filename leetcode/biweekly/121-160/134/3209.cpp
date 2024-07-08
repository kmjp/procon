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
    long long countSubarrays(vector<int>& nums, int k) {
		vector<pair<int,int>> V;
		ll ret=0;
		int i,j;
		int N=nums.size();
		FOR(i,N) {
			vector<pair<int,int>> W;
			FORR(v,V) {
				int a=v.first&nums[i];
				int b=v.second;
				if(W.size()&&W.back().first==a) continue;
				W.push_back({a,b});
			}
			if(W.empty()||W.back().first!=nums[i]) {
				W.push_back({nums[i],i});
			}
			V=W;
			FOR(j,V.size()) if(V[j].first==k) {
				if(j==V.size()-1) ret+=i+1-V[j].second;
				else ret+=V[j+1].second-V[j].second;
			}
			
		}
		return ret;
		
		
        
    }
};
