#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N,M;
int A[2020],B[2020],C[2020];
int tar[2020][2020];
int col[2020];
vector<int> E[2020];
int vis[2020],len[2020];

void dfs(int cur,int co,int le) {
	if(len[cur]<0) len[cur]=le;
	else if(abs(le-len[cur])%2) {
		_P("Yes\n");
		exit(0);
	}
	FORR(r,E[cur]) {
		int id=tar[cur][r];
		if(vis[id]) continue;
		if(C[id]==co) {
			vis[id]++;
			dfs(r,co^1,le+1);
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>s;
		A[i]--;B[i]--;
		E[A[i]].push_back(B[i]);
		E[B[i]].push_back(A[i]);
		tar[A[i]][B[i]]=tar[B[i]][A[i]]=i;
		C[i]=(s=="r");
	}
	FOR(i,N) {
		FOR(j,2) {
			ZERO(vis);
			MINUS(len);
			dfs(i,j,0);
			if(count(vis,vis+M,0)==0) return _P("Yes\n");
		}
	}
	_P("No\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
