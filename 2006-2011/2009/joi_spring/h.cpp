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

int N,M,C;
int T[101010];
double D[101010],S[101010];
vector<int> E[101010];
double dp[10101];
int A[10101];

int ok(double v) {
	int i;
	FOR(i,N+1) dp[i]=1e10;
	FOR(i,M) dp[A[i]]=0;
	
	for(i=1;i<N;i++) {
		FORR(e,E[i]) {
			double c=D[e]-D[e]/S[e]*v;
			dp[T[e]]=min(dp[T[e]],dp[i]+c);
		}
	}
	return dp[N]<=0;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>C;
	FOR(i,M) cin>>A[i];
	FOR(i,C) {
		cin>>x>>T[i]>>D[i]>>S[i];
		E[x].push_back(i);
	}
	
	double L=0,R=1e10;
	FOR(i,200) {
		double M=(L+R)/2;
		if(ok(M)) R=M;
		else L=M;
	}
	cout<<(int)(L+0.5)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
