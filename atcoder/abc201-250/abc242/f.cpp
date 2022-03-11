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

int H,W,C[2];
const ll mo=998244353;
ll dp[2][51][51];
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


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>C[0]>>C[1];
	int ty,tx;
	FOR(i,2) {
		for(y=1;y<=H;y++) for(x=1;x<=W;x++) if(x*y>=C[i]) {
			dp[i][y][x]=comb(x*y,C[i]);
			for(tx=1;tx<=W;tx++) for(ty=1;ty<=H;ty++) if(tx!=x||ty!=y) {
				(dp[i][y][x]-=comb(x,tx)*comb(y,ty)%mo*dp[i][ty][tx])%=mo;
			}
			dp[i][x][y]=((dp[i][x][y]%mo)+mo)%mo;
		}
	}
	
	ll ret=0;
	FOR(y,H+1) FOR(x,W+1) for(tx=1;tx+x<=W;tx++) for(ty=1;ty+y<=H;ty++) {
		ret+=comb(H,y)*comb(H-y,ty)%mo*comb(W,x)%mo*comb(W-x,tx)%mo*dp[0][y][x]%mo*dp[1][ty][tx]%mo;
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
