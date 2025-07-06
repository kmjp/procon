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
	static V const def=0;
	V comp(V l,V r){ return __gcd(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
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
SegTree_1<int,1<<18> st;


class Solution {
public:
    int minStable(vector<int>& nums, int maxC) {
		
		int i;
		FOR(i,nums.size()) st.update(i,nums[i]);
		int N=nums.size();
		
		int num=0;
		FORR(a,nums) if(a>1) num++;
		if(num<=maxC) return 0;
		
        int ret=(1<<20);
        for(int i=19;i>=0;i--) {
			int tmp=ret-(1<<i);
			int cur=0;
			int num=0;
			int step=0;
			for(int L=0,R=0;R<N;R++) {
				while(L<R&&st.getval(L,R+1)==1) L++;
				
				if(R-L+1<=tmp) continue;
				step++;
				L=R+1;
				
			}
			if(step<=maxC) ret=tmp;
		}
		return ret;
        
    }
};
