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
ll mo;
int W[5050];
ll dp[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>mo;
	int L,R;
	R=(N-1)/2;
	L=R+1;
	FOR(i,L) W[i]=L-i;
	FOR(i,N) W[N-1-i]-=min(R,i+1);
	
	dp[N]=1;
	for(i=1;i<N;i++) {
		int w=-W[i]+1;
		for(x=N;x>=w;x--) (dp[x-w]+=dp[x])%=mo;
	}
	
	ll ret=0;
	FOR(i,N+1) ret+=dp[i]*i%mo;
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
