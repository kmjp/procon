#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll N;
int P,C,M;
int A[6]={2,3,5,7,11,13};
int B[6]={4,6,8,9,10,12};
int mo=1000000007;

ll dp[2][400][4000];
ll dp2[8000];
ll single[8010];

struct Kitamasa_slow {
	vector<ll> P;
	vector<ll> mult(vector<ll>& v,vector<ll>& v2,vector<ll>& D) {
		int i,j;
		int M=v.size();
		ll lim=7LL<<60;
		vector<ll> t(2*M,0);
		FOR(i,M) FOR(j,M) if(v[i]&&v2[j]) {
			t[i+j] += v[i]*v2[j];
			if(t[i+j]>=lim) t[i+j]%=mo;
		}
		
		for(i=2*M-2;i>=M;i--) if(t[i]) {
			t[i]%=mo;
			for(j=1;j<=M;j++) if(D[M-j]) {
				t[i-j] += D[M-j]*t[i];
				if(t[i-j]>=lim) t[i-j]%= mo;
			}
		}
		FOR(i,M) t[i]%=mo;
		t.resize(M);
		return t;
	}
	
	void calc(ll N, vector<ll> D) {
		int n=D.size();
		vector<ll> p(n,0),v(n,0);
		p[0]=v[1]=1;
		while(N) {
			if(N%2) p=mult(p,v,D);
			v=mult(v,v,D);
			N/=2;
		}
		P=p;
	}
	ll calc(ll N, vector<ll> A, vector<ll> D) {
		// A_K=A0*D0+A1*D1+A2*D2..+A_K-1*D_K-1 return A_N
		int i;ll ret=0;
		calc(N,D);
		FOR(i,A.size()) ret += A[i]*P[i];
		return ret;
	}
};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P>>C;
	dp[0][0][0]=dp[1][0][0]=1;
	
	FOR(x,6) FOR(y,P) FOR(i,y*13+1) if(dp[0][y][i]) (dp[0][y+1][i+A[x]] += dp[0][y][i])%=mo;
	FOR(x,6) FOR(y,C) FOR(i,y*12+1) if(dp[1][y][i]) (dp[1][y+1][i+B[x]] += dp[1][y][i])%=mo;
	FOR(x,300*13+1) if(dp[0][P][x]) FOR(y,300*12+1) (single[x+y] += dp[0][P][x]*dp[1][C][y])%=mo;
	M=P*13+C*12;
	dp2[0]=1;
	
	for(i=1;i<=2*M+2;i++) {
		FOR(x,M+1) if(i>=x) dp2[i] += dp2[i-x]*single[x]%mo;
		dp2[i] %= mo;
	}
	
	ll tot=0;
	if(N<=2*M) {
		for(ll v=max(0LL,N-M);v<N;v++) {
			for(x=1;x<=M;x++) if(v+x>=N) tot += dp2[v]*single[x]%mo;
			tot %= mo;
		}
	}
	else {
		Kitamasa_slow kf;
		vector<ll> A(M,1),V(M,0);
		FOR(i,M) V[i]=single[M-i];
		tot = kf.calc(N+M-1,A,V);
	}
	
	cout<<tot%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
