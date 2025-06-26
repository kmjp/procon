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

int T,N,K;

const int MAT=503;
ll mo=998244353;
ll ma[MAT][MAT],V[MAT],R[MAT];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll rev(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int Gauss(int n,ll mat_[MAT][MAT],ll v_[MAT],ll r[MAT]) {
	int i,j,k;
	ll mat[MAT][MAT],v[MAT];
	memmove(mat,mat_,sizeof(mat));
	memmove(v,v_,sizeof(v));
	
	FOR(i,n) {
		if(mat[i][i]==0) {
			for(j=i+1;j<n;j++) if(mat[j][i]) break;
			if(j>=n) return i;
			FOR(k,n) swap(mat[i][k],mat[j][k]);
			swap(v[i],v[j]);
		}
		(v[i]*=rev(mat[i][i]))%=mo;
		for(k=n-1;k>=i;k--) (mat[i][k]*=rev(mat[i][i]))%=mo;
		for(j=i+1;j<n;j++) {
			v[j]=((v[j]-v[i]*mat[j][i]%mo)+mo)%mo;
			for(k=n-1;k>=i;k--) mat[j][k]=((mat[j][k]-mat[i][k]*mat[j][i]%mo)+mo)%mo;
		}
	}
	
	for(i=n-1;i>=0;i--) {
		for(j=n-1;j>i;j--) v[i]=((v[i]-mat[i][j]*v[j]%mo)+mo)%mo;
		r[i]=v[i];
	}
	return n;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		ZERO(ma);
		ZERO(V);
		ZERO(R);
		FOR(i,N) {
			for(k=i-K;k<=i+K;k++) {
				if(k>=0&&k<N) ma[i][k]=modpow(2*K+1);
			}
			(ma[i][i]+=mo-1)%=mo;
			V[i]=mo-1;
		}
		Gauss(N,ma,V,R);
		FOR(i,N) cout<<R[i]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
