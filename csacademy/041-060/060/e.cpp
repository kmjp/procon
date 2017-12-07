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

int N;
vector<pair<int,int>> E[101010];
int vis[101010];
ll P[101010][2];
ll L[101010][2];

void dfs(int cur,int pre) {
	int tar=-1;
	vis[cur]=1;
	P[cur][1]=L[cur][1]=1LL<<50;
	FORR(e,E[cur]) {
		int t=e.first;
		if(t==pre) {
			tar=e.second;
			continue;
		}
		pair<ll,ll> T[2];
		dfs(t,cur);
		
		T[0]=min(make_pair(P[cur][0]+P[t][0],L[cur][0]+L[t][0]),make_pair(P[cur][1]+P[t][1]-1,L[cur][1]+L[t][1]));
		T[1]=min(make_pair(P[cur][0]+P[t][1],L[cur][0]+L[t][1]),make_pair(P[cur][1]+P[t][0],L[cur][1]+L[t][0]));
		
		P[cur][0]=T[0].first;
		P[cur][1]=T[1].first;
		L[cur][0]=T[0].second;
		L[cur][1]=T[1].second;
		
	}
	
	if(tar==1) {
		pair<ll,ll> T=min(make_pair(P[cur][0]+1,L[cur][0]+1),make_pair(P[cur][1],L[cur][1]+1));
		P[cur][1]=T.first;
		L[cur][1]=T.second;
		P[cur][0]=L[cur][0]=1LL<<50;
	}
	else {
		pair<ll,ll> T[2];
		T[0]=min(make_pair(P[cur][0],L[cur][0]),make_pair(P[cur][1],L[cur][1]));
		T[1]=min(make_pair(P[cur][0]+1,L[cur][0]+1),make_pair(P[cur][1],L[cur][1]+1));
		
		P[cur][0]=T[0].first;
		P[cur][1]=T[1].first;
		L[cur][0]=T[0].second;
		L[cur][1]=T[1].second;
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>j>>k;
		if(j==k) continue;
		x--;
		y--;
		E[x].push_back({y,k!=2});
		E[y].push_back({x,k!=2});
	}
	
	ll PR=0,LR=0;
	FOR(i,N) if(vis[i]==0) {
		dfs(i,-1);
		PR+=P[i][0];
		LR+=L[i][0];
	}
	cout<<PR<<" "<<LR<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
