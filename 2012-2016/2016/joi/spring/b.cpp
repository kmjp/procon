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

#include "Memory2_lib.h"

int A[101];
int memo[101][101];


int ask(int a,int b) {
	if(a>b) swap(a,b);
	if(memo[a][b]==-1) memo[a][b]=Flip(a,b);
	return memo[a][b];
}

void Solve(int T, int N){
	MINUS(A);
	MINUS(memo);
	int i,x;
	
	vector<pair<int,int>> V;
	FOR(i,N) V.push_back({2*i,2*i+1});
	while(V.size()) {
		map<int,vector<pair<int,int>>> M;
		FORR(v,V) {
			M[ask(v.first,v.second)].push_back(v);
		}
		
		int num2=-1;
		FORR(m,M) if(m.second.size()==2) num2=m.first;
		if(num2==-1) {
			FORR(v,V) {
				A[v.first]=A[v.second]=ask(v.first,v.second);
			}
			break;
		}
		V.clear();
		FORR(m,M) if(m.first!=num2) FORR(mm,m.second) V.push_back(mm);
		pair<int,int> a=M[num2][0],b=M[num2][1];
		
		if(ask(a.first,b.first)!=num2) {
			A[a.second]=A[b.second]=num2;
			V.push_back({a.first,b.first});
		}
		else if(ask(a.first,b.second)!=num2) {
			A[a.second]=A[b.first]=num2;
			V.push_back({a.first,b.second});
		}
		else if(ask(a.second,b.first)!=num2) {
			A[a.first]=A[b.second]=num2;
			V.push_back({a.second,b.first});
		}
		else {
			A[a.first]=A[b.first]=num2;
			V.push_back({a.second,b.second});
		}
	}
	
	FOR(i,N) {
		vector<int> V;
		FOR(x,2*N) if(A[x]==i) V.push_back(x);
		Answer(V[0],V[1],i);
	}
}
