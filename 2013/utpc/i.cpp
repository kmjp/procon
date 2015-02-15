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

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N;
int A[100001];
int ret[100001],inin[100001];
vector<int> E[100001];
set<int> S;

void dfs(int cur,int dir) {
	
	set<int>::iterator sit=S.lower_bound(A[cur]);
	if(sit!=S.end()) {
		if(ret[cur]==-1) ret[cur]=*sit;
		if(abs(A[cur]-*sit) < abs(A[cur]-ret[cur])) ret[cur]=*sit;
		if(abs(A[cur]-*sit) == abs(A[cur]-ret[cur])) ret[cur]=min(ret[cur],*sit);
	}
	if(sit!=S.begin()) {
		sit--;
		if(abs(A[cur]-*sit) < abs(A[cur]-ret[cur])) ret[cur]=*sit;
		if(abs(A[cur]-*sit) == abs(A[cur]-ret[cur])) ret[cur]=min(ret[cur],*sit);
	}
	
	int i;
	if(dir==0) {
		FOR(i,E[cur].size()) dfs(E[cur][i],0);
	}
	else {
		FOR(i,E[cur].size()) dfs(E[cur][E[cur].size()-1-i],1);
	}
	
	S.insert(A[cur]);
}


void solve() {
	int f,i,j,k,l,x,y;
	
	MINUS(ret);
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		inin[y]++;
	}
	FOR(i,N) if(inin[i]==0) break;
	
	
	dfs(i,0);
	S.clear();
	dfs(i,1);
	
	FOR(i,N) _P("%d\n",ret[i]);
}

int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


