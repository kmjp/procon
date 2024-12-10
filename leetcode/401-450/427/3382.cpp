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
	static V const def=1<<30;
	V comp(V l,V r){ return min(l,r);};
	
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
    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
		map<int,vector<int>> XminY;
		map<int,int> YminX;
		set<pair<int,int>> S;
		vector<pair<int,int>> cand;
		vector<int> Xs=xCoord;
		int N=xCoord.size();
		sort(ALL(Xs));
		Xs.erase(unique(ALL(Xs)),Xs.end());
		int i;
		
		FOR(i,N) {
			st.update(i,1<<30);
			cand.push_back({yCoord[i],xCoord[i]});
		}
		sort(ALL(cand));
		reverse(ALL(cand));
		ll ret=-1;
		FORR(c,cand) {
			int y=c.first;
			int x=lower_bound(ALL(Xs),c.second)-Xs.begin();
			int ty=-1,tx=-1;
			if(XminY.count(x)) ty=XminY[x].back();
			if(YminX.count(y)) tx=YminX[y];
			if(S.count({tx,ty})&&XminY[tx][XminY[tx].size()-2]==ty) {
				if(st.getval(x+1,tx)>ty) {
					ret=max(ret,1LL*(ty-y)*(Xs[tx]-Xs[x]));
				}
			}
			S.insert({x,y});
			XminY[x].push_back(y);
			YminX[y]=x;
			st.update(x,y);
		}
		return ret;
		
        
    }
};


