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
int C[252525],A[252525];
vector<pair<int,int>> E[252525];
ll ret[1010101];

ll dfs(int cur,int pre,int v) {
	vector<ll> cand;
	cand.push_back(0);
	cand.push_back(0);
	FORR(e,E[cur]) if(e.first!=pre) {
		cand.push_back(dfs(e.first,cur,v)+C[e.second]+v*A[e.second]);
	}
	sort(ALL(cand));
	reverse(ALL(cand));
	ret[v]=max(ret[v],cand[0]+cand[1]);
	return cand[0];
}

ll hoge(int v) {
	if(ret[v]==1LL<<60) {
		ret[v]=0;
		dfs(0,-1,v);
	}
	return ret[v];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	
	FOR(i,N-1) {
		cin>>x>>y>>C[i]>>A[i];
		E[x-1].push_back({y-1,i});
		E[y-1].push_back({x-1,i});
	}
	FOR(i,D+1) ret[i]=1LL<<60;
	
	int L=0,R=D;
	while(L<R-3) {
		int M1=(L*2+R)/3;
		int M2=(L+R*2)/3;
		ll v1=hoge(M1);
		ll v2=hoge(M2);
		if(v1<=v2) R=M2;
		else L=M1;
	}
	
	ll mi=1LL<<60;
	for(i=L;i<=R;i++) mi=min(mi,hoge(i));
	for(i=L;i<=R;i++) if(ret[i]==mi) {
		cout<<i<<endl;
		cout<<mi<<endl;
		break;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
