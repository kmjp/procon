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

int N,K;
int X[303];
const ll mo=998244353;

ll num[313][313];
ll dp[313][313];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll hoge(vector<ll> X) {
	X.insert(X.begin(),0);
	X.push_back(N);
	int i,j,l;
	FOR(i,K+1) {
		ll p=1,q=1;
		for(j=1;j<=K;j++) {
			p=p*(X[i]-X[i-1]+1-j)%mo;
			q=q*j%mo;
			num[i][j]=p*modpow(q)%mo;
		}
	}
	ZERO(dp);
	dp[0][0]=1;
	FOR(i,K) {
		ll sum=0;
		FOR(j,i+1) {
			(sum+=dp[i][j])%=mo;
			for(l=1;i+l<=K;l++) {
				(dp[i+l][j+1]+=sum*num[j+1][l])%=mo;
			}
		}
	}
	ll ret=0;
	FOR(j,K+2) (ret+=dp[K][j])%=mo;
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	vector<ll> A,B;
	FOR(i,K) {
		cin>>x;
		A.push_back(x);
		B.push_back(N+1-x);
	}
	reverse(ALL(B));
	ll sum=1;
	FOR(i,K) sum=sum*(N-i)%mo*modpow(i+1)%mo;
	
	cout<<hoge(A)<<" "<<(sum+mo-hoge(B)+1)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
