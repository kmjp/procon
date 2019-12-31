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

int N,M;
int P[2][2121];
vector<int> E[2][2121];

int L[2][2121],R[2][2121];
int id;
int S[2121][2121];

void dfs(int cur,int t) {
	L[t][cur]=id++;
	FORR(e,E[t][cur]) dfs(e,t);
	R[t][cur]=id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	for(i=1;i<=N;i++) {
		cin>>P[0][i]>>P[1][i];
		E[0][P[0][i]].push_back(i);
		E[1][P[1][i]].push_back(i);
	}
	id=0;
	dfs(0,0);
	id=0;
	dfs(0,1);
	
	FOR(i,M) {
		cin>>x>>y;
		S[L[0][x]][L[1][y]]++;
		S[R[0][x]][L[1][y]]--;
		S[L[0][x]][R[1][y]]--;
		S[R[0][x]][R[1][y]]++;
	}
	for(x=1;x<=N;x++) {
		for(y=1;y<=N;y++) {
			S[x][y]=S[x][y]+S[x-1][y]+S[x][y-1]-S[x-1][y-1];
		}
	}
	for(i=1;i<=N;i++) cout<<S[L[0][i]][L[1][i]]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
