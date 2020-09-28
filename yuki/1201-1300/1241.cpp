#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int X,Y,A,B,C,D;
ll T;
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template<class T> vector<T> fft(vector<T> v, bool rev=false) {
	int n=v.size(),i,j,m;
	
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	for(int m=2; m<=n; m*=2) {
		T wn=modpow(5,(mo-1)/m);
		if(rev) wn=modpow(wn);
		for(i=0;i<n;i+=m) {
			T w=1;
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				T t1=v[j1],t2=(ll)w*v[j2]%mo;
				v[j1]=t1+t2;
				v[j2]=t1+mo-t2;
				while(v[j1]>=mo) v[j1]-=mo;
				while(v[j2]>=mo) v[j2]-=mo;
				w=(ll)w*wn%mo;
			}
		}
	}
	if(rev) {
		ll rv = modpow(n);
		FOR(i,n) v[i]=(ll)v[i]*rv%mo;
	}
	return v;
}

void fft2d(vector<vector<V>>& dp,bool rev=false) {
	int Y=dp.size();
	int X=dp[0].size();
	int y,x;
	FORR(d,dp) d=fft(d,rev);
	FOR(x,X) {
		vector<ll> V(Y);
		FOR(y,Y) V[y]=dp[y][x];
		V=fft(V,rev);
		FOR(y,Y) dp[y][x]=V[y];
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y>>T>>A>>B>>C>>D;
	vector<vector<ll>> dp(1<<(X+1),vector<ll>(1<<(Y+1)));
	vector<vector<ll>> M(1<<(X+1),vector<ll>(1<<(Y+1)));
	
	dp[A][B]=dp[(1<<(X+1))-A][(1<<(Y+1))-B]=1;
	dp[A][(1<<(Y+1))-B]=dp[(1<<(X+1))-A][B]=mo-1;
	M[0][0]=M[0][1]=M[1][0]=M[(1<<(X+1))-1][0]=M[0][(1<<(Y+1))-1]=1;
	
	fft2d(dp);
	fft2d(M);
	FOR(x,dp.size()) FOR(y,dp[0].size()) {
		dp[x][y]=dp[x][y]*modpow(M[x][y],T)%mo;
	}
	
	fft2d(dp,1);
	cout<<dp[C][D]<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
