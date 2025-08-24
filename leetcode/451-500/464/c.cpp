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

template<class V,int NV> class SegTree_Pair_ma {
public:
	vector<pair<V,int> > val;
	static V const def=-1;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return max(l,r);}
	SegTree_Pair_ma(){
		val.resize(NV*2);
		int i;
		FOR(i,NV) val[i+NV]=make_pair(def,i);
		for(i=NV-1;i>=1;i--) val[i]=comp(val[2*i],val[2*i+1]);
	};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,NV);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=make_pair(v,entry-NV);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
template<class V,int NV> class SegTree_Pair_mi {
public:
	vector<pair<V,int> > val;
	static V const def=1<<30;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return min(l,r);}
	SegTree_Pair_mi(){
		val.resize(NV*2);
		int i;
		FOR(i,NV) val[i+NV]=make_pair(def,i);
		for(i=NV-1;i>=1;i--) val[i]=comp(val[2*i],val[2*i+1]);
	};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,NV);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=make_pair(v,entry-NV);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_Pair_ma<int,1<<20> stma;
SegTree_Pair_mi<int,1<<20> stmi;



class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int i,N=nums.size();
        vector<int> ret(N);
        FOR(i,N) {
			stma.update(i,nums[i]);
			stmi.update(i,nums[i]);
		}
		while(1) {
			auto p=stma.getval(0,N);
			if(p.first==-1) break;
			int v=p.first;
			int cur=p.second;
			stma.update(cur,-1);
			stmi.update(cur,1<<30);
			queue<int> Q;
			Q.push(cur);
			while(Q.size()) {
				int cur=Q.front();
				Q.pop();
				ret[cur]=v;
				while(1) {
					auto p=stma.getval(0,cur);
					if(p.first<=nums[cur]) break;
					int ne=p.second;
					stma.update(ne,-1);
					stmi.update(ne,1<<30);
					Q.push(ne);
				}
				while(1) {
					auto p=stmi.getval(cur+1,N);
					if(p.first>=nums[cur]) break;
					int ne=p.second;
					stma.update(ne,-1);
					stmi.update(ne,1<<30);
					Q.push(ne);
				}
			}
			
		}
        return ret;
    }
};


