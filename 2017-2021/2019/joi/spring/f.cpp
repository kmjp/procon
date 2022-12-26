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

//#include "Azer.h"
//#include "Baijan.h"
#include "transportations.h"

int N;
vector<pair<int,int>> E[2][2020];
int D[2][2020];
int LD[2];
int fix[2][2020];

pair<int,int> B[2];
int L[2],M[2],LS[2];
int V[2];

priority_queue<pair<int,int>> Q[2];

void SA(int v,int len) {
	L[0]=V[0]=M[0]=0;
	LS[0]=v;
	int i;
	FOR(i,len) SendA((v>>i)&1);
	
}
void SB(int v,int len) {
	L[1]=V[1]=M[1]=0;
	LS[1]=v;
	int i;
	FOR(i,len) SendB((v>>i)&1);
	
}

void goA() {
	B[0]={-1,-1};
	while(Q[0].size()) {
		int co=-Q[0].top().first;
		int cur=Q[0].top().second;
		
		if(fix[0][cur] || D[0][cur]!=co) {
			Q[0].pop();
			continue;
		}
		B[0]={co,cur};
		SA(co-LD[0],9);
		return;
	}
	SA(511,9);
}
void goB() {
	B[1]={-1,-1};
	while(Q[1].size()) {
		int co=-Q[1].top().first;
		int cur=Q[1].top().second;
		if(fix[1][cur] || D[1][cur]!=co) {
			Q[1].pop();
			continue;
		}
		B[1]={co,cur};
		
		SB(co-LD[1],9);
		return;
	}
	SB(511,9);
	return;
}



void ReceiveA(bool x) {
	if(x) V[0] |= 1<<L[0];
	L[0]++;
	
	if(M[0]==0) {
		if(L[0]!=9) return;
		if(LS[0]==511 && V[0]==511) return;
		if(LS[0]<=V[0]) {
			Q[0].pop();
			SA(B[0].second,11);
			V[0]=B[0].second;
			goto update;
		}
		else {
			B[0].first=LD[0]+V[0];
			L[0]=V[0]=0;
			M[0]=1;
		}
		
	}
	else {
		if(L[0]!=11) return;
		
		B[0].second=V[0];
		update:
		LD[0]=D[0][V[0]]=B[0].first;
		fix[0][V[0]]=1;
		FORR(e,E[0][V[0]]) {
			if(D[0][e.first]>LD[0]+e.second) {
				D[0][e.first]=LD[0]+e.second;
				Q[0].push({-D[0][e.first],e.first});
			}
		}
		goA();
	}
}

void ReceiveB(bool y) {
	if(y) V[1] |= 1<<L[1];
	L[1]++;
	
	if(M[1]==0) {
		if(L[1]!=9) return;
		if(LS[1]==511 && V[1]==511) return;
		if(LS[1]<V[1]) {
			Q[1].pop();
			SB(B[1].second,11);
			V[1]=B[1].second;
			goto update;
		}
		else {
			B[1].first=LD[1]+V[1];
			L[1]=V[1]=0;
			M[1]=1;
		}
		
	}
	else {
		if(L[1]!=11) return;
		
		B[1].second=V[1];
		update:
		LD[1]=D[1][V[1]]=B[1].first;
		fix[1][V[1]]=1;
		FORR(e,E[1][V[1]]) {
			if(D[1][e.first]>LD[1]+e.second) {
				D[1][e.first]=LD[1]+e.second;
				Q[1].push({-D[1][e.first],e.first});
			}
		}
		goB();
	}
}


void InitA(int N, int A, std::vector<int> U, std::vector<int> V,
           std::vector<int> C) {
	::N=N;
	int i;
	FOR(i,U.size()) {
		E[0][U[i]].push_back({V[i],C[i]});
		E[0][V[i]].push_back({U[i],C[i]});
	}
	FOR(i,N) D[0][i]=1<<30;
	D[0][0]=0;
	Q[0].push({0,0});
	fix[0][0]=1;
	FORR(e,E[0][0]) {
		D[0][e.first]=e.second;
		Q[0].push({-e.second,e.first});
	}
	
	goA();
	
}


void InitB(int N, int B, std::vector<int> S, std::vector<int> T,
           std::vector<int> D_) {
	::N=N;
	int i;
	FOR(i,S.size()) {
		E[1][S[i]].push_back({T[i],D_[i]});
		E[1][T[i]].push_back({S[i],D_[i]});
	}
	FOR(i,N) D[1][i]=1<<30;

	D[1][0]=0;
	Q[1].push({0,0});
	fix[1][0]=1;
	
	FORR(e,E[1][0]) {
		D[1][e.first]=e.second;
		Q[1].push({-e.second,e.first});
	}
	goB();
}

vector<int> Answer() {
	vector<int> ans(N);
	int i;
	FOR(i,N) ans[i]=D[0][i];
	return ans;
}

