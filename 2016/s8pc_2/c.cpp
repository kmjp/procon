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

int L,D;
string S;
ll dp[105][100005];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>S>>D;
	dp[0][0]=1;
	L=S.size();
	FORR(r,S) r-='0';
	FOR(i,L) {
		ll sum=0;
		for(l=1;i+l<=L;l++) {
			sum=sum*10+S[i+l-1];
			if(sum>D) break;
			for(x=0;x+sum<=D;x++) if(dp[i][x]) {
				dp[i+l][x+sum] += dp[i][x];
				if(dp[i+l][x+sum]>=mo) dp[i+l][x+sum]-=mo;
			}
		}
	}
	ll tot=0;
	FOR(i,D+1) tot+=dp[L][i];
	cout<<tot%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
