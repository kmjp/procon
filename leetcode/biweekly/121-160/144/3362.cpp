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


int C[202020];
const int def=-1<<20;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
		FOR(i,NV) val[i+NV]=ma[i+NV]=def;
		for(i=NV-1;i>=1;i--) ma[i]=max(ma[2*i],ma[2*i+1]);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+max(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<int,1<<20> st;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
		int i;
		int N=nums.size();
		FOR(i,N+1) C[i]=0;
		FORR(q,queries) C[q[0]]++,C[q[1]+1]--;
		FOR(i,N) {
			if(i) {
				C[i]+=C[i-1];
			}
			if(nums[i]>C[i]) return -1;
			nums[i]-=C[i];
			st.update(i,i+1,-st.getval(i,i+1)+nums[i]);
		}
		int ret=0;
		sort(ALL(queries));
		reverse(ALL(queries));
		FORR(q,queries) {
			int x=st.getval(q[0],q[1]+1);
			if(x<0) {
				ret++;
				st.update(q[0],q[1]+1,1);
			}
			
		}
		
		return ret;
        
        
    }
};
