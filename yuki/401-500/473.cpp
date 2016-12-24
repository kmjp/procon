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

ll N,X;
vector<ll> V;
map<int,int> R;

map<int,int> memo[101][1500];
ll P[1500][105];


ll dfs(int left,int id,ll v) {
	if(left==0) return v==X;
	if(memo[left][id].count(v)) return memo[left][id][v];
	if(v*P[id][left]>X) return 0;
	ll ret=0;
	
	int x;
	for(x=id;x<V.size();x++) if(v*V[x]<=X && R.count(v*V[x])) ret += dfs(left-1,x,v*V[x]);
	
	return memo[left][id][v]=ret;
	
}

vector<ll> enumdiv(ll n) {
	vector<ll> S;
	for(ll i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
	sort(S.begin(),S.end());
	return S;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	X++;
	V=enumdiv(X);
	FOR(i,V.size()) {
		R[V[i]]=i;
		P[i][0]=1;
		FOR(x,100) P[i][x+1]=min(P[i][x]*V[i],1LL<<30);
	}
	
	
	cout<<dfs(N,1,1)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
