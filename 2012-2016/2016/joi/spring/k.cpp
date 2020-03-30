#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------
#include "snowy.h"
//#include "Borislib.h"
//#include "Anyalib.h"

static int getL;

int V;
vector<pair<int,int>> E[505];
int F[505],isL[505];
vector<int> L,S;
int P[505],PE[505];
int pos[505];
vector<int> VO;
int D[505];

void dfs(int cur,int pre) {
	VO.push_back(cur);
	FORR(e,E[cur]) {
		if(e.first==pre) {
			P[cur]=pre;
			PE[cur]=e.second;
		}
		else {
			dfs(e.first,cur);
			F[cur]=max(F[cur],F[e.first]+1);
		}
	}
	
	if(F[cur]==10) {
		isL[cur]=1;
		F[cur]=0;
		L.push_back(cur);
	}
	else {
		S.push_back(cur);
	}
}



void InitAnya(int N , int A[] , int B[]) {
	V=N;
	int i;
	VO.clear();
	FOR(i,N) E[i].clear();
	FOR(i,N-1) {
		E[A[i]].push_back({B[i],i});
		E[B[i]].push_back({A[i],i});
	}
	ZERO(isL);
	L.clear();
	S.clear();
	dfs(0,0);
	int cur=0;
	FORR(v,L) {
		pos[v]=cur;
		cur+=9;
	}
	FORR(v,S) pos[v]=cur++;
}

void Anya(int C[]) {
	FORR(v,VO) if(v) {
		D[v]=D[P[v]]+C[PE[v]];
		if(isL[v]) {
			int i;
			FOR(i,9) Save(pos[v]+i,(D[v]>>i)&1);
		}
		else {
			Save(pos[v],C[PE[v]]);
		}
	}
}

void InitBoris(int N , int A[] , int B[]) {
	InitAnya(N,A,B);
}

int Boris(int cur) {
	int dis=0;
	while(cur) {
		if(isL[cur]==0) {
			dis+=Ask(pos[cur]);
			cur=P[cur];
		}
		else {
			int i;
			FOR(i,9) dis+=Ask(pos[cur]+i)<<i;
			break;
		}
	}
	
	
  return dis;
}
