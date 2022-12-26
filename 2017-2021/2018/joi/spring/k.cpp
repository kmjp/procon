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

#include "library.h"

int N;
int Q[2020];
int A[2020];
int vis[2020];

 

int query() {
	vector<int> V;
	int i;
	FOR(i,N) V.push_back(Q[i]);
	return Query(V);
}

void ans() {
	vector<int> V;
	int i;
	FOR(i,N) V.push_back(A[i]+1);
	Answer(V);
}


void Solve(int n) {
	int i,j,k,l,r,x,y; string s;
	N=n;
	
	if(N==1) ans();
	
	FOR(i,N) {
		FOR(j,N) Q[j]=1;
		Q[i]=0;
		x=query();
		if(x==1) break;
	}
	
	A[0]=i;
	vis[i]=1;
	for(i=0;i<N-1;i++) {
		vector<int> V;
		FOR(j,N) if(vis[j]==0) V.push_back(j);
		y=V.size();
		for(j=9;j>=0;j--) if(y-(1<<j)>0) {
			ZERO(Q);
			FOR(x,y-(1<<j)) Q[V[x]]=1;
			int a=query();
			Q[A[i]]=1;
			int b=query();
			if(a==b) y-=1<<j;
		}
		A[i+1]=V[y-1];
		vis[A[i+1]]=1;
	}
	ans();
	
}

