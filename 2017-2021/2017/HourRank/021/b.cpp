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

ll S,M,D;
ll mo=1000000009;

const int MAT=100;
ll G[MAT][MAT],G2[MAT][MAT];
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

ll F[21][11];
ll H[100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>M>>D;
	
	FOR(i,M+1) F[i][i]=1;
	for(i=1;i<=21;i++) {
		for(j=1;j<=M;j++) {
			for(x=1;x<=M;x++) if(abs(j-x)<=D) (F[i+x][x] += F[i][j])%=mo;
		}
	}
	
	ll ret=0;
	if(S<=M) {
		FOR(i,M+1) ret+=F[S][i];
		cout<<ret%mo<<endl;
		return;
	}
	
	for(i=1;i<M;i++) {
		for(j=1;j<=M;j++) G[M*i+j-1][M*(i-1)+j-1]=1;
	}
	for(i=1;i<=M;i++) {
		for(j=1;j<=M;j++) if(abs(i-j)<=D) {
			G[i-1][(i-1)*M+(j-1)]=1;
		}
	}
	
	
	powmat(S-M,M*M,G,G2);
	FOR(x,M) FOR(y,M) H[x*M+y]=F[M-x][y+1];
	FOR(x,M) FOR(y,M*M) ret+=G2[x][y]*H[y]%mo;
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
