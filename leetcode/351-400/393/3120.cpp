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


ll from[10101];
ll to[10101];
int pre[20][10101];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,1<<29);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return 1<<29;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<20> st;


class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        
        int i,j;
        int N=nums.size();
        FOR(j,20) {
			FOR(i,N) {
				if(nums[i]&(1<<j)) {
					if(i==0) pre[j][i+1]=-1;
					else pre[j][i+1]=pre[j][i];
				}
				else {
					pre[j][i+1]=i+1;
				}
			}
		}
		
        FOR(i,N) from[i]=(1<<29);
        from[0]=0;
		FORR(a,andValues) {
			FOR(i,N+1) st.update(i,from[i]);
			from[0]=1<<29;
			for(i=1;i<=N;i++) {
				int L=0,R=i-1;
				FOR(j,20) {
					if(a&(1<<j)) {
						L=max(L,pre[j][i]);
					}
					else {
						R=min(R,pre[j][i]-1);
					}
				}
				if(L<=R) {
					from[i]=st.getval(L,R+1)+nums[i-1];
				}
				else {
					from[i]=(1<<29);
				}
			}
		}
        
        if(from[N]<1<<29) return from[N];
        return -1;
        
        
    }
};
