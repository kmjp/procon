#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

const int MAT=101;
ll G[MAT][MAT],G2[MAT][MAT];
void powmat(ll p,ll n,ll a[MAT][MAT],ll r[MAT][MAT]) {
	ll i,x,y,z;
	ll a2[MAT][MAT];
	FOR(x,n) FOR(y,n) a2[x][y]=a[x][y];
	FOR(x,n) FOR(y,n) r[x][y]=0;
	FOR(i,n) r[i][i]=(1LL<<32)-1;
	while(p) {
		ll h[MAT][MAT];
		if(p%2) {
			FOR(x,n) FOR(y,n) {
				h[x][y]=0;
				FOR(z,n) h[x][y] ^= r[x][z]&a2[z][y];
			}
			FOR(x,n) FOR(y,n) r[x][y]=h[x][y];
		}
		FOR(x,n) FOR(y,n) {
			h[x][y]=0;
			FOR(z,n) h[x][y] ^= a2[x][z]&a2[z][y];
		}
		FOR(x,n) FOR(y,n) a2[x][y]=h[x][y];
		p>>=1;
	}
}

ll A[101],C[101];
ll K,M;
int loop[32];

void solve() {
	int f,i,j,k,l,x,y;
	cin>>K>>M;
	M--;
	FOR(i,K) cin>>A[i];
	FOR(i,K) cin>>C[i];
	
	//if(M<K) return _P("%lld\n",A[M]);
	ll ret=0;
	ZERO(G);
	FOR(j,K-1) G[j+1][j]=(1LL<<32)-1;
	FOR(j,K) G[0][j]=C[j];
	powmat(M,K,G,G2);
	FOR(j,K) ret^=A[j] & G2[K-1][K-1-j];
	
	cout << ret << endl;
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


