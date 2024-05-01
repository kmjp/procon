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

int N,Q;
vector<ll> A;
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1; a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


int X[202020],Y[202020];
vector<int> S[18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,1<<N) {
		cin>>x;
		A.push_back(x);
	}
	FOR(i,Q) {
		cin>>x>>y;
		S[x].push_back(y);
	}
	
	FOR(i,N) {
		ll dp[2][2]={{1,0},{0,1}};
		FORR(v,S[i]) {
			if(v==0) {
				(dp[1][0]+=dp[0][0])%=mo;
				(dp[1][1]+=dp[0][1])%=mo;
			}
			else {
				(dp[0][0]+=dp[1][0])%=mo;
				(dp[0][1]+=dp[1][1])%=mo;
			}
		}
		FOR(j,1<<N) if((j&(1<<i))==0) {
			k=j^(1<<i);
			ll a=A[j];
			ll b=A[k];
			A[j]=(dp[0][0]*a+dp[0][1]*b)%mo;
			A[k]=(dp[1][0]*a+dp[1][1]*b)%mo;
		}
		
	}
	FOR(i,1<<N) cout<<A[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
