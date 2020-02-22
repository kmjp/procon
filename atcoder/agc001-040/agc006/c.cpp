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
ll X[101010];
int M;
ll K;
int A[62][101010];
int B[101010],C[101010];

void doswap(int a[101010],int b[101010],int c[101010]) {
	int i;
	FOR(i,N-1) c[i]=b[a[i]];
}

void solve() {
	int i,j,k,l,r,x,y;
	
	cin>>N;
	FOR(i,N) cin>>X[i];
	FOR(i,N-1) A[0][i]=B[i]=i;
	cin>>M>>K;
	FOR(i,M) {
		cin>>x;
		swap(A[0][x-2],A[0][x-1]);
	}
	
	for(i=0;i<=60;i++) {
		if(K&(1L<<i)) {
			doswap(B,A[i],C);
			swap(B,C);
		}
		doswap(A[i],A[i],A[i+1]);
	}
	
	ll s=X[0];
	FOR(i,N) {
		cout<<s<<endl;
		s+=X[B[i]+1]-X[B[i]];
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
