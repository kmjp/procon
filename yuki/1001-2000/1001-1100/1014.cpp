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
int A[101010],B[101010],C[101010];
pair<int,int> P[201010];
int id[101010];


int RL[1<<20],RR[1<<20];
vector<int> E[1<<20];
ll dp[1<<20];
ll X[1<<20];

void add_edge(int cur,int L,int R,int from) {
	if(RR[cur]<=L) return;
	if(R<=RL[cur]) return;
	
	if(L<=RL[cur]&&RR[cur]<=R) {
		E[from].push_back(cur);
	}
	else {
		add_edge(cur*2,L,R,from);
		add_edge(cur*2+1,L,R,from);
	}
}

ll dfs(int cur) {
	if(dp[cur]>=0) return dp[cur];
	if(dp[cur]==-2) return dp[cur]=1LL<<60;
	dp[cur]=-2;
	ll ret=0;
	FORR(e,E[cur]) ret=max(ret,dfs(e));
	return dp[cur]=ret+X[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i];
		P[i]={A[i],i};
	}
	sort(P,P+N);
	FOR(i,1<<19) {
		RL[(1<<19)+i]=i;
		RR[(1<<19)+i]=i+1;
	}
	for(i=(1<<19)-1;i>=1;i--) {
		E[i].push_back(2*i);
		E[i].push_back(2*i+1);
		RL[i]=RL[2*i];
		RR[i]=RR[2*i+1];
	}
	FOR(i,N) {
		id[P[i].second]=i;
	}
	FOR(i,N) {
		y=id[i];
		X[y+(1<<19)]=B[i];
		x=lower_bound(P,P+N,make_pair(B[i]-C[i]+1,0))-P;
		if(x<=y) {
			if(x) add_edge(1,0,x,y+(1<<19));
		}
		else {
			if(y) add_edge(1,0,y,y+(1<<19));
			if(y+1<x) add_edge(1,y+1,x,y+(1<<19));
		}
	}
	
	MINUS(dp);
	FOR(i,N) {
		ll ret=dfs((1<<19)+id[i]);
		if(ret>=1LL<<60) {
			cout<<"BAN"<<endl;
		}
		else {
			cout<<ret<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
