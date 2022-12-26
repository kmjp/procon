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

int N,P,Q;
int A[4040],B[4040];
int T[4040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P>>Q;
	FOR(i,P) cin>>A[i];
	FOR(i,Q) cin>>B[i];
	FOR(x,P) FOR(y,Q) T[(3*N-A[x]-B[y])%N]++;
	T[N]=T[0];
	
	int id=1;
	for(i=1;i<=N;i++) if(T[i]<T[id]) id=i;
	cout<<id<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
