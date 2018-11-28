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

int N,M,K;
int P[301];
vector<int> E[301];
int D[303];

set<int> ST[301];
int ng[303];

void dfs(int cur,int pre,int d) {
	D[cur]=d;
	int p=cur;
	while(p) {
		ST[p].insert(cur);
		p=P[p];
	}
	
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	int R;
	for(i=1;i<=N;i++) {
		cin>>P[i];
		if(P[i]==0) {
			R=i;
		}
		else {
			E[P[i]].push_back(i);
		}
	}
	
	dfs(R,0,1);
	
	vector<int> V;
	while(M) {
		for(i=1;i<=N;i++) if(ng[i]==0) {
			vector<int> W;
			for(j=1;j<=N;j++) if(ng[j]==0 && ST[i].count(j)==0) W.push_back(D[j]);
			
			if(W.size()+1<M) continue;
			sort(ALL(W));
			int mi=D[i],ma=D[i];
			FOR(x,M-1) mi+=W[x];
			reverse(ALL(W));
			FOR(x,M-1) ma+=W[x];
			
			if(mi<=K && K<=ma) {
				V.push_back(i);
				K-=D[i];
				M--;
				FORR(e,ST[i]) ng[e]=1;
				break;
			}
		}
		if(i==N+1) {
			cout<<-1<<endl;
			return;
		}
	}
	FORR(v,V) cout<<v<<" ";
	cout<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
