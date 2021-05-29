#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
int A[101010];
int mask[4000001];
int sum[1<<18];

int ok(int v) {
	if(v<=0) return 0;
	ZERO(sum);
	int i,x;
	FOR(i,v) sum[mask[i]]++;
	FOR(i,N) FOR(x,1<<N) if(x&(1<<i)) sum[x^(1<<i)]+=sum[x];
	FOR(i,1<<N) {
		int need=(N-__builtin_popcount(i))*K;
		if(v-sum[i^((1<<N)-1)]<need) return 0;
	}
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		FOR(j,4000000) if(j%(2*A[i])>=A[i]) mask[j]|=1<<i;
	}
	
	ll ret=2*N*K;
	for(i=30;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
