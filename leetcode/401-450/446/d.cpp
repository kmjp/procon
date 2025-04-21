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


int K;
template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		if(r.first==-1) return l;
		if(l.first==-1) return r;
		int i;
		FOR(i,K) l.second[l.first*i%K]+=r.second[i];
		l.first=l.first*r.first%K;
		return l;
	};
	
	SegTree_1(){val.resize(NV*2);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {-1,{0,0,0,0,0}};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, int v) {
		entry += NV;
		v%=K;
		val[entry].first=v;
		val[entry].second={0,0,0,0,0};
		val[entry].second[v]++;
		
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<pair<int,array<int,5>>,1<<20> st;


class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        K=k;
        int N=nums.size();
        int i;
        FOR(i,N) st.update(i,nums[i]);
        vector<int> ret;
        FORR(q,queries) {
			st.update(q[0],q[1]);
			auto p=st.getval(q[2],N);
			ret.push_back(p.second[q[3]]);
		}
		return ret;
    }
};


