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

int N,H;
int D[505050];
vector<int> E[505050];
int A[505050];
ll ret;

set<int> S[505050];
map<int,int> M[505050];
int dif[505050];
vector<int> cand[505050];

void dfs(int cur) {
	if(A[D[cur]]==1) {
		S[cur].insert(D[cur]);
	}
	else if(A[D[cur]]>1) {
		M[cur][D[cur]]++;
	}
	
	FORR(e,E[cur]) {
		if(S[cur].size()<S[e].size()) swap(S[cur],S[e]);
		FORR(r,S[e]) S[cur].insert(r);
		S[e].clear();
		if(M[cur].size()<M[e].size()) swap(M[cur],M[e]);
		FORR(r,M[e]) {
			if(S[cur].count(r.first)) continue;
			M[cur][r.first] += r.second;
			if(M[cur][r.first]>=A[r.first]) {
				S[cur].insert(r.first);
				M[cur].erase(r.first);
			}
		}
		M[e].clear();
	}
	
	ret += S[cur].size();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>H;
	FOR(i,N-1) {
		cin>>x;
		E[x].push_back(i+1);
	}
	FOR(i,H+1) {
		cin>>A[i];
		if(A[i]==0) ret += N;
	}
	
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		FORR(r,E[x]) {
			D[r]=D[x]+1;
			Q.push(r);
		}
	}
	
	FOR(i,N) cand[D[i]].push_back(i);
	
	for(i=H;i>=0;i--) FORR(e,cand[i]) dfs(e);
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
