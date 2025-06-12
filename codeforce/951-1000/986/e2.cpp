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

int T,N;
vector<int> E[202020];
int D[202020],D2[202020];
const ll mo=998244353;
ll ret[202020];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int dfs(int cur,int pre,int d) {
	D[cur]=d;
	
	if(cur&&E[cur].size()==1) {
		D2[cur]=0;
	}
	else {
		D2[cur]=1<<20;
		FORR(e,E[cur]) if(e!=pre) chmin(D2[cur],dfs(e,cur,d+1)+1);
	}
	return D2[cur];
	
}
void dfs2(int cur,int pre) {
	if(cur==0) {
		ret[cur]=1;
	}
	else {
		ret[cur]=ret[pre]*(D2[cur])%mo*modpow(D2[cur]+1)%mo;
	}
	FORR(e,E[cur]) if(e!=pre) dfs2(e,cur);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		dfs(0,0,0);
		dfs2(0,0);
		FOR(i,N) cout<<ret[i]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
