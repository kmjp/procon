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

#include "airline.h"
/*
void Alice( int N, int M, int A[], int B[] );
void InitG( int V, int U );
void MakeG( int pos, int C, int D );
void Bob( int V, int U, int C[], int D[] );
void InitMap( int N, int M );
void MakeMap( int A, int B );
*/


void Alice( int N, int M, int A[], int B[] ){
	int i,j;
	int V=N+12;
	vector<pair<int,int>> E;
	
	FOR(i,10) {
		E.push_back({0,2+i});
		E.push_back({1,2+i});
		if(i) E.push_back({2+i-1,2+i});
	}
	FOR(i,N) {
		E.push_back({0,12+i});
		FOR(j,10) if(i&(1<<j)) E.push_back({2+j,12+i});
	}
	FOR(i,M) E.push_back({A[i]+12,B[i]+12});
	
	InitG(V,E.size());
	FOR(i,E.size()) MakeG(i,E[i].first,E[i].second);
}

void Bob( int V, int U, int C[], int D[] ){
	set<int> E[2020];
	int i,j;
	FOR(i,U) {
		E[C[i]].insert(D[i]);
		E[D[i]].insert(C[i]);
	}
	int A,B;
	FOR(i,V) if(E[i].size()==V-2) A=i;
	FOR(i,V) if(i!=A && E[i].count(A)==0) B=i;
	int cand[1020]={};
	
	FOR(i,V) if(E[i].count(B)) cand[i]=1;
	vector<pair<int,int>> side;
	FOR(i,V) if(cand[i]) {
		int num=0;
		FORR(e,E[i]) if(cand[e]) num++;
		if(num==1) side.push_back({E[i].size(),i});
	}
	
	sort(ALL(side));
	vector<int> F;
	F.push_back(side[1].second);
	while(F.size()<10) {
		cand[F.back()]=0;
		int nex;
		FORR(e,E[F.back()]) if(cand[e]) nex=e;
		F.push_back(nex);
	}
	
	int cnt[1212]={};
	cnt[A]=-1<<30;
	cnt[B]=-1<<30;
	FORR(f,F) cnt[f]=-1<<30;
	FOR(i,F.size()) {
		FORR(f,E[F[i]]) cnt[f] += 1<<i;
	}
	int M=0;
	FOR(i,V) FORR(e,E[i]) if(i<e && cnt[i]>=0 && cnt[e]>=0) M++;
	InitMap(V-12,M);
	FOR(i,V) FORR(e,E[i]) if(i<e && cnt[i]>=0 && cnt[e]>=0) MakeMap(cnt[i],cnt[e]);
	
	
}


