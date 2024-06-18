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

ll O[5][34];
ll X[5][34];

ll dp[9][9][34];
const ll mo=998244353;
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(ll P_,ll Q_) {
	if(P_<0 || Q_<0 || Q_>P_) return 0;
	ll p=1,q=1;
	Q_=min(Q_,P_-Q_);
	P_%=mo;
	for(int i=1;i<=Q_;i++) p=p*P_%mo, q=q*i%mo,P_--;
	
	return p*modpow(q,mo-2)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;

	
	FOR(y,5) FOR(x,34) cin>>O[y][x];
	FOR(y,5) FOR(x,34) cin>>X[y][x];
	
	dp[0][0][0]=1;
	FOR(y,5) FOR(x,34) {
		for(i=7;i>=0;i--) for(j=1;i+j<=8;j++) {
			for(int a=0;a+y*j<=4;a++) for(int b=0;b+x*j<=33;b++) {
				(dp[i+j][a+y*j][b+x*j]+=dp[i][a][b]*comb(O[y][x],j))%=mo;
			}
		}
	}
	
	ll ret=0;
	FOR(y,5) (ret+=dp[8][y][33]*(X[4-y][0]%mo))%=mo;
	cout<<ret<<endl;
	

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
