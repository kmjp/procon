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
int X[25],Y[25];


ll mo=100000007;
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

int dp[1<<20];
pair<int,int> P[21];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(i,K) cin>>Y[i]>>X[i];
	
	
	int mask;
	for(mask=(1<<K)-1;mask>=0;mask--) {
		x=0;
		FOR(i,K) if(mask&(1<<i)) P[x++]={X[i]+Y[i],Y[i]};
		sort(P,P+x);
		
		int px=0,py=0;
		ll pat=1;
		FOR(i,x) {
			auto v=P[i];
			v.first-=v.second;
			if(v.first<px || v.second<py) {
				pat=0;
			}
			else {
				(pat*=comb(v.first-px+v.second-py,v.second-py))%=mo;
				px=v.first;
				py=v.second;
			}
		}
		dp[mask]=pat*comb(W-px+H-py,H-py)%mo;

	}
	FOR(i,K) FOR(mask,1<<K) if((mask&(1<<i))==0) {
		dp[mask]+=mo-dp[mask|(1<<i)];
		if(dp[mask]>=mo) dp[mask]-=mo;
	}
	FOR(i,K) FOR(mask,1<<K) if((mask&(1<<i))) {
		dp[mask]+=dp[mask^(1<<i)];
		if(dp[mask]>=mo) dp[mask]-=mo;
	}
	
	FOR(mask,1<<K) {
		int ok=mask^((1<<K)-1);
		_P("%d\n",dp[ok]);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
