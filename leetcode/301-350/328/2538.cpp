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

int N;
vector<vector<int>> E;
vector<int> P;
vector<ll> D[2];

pair<ll,int> farthest(int cur,int pre,ll d,vector<ll>& D) {
	D[cur]=d+P[cur];
	pair<ll,int> r={D[cur],cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(e,cur,D[cur],D));
	return r;
}

pair<int,vector<int>> diameter() { // diameter,center
	D[0].resize(N);
	D[1].resize(N);
	auto v1=farthest(0,0,0,D[0]);
	auto v2=farthest(v1.second,v1.second,0,D[0]);
	v1=farthest(v2.second,v2.second,0,D[1]);
	pair<ll,vector<int>> R;
	R.first = v2.first;
	//—¼’[‚¾‚¯
	R.second={v1.second,v2.second};

	return R;
}


class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
		N=n;
		E.resize(n);
		int i;
		FOR(i,n) E[i].clear();
		FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		P=price;
		auto r=diameter();
		ll ma=0;
		FOR(i,N) {
			ma=max(ma,D[0][i]-P[i]);
			ma=max(ma,D[1][i]-P[i]);
		}
		return ma;
			
		
        
    }
};
