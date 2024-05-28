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


template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		V ret={-(1LL<<60),-(1LL<<60),-(1LL<<60),-(1LL<<60)};
		int a,b,c,d;
		FOR(a,2) FOR(b,2) FOR(c,2) FOR(d,2) {
			if(b&&c) continue;
			ret[a+d*2]=max(ret[a+d*2],l[a+b*2]+r[c+d*2]);
		}
		return ret;
		
	};
	
	SegTree_1(){
		val=vector<V>(NV*2);
		FORR(v,val) v={0,-(1LL<<40),-(1LL<<40),0};
	};
	void update(int entry, int v) {
		entry += NV;
		val[entry]={0,-(1LL<<40),-(1LL<<40),v};
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<array<ll,4>,1<<18> st;

class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int i;
        FOR(i,nums.size()) st.update(i,nums[i]);
        
        ll ret=0;
        FORR(q,queries) {
			st.update(q[0],q[1]);
			ll ma=max({st.val[1][0],st.val[1][1],st.val[1][2],st.val[1][3]});
			ret+=ma;
		}
        FOR(i,nums.size()) st.update(i,0);
		ll mo=1000000007;
		ret=ret%mo+mo;
		return ret%mo;
        
    }
};
