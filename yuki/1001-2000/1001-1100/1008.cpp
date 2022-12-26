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
ll A[101010];
ll B[101010];
int X[101010];
ll Y[101010];
ll LD[101010];
ll RD[101010];
ll LS[101010];
ll RS[101010];
ll S[101010];


int ok(ll c) {
	int i;
	ZERO(LD);
	ZERO(RD);
	ZERO(S);
	ZERO(LS);
	ZERO(RS);
	
	if(c==0) {
		ll sum=0;
		FOR(i,M) sum+=Y[i];
		FOR(i,N) if(A[i+1]<=sum) return 0;
		return 1;
	}
	
	FOR(i,M) {
		int w=Y[i]/c;
		S[max(0,X[i]-w)]+=Y[i];
		S[min(X[i]+w+1,101000)]-=Y[i];
		RD[X[i]+1]++;
		RD[min(X[i]+w+1,101000)]--;
		RS[min(X[i]+w,101000)]-=w;
		LD[X[i]-1]++;
		LD[max(X[i]-w-1,0)]--;
		LS[max(X[i]-w,0)]-=w;
	}
	
	ll d=0,s=0;
	for(i=1;i<=N;i++) {
		d+=RD[i]*c;
		s+=d;
		S[i]+=S[i-1];
		B[i]=S[i]-s;
		s+=RS[i]*c;
	}
	d=s=0;
	for(i=N;i>=1;i--) {
		d+=LD[i]*c;
		s+=d;
		B[i]-=s;
		s+=LS[i]*c;
	}
	FOR(i,N) if(B[i+1]>=A[i+1]) return 0;
	return 1;
	
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	ll sum=0;
	FOR(i,N) {
		cin>>A[i+1];
	}
	FOR(i,M) {
		cin>>X[i]>>Y[i];
		B[X[i]]+=Y[i];
	}
	FOR(i,N) if(B[i+1]>=A[i+1]) return _P("-1\n");
	
	ll ret=(1LL<<30)-1;
	for(i=29;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
	cout<<ret<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
