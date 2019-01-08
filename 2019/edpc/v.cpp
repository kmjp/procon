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
ll mo;
vector<int> E[101010];
vector<ll> dp[101010];

ll dfs(int cur,int pre) {
	ll ret=1;
	int i;	
	FOR(i,E[cur].size()) {
		int e=E[cur][i];
		if(e!=pre) {
			dp[cur][i]=dfs(e,cur);
			(ret*=(1+dp[cur][i]))%=mo;
		}
	}
	return ret;
}

void dfs2(int cur,int pre,ll p) {
	int i;
	FOR(i,E[cur].size()) {
		int e=E[cur][i];
		if(e==pre) dp[cur][i]=p;
	}
	vector<ll> L(E[cur].size()),R(E[cur].size());
	FOR(i,E[cur].size()) {
		L[i]=(i?L[i-1]:1)*(1+dp[cur][i])%mo;
	}
	for(i=E[cur].size()-1;i>=0;i--) {
		R[i]=((i<E[cur].size()-1)?(R[i+1]):1)*(1+dp[cur][i])%mo;
		if(E[cur][i]!=pre) {
			ll tot=(i?L[i-1]:1)*((i<E[cur].size()-1)?R[i+1]:1)%mo;
			dfs2(E[cur][i],cur,tot);
		}
		
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>mo;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) dp[i].resize(E[i].size());
	ll tot=dfs(0,-1);
	dfs2(0,-1,0);
	
	FOR(i,N) {
		ll tot=1;
		FORR(d,dp[i]) (tot*=(1+d))%=mo;
		cout<<tot<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
