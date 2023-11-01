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

int N,M,K;
int ma[22];
int need[1010101];
int X[444],Y[444];
ll dp[1<<20][20];
const ll mo=998244353;
const int NUM_=1400001;
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
	cin>>N>>M>>K;
	FOR(i,K) {
		cin>>X[i]>>Y[i];
		X[i]--,Y[i]--;
		need[X[i]]=need[Y[i]]=1;
	}
	int A=0,B=0;
	vector<int> V;
	FOR(i,N) {
		if(need[i]) {
			V.push_back(i);
			if(i<M) A++;
			else B++;
		}
	}
	int AL=M-A,BL=(N-M)-B;
	int C=V.size();
	FOR(i,K) {
		X[i]=lower_bound(ALL(V),X[i])-V.begin();
		Y[i]=lower_bound(ALL(V),Y[i])-V.begin();
		ma[Y[i]]|=1<<X[i];
	}
	
	FOR(i,C) dp[1<<i][i]=1;
	int mask;
	FOR(mask,1<<C) FOR(i,C) if(dp[mask][i]) {
		FOR(x,C) if((mask&(1<<x))==0&&(mask&ma[x])==0) (dp[mask|(1<<x)][x]+=dp[mask][i])%=mo;
	}
	
	ll ret=0;
	if(C==0) {
		ret=BL*fact[N-1]%mo;
	}
	
	FOR(i,C) {
		if(BL) {
			(ret+=dp[(1<<C)-1][i]*BL%mo*fact[N-C-1]%mo*comb(N-1,C))%=mo;
		}
		if(V[i]>=M) {
			(ret+=dp[(1<<C)-1][i]*fact[N-C]%mo*comb(N-1,C-1))%=mo;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
