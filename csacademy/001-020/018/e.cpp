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
int A[101010];
int R[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) cin>>A[i];
	FOR(i,N) R[i]=9;
	FOR(j,11) {
		FOR(i,N-1) {
			if(A[i]==0) R[i]=R[i+1]=min(R[i],R[i+1]);
			if(A[i]==1) R[i+1]=min(R[i]-1,R[i+1]);
			if(A[i]==-1) R[i]=min(R[i+1]-1,R[i]);
		}
		for(i=N-2;i>=0;i--) {
			if(A[i]==0) R[i]=R[i+1]=min(R[i],R[i+1]);
			if(A[i]==1) R[i+1]=min(R[i]-1,R[i+1]);
			if(A[i]==-1) R[i]=min(R[i+1]-1,R[i]);
		}
	}
	FOR(i,N) if(R[i]<0) return _P("-1\n");
	if(R[0]==0) return _P("-1\n");
	FOR(i,N) _P("%d",R[i]);
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
