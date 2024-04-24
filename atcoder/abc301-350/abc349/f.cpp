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

int N,DN;
ll M,A[202020];
const ll mo=998244353;
map<ll,ll> V;
ll p2[202020];

ll dp[1<<20];
vector<ll> Ds;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,201010) p2[i+1]=p2[i]*2%mo;
	
	cin>>N>>M;
	
	ll OM=M;
	map<ll,int> D;
	for(ll a=2;a*a<=M;a++) if(M%a==0) {
		ll b=1;
		while(M%a==0) b*=a,M/=a;
		x=D.size();
		D[b]=x;
		Ds.push_back(b);
	}
	if(M>1) {
		x=D.size();
		D[M]=x;
		Ds.push_back(M);
	}
	
	dp[0]=1;
	DN=D.size();
	
	int mask;
	FOR(i,N) {
		cin>>A[i];
		if(OM%A[i]) continue;
		int mask2=0;
		FOR(j,DN) if(A[i]%Ds[j]==0) mask2|=1<<j;
		V[mask2]++;
	}
	FORR2(mask2,n,V) {
		for(mask=(1<<DN)-1;mask>=0;mask--) {
			(dp[mask|mask2]+=(p2[n]-1)*dp[mask])%=mo;
		}
		
	}
	
	(dp[0]+=mo-1)%=mo;;
	
	cout<<dp[(1<<DN)-1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
