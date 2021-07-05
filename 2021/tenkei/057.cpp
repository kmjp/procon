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

const int MAT=303;
int ma[MAT][MAT],V[MAT],R[MAT];


int gf2_rank(int A_[MAT][MAT],int n) { /* input */
	int A[MAT][MAT];
	memmove(A,A_,sizeof(A));
	int i,j,k;
	FOR(i,n) {
		int be=i,mi=n+1;
		for(j=i;j<n;j++) {
			FOR(k,n) if(A[j][k]) break;
			if(k<mi) be=j,mi=k;
		}
		if(mi>=n) break;
		FOR(j,n) swap(A[i][j],A[be][j]);
		
		FOR(j,n) if(i!=j&&A[j][mi]) {
			FOR(k,n) A[j][k] ^= A[i][k];
		}
	}
	return i;
}

int N,M;




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x;
		FOR(j,x) {
			cin>>y;
			ma[y-1][i]=1;
		}
	}
	FOR(i,M) cin>>ma[i][300];
	
	x=gf2_rank(ma,300);
	y=gf2_rank(ma,301);
	
	
	if(x!=y) {
		cout<<0<<endl;
	}
	else {
		ll ret=1;
		FOR(i,N-x) ret=ret*2%998244353;
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}