#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int X,S,N,K;
ll mo=1000000007;

ll fact[200],factr[200];
ll dp[355][355][200];
ll ret;

const int CN=401;
ll C[CN][CN];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	int Nx,Ny,Nz,Nxy;
	
	FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
	cin>>X>>S>>N>>K;
	fact[0]=factr[0]=1;
	FOR(i,199) fact[i+1]=fact[i]*(i+1)%mo, factr[i+1]=modpow(fact[i+1]);
	
	for(i=0;i<=X;i++) {
		FOR(x,301) FOR(y,301) {
			ll& t=dp[x][y][i];
			if(i-x-y>=0) t = fact[i]*factr[x]%mo*factr[y]%mo*factr[i-x-y]%mo;
			if(x) t += dp[x-1][y][i];
			if(y) t += dp[x][y-1][i];
			if(x&&y) t -= dp[x-1][y-1][i];
			if(t<0) t+= mo;
			while(t>=mo) t-= mo;
		}
	}
	
	if(S+N+K>=X) {
		FOR(Nx,min(X,S)+1) FOR(Ny,min(X-Nx,N)+1) FOR(Nz,min(X-Nx-Ny,K)+1) FOR(Nxy,X-Nx-Ny-Nz+1) {
			if(Nx+Ny+Nxy>S+N) break;
			ll pat=C[X][Nx]*C[X-Nx][Ny]%mo*C[X-Nx-Ny][Nz]%mo*C[X-Nx-Ny-Nz][Nxy]%mo;
			ret += pat * dp[N+K-Ny-Nz][S+K-Nx-Nz][X-Nx-Ny-Nz-Nxy] % mo;
		}
	}
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
