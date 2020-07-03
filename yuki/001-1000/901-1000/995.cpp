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

const int MAT=2;
ll G[MAT][MAT],G2[MAT][MAT];
ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void powmat(ll p,int n,ll a[MAT][MAT],ll r[MAT][MAT]) {
	int i,x,y,z;
	ll a2[MAT][MAT];
	FOR(x,n) FOR(y,n) a2[x][y]=a[x][y];
	FOR(x,n) FOR(y,n) r[x][y]=(x==y);
	while(p) {
		ll h[MAT][MAT];
		if(p%2) {
			FOR(x,n) FOR(y,n) h[x][y]=0;
			FOR(x,n) FOR(z,n) FOR(y,n) h[x][y] += (r[x][z]*a2[z][y]) % mo;
			FOR(x,n) FOR(y,n) r[x][y]=h[x][y]%mo;
		}
		FOR(x,n) FOR(y,n) h[x][y]=0;
		FOR(x,n) FOR(z,n) FOR(y,n) h[x][y] += (a2[x][z]*a2[z][y]) % mo;
		FOR(x,n) FOR(y,n) a2[x][y]=h[x][y]%mo;
		p>>=1;
	}
}

int N,M,P,Q;
ll K;
ll B[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>P>>Q;
	G[0][0]=G[1][1]=1LL*(Q-P)*modpow(Q)%mo;
	G[0][1]=G[1][0]=1LL*P*modpow(Q)%mo;
	powmat(K,2,G,G2);
	ll ret=0;
	FOR(i,N) {
		cin>>x;
		if(i<M) ret+=x*G2[0][0]%mo;
		else ret+=x*G2[0][1]%mo;
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
