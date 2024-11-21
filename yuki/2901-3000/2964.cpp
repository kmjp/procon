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

int L,K;
string S,T;
ll A[26];

ll dp[505][505][505];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>K;
	cin>>S>>T;
	while(S.size()<K) S=S+S,T=T+T;
	x=0;
	FOR(i,26) {
		cin>>A[i];
		x+=A[i];
	}
	FOR(i,26) A[i]=A[i]*modpow(x)%mo;
	
	FORR(s,S) s-='a';
	FORR(s,T) s-='a';
	ll ra=0,rb=0;
	dp[0][0][0]=1;
	FOR(i,K) {
		FOR(x,i+1) FOR(y,i+1) if(dp[i][x][y]) {
			ll v=dp[i][x][y];
			if(S[x]==T[y]) {
				(dp[i+1][x+1][y+1]+=v*A[S[x]])%=mo;
				(dp[i+1][x][y]+=v*(1+mo-A[S[x]]))%=mo;
			}
			else {
				if(x+1>=y+L) {
					(ra+=v*A[S[x]])%=mo;
				}
				else {
					(dp[i+1][x+1][y]+=v*A[S[x]])%=mo;
				}
				if(y+1>=x+L) {
					(rb+=v*A[T[y]])%=mo;
				}
				else {
					(dp[i+1][x][y+1]+=v*A[T[y]])%=mo;
				}
				(dp[i+1][x][y]+=v*(1+2*mo-A[S[x]]-A[T[y]]))%=mo;
			}
		}
	}
	cout<<ra<<" "<<rb<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
