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

string S;
ll mo=1000000007;
ll dp[4];
int N;
int L[101010][4];
int R[101010][4];
ll p3[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	
	N=S.size();
	p3[0]=1;
	FOR(i,N) p3[i+1]=p3[i]*3%mo;
	
	FOR(i,N) {
		FOR(j,4) L[i+1][j]=L[i][j];
		if(S[i]=='A') L[i+1][0]++;
		if(S[i]=='B') L[i+1][1]++;
		if(S[i]=='C') L[i+1][2]++;
		if(S[i]=='?') L[i+1][3]++;
	}
	for(i=N-1;i>=0;i--) {
		FOR(j,4) R[i+1][j]=R[i+2][j];
		if(S[i]=='A') R[i+1][0]++;
		if(S[i]=='B') R[i+1][1]++;
		if(S[i]=='C') R[i+1][2]++;
		if(S[i]=='?') R[i+1][3]++;
	}
	
	ll ret=0;
	for(i=2;i<=N-1;i++) if(S[i-1]=='B' || S[i-1]=='?') {
		ll lef=L[i-1][0]*p3[L[i-1][3]]%mo;
		if(L[i-1][3]) lef+=L[i-1][3]*p3[L[i-1][3]-1]%mo;
		ll ri=R[i+1][2]*p3[R[i+1][3]]%mo;
		if(R[i+1][3]) ri+=R[i+1][3]*p3[R[i+1][3]-1]%mo;
		(ret+=lef*ri)%=mo;
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
