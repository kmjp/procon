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
set<int> E[101010];
set<int> RE[101010];
int in[101010];
int par[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N-1+M) {
		cin>>x>>y;
		E[x].insert(y);
		RE[y].insert(x);
	}
	
	FOR(i,N) if(RE[i+1].empty()) {
		E[0].insert(i+1);
		RE[i+1].insert(0);
	}
	
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		FORR(e,E[x]) {
			RE[e].erase(x);
			if(RE[e].empty()) {
				par[e]=x;
				Q.push(e);
			}
		}
	}
	
	for(i=1;i<=N;i++) cout<<par[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
