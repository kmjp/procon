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

template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_ma(){val=vector<V>(NV*2,0);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_ma<ll,1<<18> st_up,st_down;

ll dp_up[101010],dp_down[101010];

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        
        int i,N=nums.size();
        ll ma=0;
        FOR(i,N) {
			int v=nums[i];
			if(i>=k) {
				int w=nums[i-k];
				st_up.update(w,max(st_up.getval(w,w+1),dp_up[i-k]));
				st_down.update(w,max(st_down.getval(w,w+1),dp_down[i-k]));
			}
			dp_up[i]=st_down.getval(v+1,1<<17)+v;
			dp_down[i]=st_up.getval(0,v)+v;
			ma=max(ma,dp_up[i]);
			ma=max(ma,dp_down[i]);
			
		}
        
        FORR(a,nums) {
			st_up.update(a,0);
			st_down.update(a,0);
		}
        return ma;
    }
};

