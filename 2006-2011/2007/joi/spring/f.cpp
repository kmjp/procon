#include "grader.h"
#include "salt.h"
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

set<int> E[1010];
int val[1010];

void del(int x,int y) {
	if(x==y) {
		val[x]=0;
		ITR(e,E[x]) E[*e].erase(x);
		E[x].clear();
	}
	else {
		E[x].erase(y);
		E[y].erase(x);
	}
}

void play(int N, int e[][2]) {
	int i;
	FOR(i,N-1) {
		E[e[i][0]-1].insert(e[i][1]-1);
		E[e[i][1]-1].insert(e[i][0]-1);
	}
	FOR(i,N) val[i]=1;
	int x,y;
  while(true) {
	int VV=0,VE=0;
	FOR(i,N) {
		VV+=val[i];
		VE+=E[i].size();
	}
	VE/=2;
	
	assert(VE%2 || VV%2);
	if(VV%2 && VE%2) {
		FOR(i,N) if(E[i].size()==1) x=y=i;
	}
	else if(VV%2) {
		FOR(i,N) if(val[i]==1 && E[i].size()%2==0) x=y=i;
	}
	else {
		FOR(i,N) if(E[i].size()) x=i, y=*E[i].begin();
	}
	
	if(x>y) swap(x,y);
    int ru, rv;
    del(x,y);
    turn(x+1, y+1, &ru, &rv);
    if(ru==0 && rv==0) return;
    del(ru-1,rv-1);
  }
}
