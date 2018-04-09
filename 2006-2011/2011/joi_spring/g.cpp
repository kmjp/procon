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

int L,R;
string S;
int NG[27][27];
ll mo=10000000;
ll nex[26];
ll dp[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>S;
	cin>>R;
	FOR(i,R) {
		char a,b;
		cin>>a>>b;
		NG[a-'A'][b-'A']=1;
	}
	FOR(i,26) nex[i]=L;
	for(i=L-1;i>=0;i--) {
		dp[i]=1;
		FOR(x,26) if(NG[S[i]-'A'][x]==0) dp[i]+=dp[nex[x]];
		dp[i]%=mo;
		nex[S[i]-'A']=i;
	}
	
	ll ret=0;
	FOR(i,26) ret+=dp[nex[i]];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
