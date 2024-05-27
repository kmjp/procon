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
	
	SegTree_1(){val=vector<V>(NV*2,0);};
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
SegTree_1<int,1<<18> st;

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
		set<int> S={0,(1<<17)-1};
		st.update(0,(1<<17)-1);
		vector<bool> ret;
		FORR(q,queries) {
			int x=q[1];
			int y=*prev(S.lower_bound(x+1));
			int v=st.getval(y,y+1);
			if(q[0]==1) {
				st.update(y,x-y);
				st.update(x,v-(x-y));
				S.insert(x);
			}
			else {
				if(x-y>=q[2]) {
					ret.push_back(1);
				}
				else if(st.getval(0,y)>=q[2]) {
					ret.push_back(1);
				}
				else {
					ret.push_back(0);
				}
			}
		}
		
		FORR(q,queries) {
			st.update(q[1],0);
		}
		return ret;
        
    }
};

