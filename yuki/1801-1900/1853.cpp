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


ll N;
const ll mo=998244353;
map<ll,ll> memo;


ll dfs(ll N) {
	if(N<=3) return N*(N+1)/2;
	if(memo.count(N)) return memo[N];
	ll ret=6-2;
	
	int i;
	ll a=(N-1)/4;
	if(a) (ret+=3*a+dfs(a))%=mo;
	a=(N-3)/4;
	if(a) (ret+=3*a+dfs(a+1)-1)%=mo;
	a=N/2;
	if(a) (ret+=a+dfs(a))%=mo;
	
	return memo[N]=ret%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cout<<dfs(N)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
