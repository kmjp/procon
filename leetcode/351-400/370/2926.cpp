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

static ll const def=-(1LL<<60);
template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
	void update2(int entry, V v) {
		entry += NV;
		val[entry]=v; //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<ll,1<<20> st;

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
		vector<ll> Vs;
		int i;
		FOR(i,nums.size()) {
			Vs.push_back(nums[i]-i);
		}
		FOR(i,nums.size()+2) {
			st.update2(i,-(1LL<<60));
		}
		sort(ALL(Vs));
		Vs.erase(unique(ALL(Vs)),Vs.end());
		ll ma=-1LL<<60;
		FOR(i,nums.size()) {
			int x=lower_bound(ALL(Vs),nums[i]-i)-Vs.begin();
			ll a=max(0LL,st.getval(0,x+1))+nums[i];
			ma=max(ma,a);
			st.update(x,a);
		}
		return ma;
        
    }
};
