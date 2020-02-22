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

ll N,mo;
ll ways2[3030][3030],ways[3030];
static const int N_=3020;
static ll C_[N_][N_];
ll p2[3030][3030];
ll p22[3030];

ll modpow(ll a, ll n = mo-2, ll m=mo) {
	ll r=1;a%=m;
	while(n) r=r*((n%2)?a:1)%m,a=a*a%m,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>mo;
	
	FOR(i,N_) C_[i][0]=C_[i][i]=1;
	for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	
	FOR(x,3020) p2[0][x]=p2[x][0]=1;
	FOR(x,3020) {
		p2[x+1][1]=p2[x][1]*2%mo;
		for(y=2;y<=3020;y++) p2[x][y]=p2[x][y-1]*p2[x][1]%mo;
	}
	
	ways2[0][1]=1;
	
	ll ret=modpow(2,modpow(2,N,mo-1));
	for(i=1;i<=N;i++) {
		ll hoge=modpow(2,modpow(2,N-i,mo-1));
		for(j=1;j<=i+1;j++) {
			(ways2[i][j]=ways2[i-1][j-1]+ways2[i-1][j]*j)%=mo;
			(ways[i]+=ways2[i][j]*p2[N-i][j-1]%mo*hoge)%=mo;
		}
		if(i%2) ret-=C_[N][i]*ways[i]%mo;
		else ret+=C_[N][i]*ways[i]%mo;
	}
	
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
