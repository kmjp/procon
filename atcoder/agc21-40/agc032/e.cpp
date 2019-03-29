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

int N,M;
ll A[202020];

int ok(int pos) {
	if(pos<0) return 0;
	for(int L=2*pos,R=2*N-1;L<R;L++,R--) if(A[L]+A[R]<M) return 0;
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,2*N) cin>>A[i];
	
	sort(A,A+2*N);
	int cur=N;
	for(i=20;i>=0;i--) if(ok(cur-(1<<i))) cur-=1<<i;
	
	ll ma=0;
	FOR(i,cur) ma=max(ma,A[i]+A[2*cur-1-i]);
	FOR(i,N-cur) ma=max(ma,(A[2*cur+i]+A[2*N-1-i])%M);
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
