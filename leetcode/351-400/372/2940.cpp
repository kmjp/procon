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

int def=0;
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
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<int,1<<20> st;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int i;
        int N=heights.size();
        FOR(i,N) st.update(i,heights[i]);
        vector<int> ret;
        FORR(q,queries) {
			if(q[0]>q[1]) swap(q[0],q[1]);
			
			if(heights[q[1]]>heights[q[0]]||q[0]==q[1]) {
				ret.push_back(q[1]);
				continue;
			}
			
			int x=q[1]+1;
			int h=heights[q[0]]+1;
			int L=N;
			if(st.getval(x,L)<h) {
				ret.push_back(-1);
			}
			else {
				for(i=18;i>=0;i--) if(st.getval(x,L-(1<<i))>=h) L-=1<<i;
				ret.push_back(L-1);
			}
			
		}
        
        
        FOR(i,N) st.update(i,0);
        return ret;
    }
};
