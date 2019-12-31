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
int T[202020];
int A[202020];
ll mo=1000000007;
int L[202020];
int R[202020];
int L2[202020];
int R2[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>T[i];
	FOR(i,N) cin>>A[i];
	L[0]=R[0]=T[0];
	for(i=1;i<N;i++) {
		if(T[i]>T[i-1]) L[i]=R[i]=T[i];
		else R[i]=T[i], L[i]=1;
	}
	L2[N-1]=R2[N-1]=A[N-1];
	for(i=N-2;i>=0;i--) {
		if(A[i]>A[i+1]) L2[i]=R2[i]=A[i];
		else R2[i]=A[i], L2[i]=1;
	}
	ll ret=1;
	FOR(i,N) {
		L2[i]=max(L[i],L2[i]);
		R2[i]=min(R[i],R2[i]);
		if(L2[i]>R2[i]) ret=0;
		else ret=ret*(R2[i]-L2[i]+1)%mo;
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
