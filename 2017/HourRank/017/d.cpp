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

int Q;
int N;
vector<pair<int,int>> E[505050];
set<int> S;
ll ret;
map<pair<int,int>,int> M;
int mo[2]={1000000021,1000000009};

ll modpow(ll a, ll n,ll mo) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void dfs(int cur,int pre,int a,int b) {
	ret -= M[{a,b}];
	M[{a,b}]++;
	FORR(e,E[cur]) if(e.first!=pre) {
		if(S.count(e.second)) {
			S.erase(e.second);
			int a2 = 1LL*a*modpow(7,1LL*e.second*(mo[0]-2),mo[0])%mo[0];
			int b2 = (b+modpow(5,1LL*e.second*(mo[1]-2),mo[1]))%mo[1];
			dfs(e.first,cur,a2,b2);
			S.insert(e.second);
		}
		else {
			S.insert(e.second);
			int a2 = a*modpow(7,e.second,mo[0])%mo[0];
			int b2 = (b+mo[1]-modpow(5,1LL*e.second*(mo[1]-2),mo[1]))%mo[1];
			dfs(e.first,cur,a2,b2);
			S.erase(e.second);
		}
		
		
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		
		cin>>N;
		ret=1LL*N*(N-1)/2;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y>>r;
			x--,y--,r++;
			E[x].push_back({y,r});
			E[y].push_back({x,r});
		}
		M.clear();
		S.clear();
		dfs(0,-1,1,1);
		cout<<ret<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
