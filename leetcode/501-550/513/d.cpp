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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
		vector<ll> V;
		ll cur=0;
		V.push_back(cur);
		FORR(v,nums) {
			if(v%2==0) cur+=b;
			else cur-=a;
			V.push_back(cur);
		}
		vector<ll> Vs;
		FORR(v,V) Vs.push_back(v);
		sort(ALL(Vs));
		Vs.erase(unique(ALL(Vs)),Vs.end());
		
		ll ret=0;
		FORR(v,V) {
			int x=lower_bound(ALL(Vs),v)-Vs.begin();
			ret+=bt(1<<19)-bt(x-1);
			bt.add(x,1);
		}
		FORR(v,V) {
			int x=lower_bound(ALL(Vs),v)-Vs.begin();
			bt.add(x,-1);
		}
		
		return ret;
        
    }
};

