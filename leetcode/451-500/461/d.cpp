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

template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	static V const def=-1LL<<50;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_ma(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_ma<ll,1<<20> st;
int nexU[101010];
int nexD[101010];


class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int N=nums.size();
        int i;
        FOR(i,N) {
			S[i+1]=S[i]+nums[i];
			st.update(i+1,S[i+1]);
		}
		nexU[N-1]=nexD[N-1]=N-1;
		for(i=N-2;i>=0;i--) {
			nexU[i]=nexD[i]=i;
			if(nums[i]<nums[i+1]) nexU[i]=nexU[i+1];
			if(nums[i]>nums[i+1]) nexD[i]=nexD[i+1];
		}
		ll ret=-1LL<<60;
		FOR(i,N) {
			int x=nexU[i];
			if(x<=i) continue;
			int y=nexD[x];
			if(y<=x) continue;
			int z=nexU[y];
			if(z<=y) continue;
			ll sum=st.getval(y+2,z+2)-S[i];
			ret=max(sum,ret);
		}
		return ret;
		
    }
};
