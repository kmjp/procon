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


vector<int> LIS(vector<int>& v) {
	int i,N=v.size();
	if(v.empty()) return {};
	vector<int> dp(N,1<<30),id(N);
	FOR(i,v.size()) {
		id[i] = lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin();
		// id[i] = lower_bound(dp.begin(),dp.end(),v[i]+1) - dp.begin(); //‚±‚¤‚·‚é‚Æ“¯‚¶’l‚à‹–—e‚·‚é
		dp[id[i]] = v[i];
	}
	int nl = *max_element(id.begin(),id.end());
	vector<int> ret(nl+1);
	FOR(i,N) if(id[N-1-i] == nl) ret[nl--] = v[N-1-i];
	return ret;
}

class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
		int i,N=nums.size();
		int ma=0;
		vector<pair<int,int>> V;
		FOR(i,N) if(nums[i]<=i) V.push_back({i-nums[i],nums[i]});
		sort(ALL(V));
		vector<int> W;
		FORR2(a,b,V) W.push_back(b);
		return LIS(W).size();
        
    }
};

