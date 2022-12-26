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

int N;
ll M;
int A[501];
ll K[501];
ll can[400000];
ll tot;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>K[i], tot += K[i]*A[i];
	
	if(tot<M) return _P("-1\n");
	M=tot-M;
	
	FOR(i,250001LL) can[i]=1LL<<60;
	can[0]=0;
	
	ll ret=1LL<<60;
	FOR(i,250001) {
		FOR(x,N) if(i-A[x]>=0) can[i] = min(can[i], can[i-A[x]]+1);
		if(i<=M && (M-i)%A[N-1]==0) ret=min(ret,can[i]+(M-i)/A[N-1]);
	}
	if(ret>=1LL<<60) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
