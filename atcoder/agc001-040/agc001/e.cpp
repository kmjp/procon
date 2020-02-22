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

int N;
int A[202000], B[202000];
ll dp[4040][4040];
ll yes[4040][4040];
ll mo=1000000007;
ll ret=0;

ll combi(ll N_, ll C_) {
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
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:combi(P_+Q_-1,Q_);}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		dp[2010-A[i]][2010-B[i]]++;
		yes[2010+A[i]][2010+B[i]]++;
	}
	FOR(x,4020) FOR(y,4020) {
		if(yes[x][y]) (ret += yes[x][y]*dp[x][y])%=mo;
		dp[x+1][y] += dp[x][y];
		if(dp[x+1][y]>=mo) dp[x+1][y]-=mo;
		dp[x][y+1] += dp[x][y];
		if(dp[x][y+1]>=mo) dp[x][y+1]-=mo;
	}
	
	FOR(i,N) {
		ret -= combi(2*(A[i]+B[i]),2*A[i]);
		if(ret<0) ret+=mo;
	}
	cout<<ret*((mo+1)/2)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
