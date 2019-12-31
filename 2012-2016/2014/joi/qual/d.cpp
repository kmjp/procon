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
string S;
ll mo=10007;
ll dp[1010][8];
int mp[256];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	mp['J']=1;
	mp['O']=2;
	mp['I']=4;
	
	cin>>N>>S;
	dp[0][1]=1;
	FOR(i,N) {
		FOR(x,8) FOR(y,8) {
			if((x&y) && (y&mp[S[i]])) (dp[i+1][y] += dp[i][x])%=mo;
		}
	}
	
	ll ret=0;
	FOR(x,8) ret+=dp[N][x];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
