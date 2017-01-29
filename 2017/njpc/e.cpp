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

int N,D;
int A[101010],B[101010];
int C[101010];
int rev[101010];
vector<int> dist[101010];
vector<pair<int,int>> E[101010];

int dfs(int cur,int pre) {
	
	dist[cur].push_back(0);
	FORR(r,E[cur]) {
		int tar=(r.second?A[r.first]:B[r.first]);
		if(tar!=pre) dist[cur].push_back(dfs(tar,cur)+C[r.first]);
	}
	sort(ALL(dist[cur]));
	reverse(ALL(dist[cur]));
	return dist[cur][0];
}

void dfs2(int cur,int pre,int par) {
	
	dist[cur].push_back(par);
	sort(ALL(dist[cur]));
	reverse(ALL(dist[cur]));
	
	FORR(r,E[cur]) {
		int tar=(r.second?A[r.first]:B[r.first]);
		if(tar!=pre) {
			int id=(dist[cur][0]==dist[tar][0]+C[r.first]);
			dfs2(tar,cur,dist[cur][id]+C[r.first]);
		}
	}
}

int dfs3(int cur,int pre) {
	
	FORR(r,E[cur]) {
		int tar=(r.second?A[r.first]:B[r.first]);
		if(tar!=pre) rev[cur]+=dfs3(tar,cur)+(1^r.second);
	}
	return rev[cur];
}

void dfs4(int cur,int pre,int par) {
	rev[cur]+=par;
	
	FORR(r,E[cur]) {
		int tar=(r.second?A[r.first]:B[r.first]);
		if(tar!=pre) {
			int left=rev[cur]-(rev[tar]+(1^r.second));
			dfs4(tar,cur,left+r.second);
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	FOR(i,N-1) {
		cin>>A[i]>>B[i]>>C[i];
		A[i]--;
		B[i]--;
		E[A[i]].push_back({i,0});
		E[B[i]].push_back({i,1});
	}
	
	dfs(0,-1);
	dfs2(0,-1,0);
	dfs3(0,-1);
	dfs4(0,-1,0);
	
	int mi=1<<20;
	FOR(i,N) if(dist[i][0]<=D) mi=min(mi,rev[i]);
	if(mi==1<<20) mi=-1;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
