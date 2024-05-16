#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,M;
int A[101010];
int P[202020];
int NV[202020];
ll S[101010];
set<pair<int,int>> C[202020];
vector<int> E[202020];

void dfs(int cur,int pre) {
	int i;
	P[cur]=pre;
	FOR(i,E[cur].size()) if(E[cur][i]==pre) swap(E[cur][i],E[cur].back());
	if(cur) E[cur].pop_back();
	S[cur]=A[cur];
	NV[cur]=1;
	FORR(e,E[cur]) {
		dfs(e,cur);
		S[cur]+=S[e];
		NV[cur]+=NV[e];
		C[cur].insert({-NV[e],e});
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0);
	while(M--) {
		cin>>i>>x;
		x--;
		if(i==1) {
			cout<<S[x]<<endl;
		}
		else {
			if(NV[x]==1) continue;
			auto p=C[x].begin();
			y=p->second;
			C[x].erase(p);
			C[P[x]].erase({-NV[x],x});
			
			i=NV[x];
			NV[x]=i-NV[y];
			NV[y]=i;
			
			ll a=S[x];
			S[x]=a-S[y];
			S[y]=a;
			
			P[y]=P[x];
			P[x]=y;
			C[P[y]].insert({-NV[y],y});
			C[y].insert({-NV[x],x});
			
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
