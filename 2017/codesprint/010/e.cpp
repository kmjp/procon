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
vector<int> E[303030];
vector<pair<int,int>> S[303030];
int W[303030];
int mi[303030],ma[303030];
int emi[303030],ema[303030];

ll ret=-1LL<<60;

void dfs(int cur,int pre) {
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		ma[cur]+=max(0,ma[e]);
		mi[cur]+=min(0,mi[e]);
		ema[cur]=max(ema[cur],ema[e]);
		emi[cur]=min(emi[cur],emi[e]);
	}
	ma[cur]+=W[cur];
	mi[cur]+=W[cur];
	ema[cur]=max(ema[cur],ma[cur]);
	emi[cur]=min(emi[cur],mi[cur]);
}

void dfs2(int cur,int pre,int pma,int pmi) {
	
	ret=max({ret,1LL*pma*ema[cur],1LL*pmi*emi[cur]});
	vector<ll> vma,maL,maR;
	vector<ll> vmi,miL,miR;
	int i;
	FOR(i,E[cur].size()) {
		if(E[cur][i]==pre) {
			vma.push_back(max(0,pma));
			vmi.push_back(min(0,pmi));
		}
		else {
			vma.push_back(max(0,ma[E[cur][i]]));
			vmi.push_back(min(0,mi[E[cur][i]]));
		}
	}
	maL.resize(E[cur].size()+2,0);
	maR.resize(E[cur].size()+2,0);
	miL.resize(E[cur].size()+2,0);
	miR.resize(E[cur].size()+2,0);
	FOR(i,E[cur].size()) {
		maL[i+1]=maL[i]+vma[i];
		miL[i+1]=miL[i]+vmi[i];
	}
	for(i=E[cur].size()-1;i>=0;i--) {
		maR[i+1]=maR[i+2]+vma[i];
		miR[i+1]=miR[i+2]+vmi[i];
	}
	
	FOR(i,E[cur].size()) if(E[cur][i]!=pre) {
		dfs2(E[cur][i],cur,W[cur]+maL[i]+maR[i+2],W[cur]+miL[i]+miR[i+2]);
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>W[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,-1);
	dfs2(0,-1,0,0);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
