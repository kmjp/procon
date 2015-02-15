#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N;
int X[1001],Y[1001];
int D[1001],C[1001];
vector<pair<int,int> > E[1001];

ll memo[1001][4002];

void dfs(int cur,int pre) {
	int i,j;
	
	ITR(it,E[cur]) {
		int tar=it->first;
		if(tar!=pre) dfs(tar,cur);
	}
	
	memo[cur][4001]=1LL<<60;
	for(j=4000;j>=0;j--) {
		memo[cur][j]=max(0,j-D[cur])*C[cur];
		ITR(it,E[cur]) {
			int tar=it->first;
			if(tar!=pre) memo[cur][j]+=memo[tar][max(0,it->second-j)];
		}
		memo[cur][j]=min(memo[cur][j],memo[cur][j+1]);
	}
}

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(i,N) cin>>D[i]>>C[i];
	FOR(i,N-1) {
		cin>>x>>y;
		x--;y--;
		j=(X[x]-X[y])*(X[x]-X[y])+(Y[x]-Y[y])*(Y[x]-Y[y]);
		k=0;
		while(k*k<j) k++;
		E[x].push_back(make_pair(y,k));
		E[y].push_back(make_pair(x,k));
	}
	MINUS(memo);
	dfs(0,-1);
	_P("%lld\n",memo[0][0]);
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


