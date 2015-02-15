#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N;
vector<int> E[1001];
ll mo=1000000007;
ll pat[1001][1001];
ll num[1001][1001];

ll comb(int P_,int Q_) {
	static const int N_=1020;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	return C_[P_][Q_];
}

void dodo(int pre,int cur) {
	if(pat[pre][cur]==-1) {
		pat[pre][cur] = 1;
		num[pre][cur] = E[cur].size()-1;
		int x,tar;
		FOR(x,E[cur].size()) {
			tar = E[cur][x];
			if(pre==tar) continue;
			dodo(cur,tar);
			pat[pre][cur] = (pat[pre][cur] * pat[cur][tar]) % mo;
			num[pre][cur] += num[cur][tar];
		}
		int tot=num[pre][cur];
		FOR(x,E[cur].size()) {
			tar = E[cur][x];
			if(pre==tar) continue;
			pat[pre][cur] = (pat[pre][cur] * comb(tot,num[cur][tar]+1)) % mo;
			tot -= num[cur][tar]+1;
		}
	}
}

void solve() {
	int f,r,i,j,k,l, x,y,z,mask=0;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(x,N) FOR(y,N) pat[x][y]=num[x][y]=-1;
	FOR(x,N) FOR(y,E[x].size()) dodo(x,E[x][y]);
	
	ll tot=0;
	FOR(x,N) FOR(y,E[x].size()) {
		z = E[x][y];
		if(x<z) tot = (tot + ((pat[x][z]*pat[z][x])%mo)*comb(num[x][z]+num[z][x],num[x][z])) % mo;
	}
	
	return _P("%lld\n",tot);
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


