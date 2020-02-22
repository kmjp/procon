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

int H,W,K;
ll mo;
ll po[202][20202];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

const int CN=401;
ll C[CN][CN];


ll A[101][101][101];
ll B[101][101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K>>mo;
	
	FOR(i,201) {
		po[i][0]=1;
		FOR(j,20101) po[i][j+1]=po[i][j]*i%mo;
	}
	
	FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
	
	A[0][0][0]=1;
	for(k=1;k<=K;k++) {
		FOR(y,H+1) FOR(x,W+1) if(A[k-1][y][x]) {
			ll pat=(po[k][W-x]+mo-po[k-1][W-x])%mo;
			ll v=1;
			for(int len=0;y+len<=H;len++) {
				(B[k-1][y+len][x]+=A[k-1][y][x]*C[H-y][len]%mo*v%mo*po[K+1-k][len*x])%=mo;
				v=v*pat%mo;
			}
		}
		FOR(y,H+1) FOR(x,W+1) if(B[k-1][y][x]) {
			ll pat=(po[K+1-k][y]+mo-po[K-k][y])%mo;
			ll v=1;
			for(int len=0;x+len<=W;len++) {
				(A[k][y][x+len]+=B[k-1][y][x]*C[W-x][len]%mo*v%mo*po[k][len*(H-y)])%=mo;
				v=v*pat%mo;
			}
		}
	}
	
	cout<<A[K][H][W]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
