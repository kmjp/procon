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

int const def=0;
template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	V comp(V l,V r){ return __gcd(l,r);};
	
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
SegTree_ma<int,1<<16> st;

class Solution {
public:
    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {
		int N=nums.size();
		int i;
		int num=0;
		FOR(i,N) {
			if(nums[i]%p==0) st.update(i,nums[i]/p), num++;
			else st.update(i,0);
		}
		int ret=0;
		FORR(q,queries) {
			if(nums[q[0]]%p==0) num--;
			nums[q[0]]=q[1];
			if(nums[q[0]]%p==0) {
				num++;
				st.update(q[0],q[1]/p);
			}
			else {
				st.update(q[0],0);
			}
			if(st.val[1]==1) {
				if(num>0) {
					if(num<N) {
						ret++;
					}
					else {
						FOR(i,N) {
							int x=st.getval(0,i);
							int y=st.getval(i+1,N);
							if(__gcd(x,y)==1) {
								ret++;
								break;
							}
						}
					}
				}
			}
		}
        FOR(i,N) st.update(i,0);
        return ret;
    }
};


