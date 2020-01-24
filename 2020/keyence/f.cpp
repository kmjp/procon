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
string A[10];
const ll mo=998244353;

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

int R[10];
int C[10];
ll memo_all[12][12];
ll memo[12][12];

ll hoge_all(int H,int W) {
	if(memo_all[H][W]>=0) return memo_all[H][W];
	if(H==0 || W==0) return 1;
	
	ll dp[11][11][2]={};
	int y,x;
	for(y=1;y<=H;y++) dp[y][0][0]=comb(H,y);
	for(x=1;x<=W;x++) dp[0][x][1]=comb(W,x);
	
	FOR(y,H) FOR(x,W) {
		int y2,x2;
		for(y2=y+1;y2<=H;y2++) dp[y2][x][0]+=dp[y][x][1]*comb(H-y,y2-y)%mo;
		for(x2=x+1;x2<=W;x2++) dp[y][x2][1]+=dp[y][x][0]*comb(W-x,x2-x)%mo;
	}
	
	ll ret=0;
	FOR(x,W) ret+=dp[H][x][0];
	FOR(y,H) ret+=dp[y][W][1];
	return memo_all[H][W]=ret%mo;
	
}

ll hoge(int H,int W) {
	if(memo[H][W]>=0) return memo[H][W];
	ll ret=0;
	int x,y;
	FOR(y,H+1) FOR(x,W+1) ret+=comb(H,y)*comb(W,x)%mo*hoge_all(y,x)%mo*hoge_all(H-y,W-x)%mo;
	return memo[H][W]=ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>A[y];
		FOR(x,W) if(A[y][x]=='#') {
			R[y] |= 1<<x;
			C[x] |= 1<<y;
		}
	}
	MINUS(memo);
	MINUS(memo_all);
	
	int rm,cm;
	ll ret=hoge_all(H,W);
	FOR(rm,1<<H) FOR(cm,1<<W) if(rm&&cm) {
		int did=0;
		FOR(y,H) if((rm&(1<<y)) && (((R[y]&cm)==0)||(~R[y]&cm)==0)) did = 1;
		FOR(x,W) if((cm&(1<<x)) && (((C[x]&rm)==0)||(~C[x]&rm)==0)) did = 1;
		if(did==0) ret+=hoge(H-__builtin_popcount(rm),W-__builtin_popcount(cm));
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
