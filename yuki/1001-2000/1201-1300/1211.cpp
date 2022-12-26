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


int N,K;
ll A[101010];
ll S[203030];

int nex[22][101010];
int nex2[101010];

int ok(ll v) {
	if(S[N]/K<v) return 0;
	
	int i,j,R=0;
	FOR(i,N) {
		while(S[R]<S[i]+v) R++;
		nex[0][i]=R-i;
	}
	ZERO(nex2);
	FOR(j,17) {
		FOR(i,N) nex[j+1][i]=min(N+1,nex[j][i]+nex[j][(i+nex[j][i])%N]);
		if(K&(1<<j)) {
			FOR(i,N) if(nex2[i]<N) nex2[i]+=nex[j][(i+nex2[i])%N];
		}
	}
	FOR(i,N) if(nex2[i]<=N) return 1;
	
	return 0;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	FOR(i,2*N) S[i+1]=S[i]+A[i%N];
	S[2*N+1]=1LL<<60;
	
	ll ret=0;
	for(i=50;i>=0;i--) if(ok(ret+(1LL<<i))) ret+=1LL<<i;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
