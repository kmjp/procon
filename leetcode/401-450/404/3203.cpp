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

pair<int,int> farthest(int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(e,cur,d+1,D));
	return r;
}

pair<int,vector<int>> diameter() { // diameter,center
	if(N==1) {
		return {0,{0}};
	}
	if(N==2) {
		return {1,{0}};
	}
	vector<int> D[2];
	D[0].resize(N);
	D[1].resize(N);
	auto v1=farthest(0,0,0,D[0]);
	auto v2=farthest(v1.second,v1.second,0,D[0]);
	v1=farthest(v2.second,v2.second,0,D[1]);
	pair<int,vector<int>> R;
	R.first = v2.first;
	//dS‚ðŽæ‚éê‡
	for(int i=N-1;i>=0;i--) if(D[0][i]+D[1][i]==R.first && abs(D[0][i]-D[1][i])<=1) R.second.push_back(i);

	return R;
}

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
		int A=edges1.size()+1;
		int B=edges2.size()+1;
		
		N=A;
		E.clear();
		E.resize(A);
		FORR(e,edges1) E[e[0]].push_back(e[1]),E[e[1]].push_back(e[0]);
		auto AA=diameter();
		N=B;
		E.clear();
		E.resize(B);
		FORR(e,edges2) E[e[0]].push_back(e[1]),E[e[1]].push_back(e[0]);
		auto BB=diameter();
		N=A+B;
		E.clear();
		E.resize(N);
		FORR(e,edges1) E[e[0]].push_back(e[1]),E[e[1]].push_back(e[0]);
		FORR(e,edges2) E[e[0]+A].push_back(e[1]+A),E[e[1]+A].push_back(e[0]+A);
		E[AA.second[0]].push_back(BB.second[0]+A);
		E[BB.second[0]+A].push_back(AA.second[0]);
		
        return diameter().first;
    }
};

