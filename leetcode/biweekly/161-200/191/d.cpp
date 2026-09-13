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

ll S[101010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;


class Solution {
public:
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
		int N,i;
		N=nums.size();
		vector<ll> Ss;
		Ss.push_back(0);
		Ss.push_back(-goal+k);
		Ss.push_back(-goal-k);
		Ss.push_back(0);
		Ss.push_back(1LL<<60);
		Ss.push_back(-(1LL<<60));
		FOR(i,N) {
			S[i+1]=S[i]+nums[i];
			Ss.push_back(S[i+1]);
			Ss.push_back(-goal+S[i+1]+k);
			Ss.push_back(-goal+S[i+1]-k);
		}
		sort(ALL(Ss));
		Ss.erase(unique(ALL(Ss)),Ss.end());
		ll ret=1LL*N*(N+1)/2;
		
		FOR(i,N+1) {
			int x=lower_bound(ALL(Ss),-goal+S[i]+k)-Ss.begin();
			int y=lower_bound(ALL(Ss),-goal+S[i]-k)-Ss.begin();
			if(k) {
				ret-=bt(x-1)-bt(y);
			}
			int z=lower_bound(ALL(Ss),S[i])-Ss.begin();
			bt.add(z,1);
		}
		
		FOR(i,Ss.size()) bt.add(i,-bt(i));
		return ret;
        
    }
};


