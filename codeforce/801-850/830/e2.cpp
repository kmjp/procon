#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX

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

int N,Q;
int A[250*250+2],B[250*250+2];

const int DI=120;
int G[605][50500];
ll ans[605][50500];
int cov[50500];
ll ret[805];
vector<int> di[50500],pi[505050];

ll val(int a,int b) {
	int g=__gcd(a,b);
	return (ll)(a/g)*(b/g);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=50000;i++) {
		for(j=i;j<=50000;j+=i) {
			di[j].push_back(i);
		}
		if(i>1&&pi[i].empty()) {
			for(j=i;j<=50000;j+=i) {
				pi[j].push_back(i);
			}
		}
	}
	cin>>N>>Q;
	FOR(i,250*250) A[i]=B[i]=1;
	
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,50500/DI+2) {
		ret[i]=1LL<<60;
		FOR(j,50102) G[i][j]=1LL<<30;
	}
	FOR(i,50000+DI) {
		chmin(ret[i/DI],val(A[i],B[i]));
		FORR(a,di[B[i]]) chmin(G[i/DI][a],B[i]/a);
	}
	FOR(i,50500/DI+2) {
		for(j=1;j<=50000;j++) {
			ans[i][j]=(G[i][j]==1LL<<30)?(1LL<<60):G[i][j];
			FORR(p,pi[j]) if(ans[i][j/p]!=1LL<<60) chmin(ans[i][j],ans[i][j/p]*p);
		}
	}
	
	while(Q--) {
		int L,R,X;
		cin>>i>>L>>R;
		L--;
		if(i==1) {
			cin>>X;
			if(L/DI!=R/DI) {
				x=L/DI;
				if(cov[x]) {
					for(i=x*DI;i<x*DI+DI;i++) A[i]=cov[x];
					cov[x]=0;
				}
				for(i=L;i<x*DI+DI;i++) A[i]=X;
				ret[x]=1LL<<60;
				for(i=x*DI;i<x*DI+DI;i++) chmin(ret[x],val(A[i],B[i]));
				L=x*DI+DI;
			}
			while(L/DI!=R/DI) {
				x=L/DI;
				cov[x]=X;
				ret[x]=ans[x][X];
				L+=DI;
			}
			x=L/DI;
			if(cov[x]) {
				for(i=x*DI;i<x*DI+DI;i++) A[i]=cov[x];
				cov[x]=0;
			}
			for(i=L;i<R;i++) A[i]=X;
			ret[x]=1LL<<60;
			for(i=x*DI;i<x*DI+DI;i++) chmin(ret[x],val(A[i],B[i]));
		}
		else {
			ll pat=1LL<<60;
			if(L/DI!=R/DI) {
				x=L/DI;
				for(i=L;i<x*DI+DI;i++) chmin(pat,val(cov[x]?cov[x]:A[i],B[i]));
				L=x*DI+DI;
			}
			while(L/DI!=R/DI) {
				chmin(pat,ret[L/DI]);
				L+=DI;
			}
			x=L/DI;
			for(i=L;i<R;i++) chmin(pat,val(cov[x]?cov[x]:A[i],B[i]));
			cout<<pat<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
