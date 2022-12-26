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

int K;
ll D[1010][1010];

int nex;
vector<vector<int>> E[1010];
ll F[1010];
vector<pair<int,int>> P;

void dfs(int cur,int tar) {
	FORR(e,E[cur]) {
		ll sp=(F[tar]+F[e[1]]-D[e[1]][tar])/2;
		
		if(sp>=F[e[0]]) {
			dfs(e[0],tar);
			return;
		}
		if(sp<=F[cur]) {
			continue;
		}
		
		//add
		F[nex]=sp;
		E[nex].push_back({e[0],e[1]});
		E[nex].push_back({tar,tar});
		e[0]=nex;
		nex++;
		return;
	}
	
	E[cur].push_back({tar,tar});
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	nex=K;
	FOR(y,K) FOR(x,K) cin>>D[y][x];
	FOR(y,K) {
		F[y]=D[0][y];
		if(y!=0) P.push_back({F[y],y});
	}
	sort(ALL(P));
	FORR(p,P) dfs(0,p.second);
	
	cout<<nex<<endl;
	FOR(i,nex) FORR(e,E[i]) cout<<(i+1)<<" "<<(e[0]+1)<<" "<<(F[e[0]]-F[i])<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
