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

int N,M;
ll dp[303][90909];
const ll mo=998244353;
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;

	cin>>N>>M;
	dp[0][0]=1;
	FOR(i,N) {
		FOR(x,i*i+1) if(dp[i][x]) {
			//ŒÇ—§
			(dp[i+1][x]+=dp[i][x])%=mo;
			//ƒpƒX
			for(y=2;i+y<=N;y++) {
				ll a=comb(N-(i+1),y-1);
				ll b=(fact[y]*(mo+1)/2)%mo;
				(dp[i+y][x+y-1]+=dp[i][x]*a%mo*b)%=mo;
			}
			//•Â˜H
			for(y=5;i+y<=N;y++) {
				ll a=comb(N-(i+1),y-1);
				ll b=(fact[y-1]*(mo+1)/2)%mo;
				(dp[i+y][x+y]+=dp[i][x]*a%mo*b)%=mo;
			}
		}
	}
	cout<<dp[N][N*(N-1)/2-M]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
