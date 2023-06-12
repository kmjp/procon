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
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,-1);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return -1;
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
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
		vector<pair<int,int>> Ys;
		vector<pair<int,int>> ev;
		int N=nums1.size(),Q=queries.size();
		int i;
		FOR(i,N) {
			Ys.push_back({nums2[i],i});
			st.update(i,-1);
		}
		vector<int> P(N),R(Q);
		sort(ALL(Ys));
		FOR(i,N) {
			P[Ys[i].second]=i;
			ev.push_back({-nums1[i],i});
		}
		FOR(i,Q) ev.push_back({-queries[i][0],N+i});
		sort(ALL(ev));
		FORR(e,ev) {
			if(e.second<N) {
				st.update(P[e.second],nums1[e.second]+nums2[e.second]);
			}
			else {
				int y=lower_bound(ALL(Ys),make_pair(queries[e.second-N][1],0))-Ys.begin();
				R[e.second-N]=st.getval(y,N);
				
			}
		}
		return R;
        
    }
};


