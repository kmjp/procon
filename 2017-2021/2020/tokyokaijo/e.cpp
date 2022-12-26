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

int N,K,S,T;
int A[51];

ll C[55][55];

int dp[1<<18];
ll dp2[1<<18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,52) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j]);

	
	cin>>N>>K>>S>>T;
	
	if(S&~T) return _P("0\n");
	
	FOR(i,N) {
		cin>>A[i];
		if((A[i]&~T) ||(A[i]&S)!=S) {
			i--;
			N--;
			continue;
		}
	}
	
	int mask;
	int U=T&(~S);
	ll ret=0;
	FOR(mask,1<<18) if((mask&U)==mask) {
		FOR(i,N) dp[A[i]&mask]++;
		ll tmp=0;
		FOR(i,N) if(dp[A[i]&mask]) {
			for(j=1;j<=min(K,dp[A[i]&mask]);j++) tmp+=C[dp[A[i]&mask]][j];
			dp[A[i]&mask]=0;
		}
		if(__builtin_popcount(mask)%2) ret-=tmp;
		else ret+=tmp;
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
