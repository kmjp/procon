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

int H,W;
ll K;
string S[1010];
ll mo=1000000007;

void rot() {
	int y,x;
	string T[1010];
	FOR(y,H) FOR(x,W) T[x] += S[y][x];
	FOR(x,1000) S[x]=T[x];
	swap(H,W);
}

const int MAT=2;
ll G[MAT][MAT],G2[MAT][MAT];
void powmat(ll p,int n,ll a[MAT][MAT],ll r[MAT][MAT]) {
	int i,x,y,z;
	ll a2[MAT][MAT];
	FOR(x,n) FOR(y,n) a2[x][y]=a[x][y];
	FOR(x,n) FOR(y,n) r[x][y]=0;
	FOR(i,n) r[i][i]=1;
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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	
	FOR(y,H) cin>>S[y];
	int a=0,b=0;
	FOR(y,H) if(S[y][0]=='#' && S[y][W-1]=='#') a++;
	FOR(x,W) if(S[0][x]=='#' && S[H-1][x]=='#') b++;
	if(a&&b) return _P("1\n");
	if(b) rot(), a=b;
	
	FOR(y,H) {
		FOR(x,W) {
			if(S[y][x]=='#') G[0][0]++;
			if(x>0 && a && S[y][x]=='#' && S[y][x-1]=='#') G[0][1]--;
		}
		if(S[y][0]=='#' && S[y][W-1]=='#') G[1][1]++;
	}
	
	G[0][1] += mo;
	
	powmat(K-1,2,G,G2);
	cout<<(G2[0][0] + G2[0][1])%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
