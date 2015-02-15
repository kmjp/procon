#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,D,K;

int ok[101][1001][11];
vector<int> ret;

void dfs(int n,int d,int k) {
	int i;
	if(d==0 && k==0) {
		FOR(i,ret.size()) {
			if(i) _P(" ");
			_P("%d",ret[i]);
		}
		_P("\n");
		exit(0);
	}
	if(n>N) return;
	if(k<=0) return;
	if(d<n) return;
	if(ok[n][d][k]) return;
	
	ok[n][d][k]=1;
	
	ret.push_back(n);
	dfs(n+1,d-n,k-1);
	ret.pop_back();
	dfs(n+1,d,k);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>D>>K;
	
	dfs(1,D,K);
	_P("-1\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
