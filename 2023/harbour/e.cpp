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
ll S[202020];
const ll mo=998244353;
ll ret=0;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void dfs(int d,int L,int R) {
	if(L==R) return;
	if(d<0) {
		(ret+=1LL*(R-L)*(R-L))%=mo;
		return;
	}
	
	int M=L;
	while(M<R&&(S[M]&(1<<d))==0) M++;
	// 01
	(ret+=1LL*(M-L)*(R-M))%=mo;
	// 10
	(ret+=2LL*(M-L)*(R-M))%=mo;
	// 11
	(ret+=1LL*(R-M)*(R-M))%=mo;
	dfs(d-1,L,M);
	dfs(d-1,M,R);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>S[i];
		sort(S,S+N);
		ret=0;
		dfs(30,0,N);
		ret=ret*modpow(1LL*N*N)%mo;
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
