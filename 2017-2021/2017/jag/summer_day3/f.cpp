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
vector<int> E[201010];
vector<int> EB[201010];
int memo[101010];
int D[201010];
int odd;

void dfs(int v,int step) {
	if(memo[v]!=-1) {
		if(memo[v]!=step) odd=1;
		return;
	}
	memo[v]=step;
	FORR(e,E[v]) dfs(e,step^1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--;
		y--;
		E[x].push_back(y);
		E[y].push_back(x);
		EB[x].push_back(N+y);
		EB[y].push_back(N+x);
		EB[N+x].push_back(y);
		EB[N+y].push_back(x);
	}
	
	MINUS(memo);
	dfs(0,0);
	
	if(odd==0) return _P("-1\n");
	
	FOR(i,2*N) D[i]=1<<20;
	D[0]=0;
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		FORR(e,EB[x]) if(D[e]>D[x]+1) {
			D[e]=D[x]+1;
			Q.push(e);
		}
	}
	
	int ma[2]={};
	FOR(i,N) ma[0]=max(ma[0],D[i]),ma[1]=max(ma[1],D[N+i]);
	cout<<min(ma[0],ma[1])<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
