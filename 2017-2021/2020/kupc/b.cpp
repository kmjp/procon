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
int V[101][10101];
ll dp[101][10101];
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		FOR(x,K) cin>>V[i][x];
		sort(V[i],V[i]+K);
		if(i==0) {
			FOR(x,K) dp[i][x]=1;
		}
		else {
			y=0;
			ll sum=0;
			FOR(x,K) {
				while(y<K&&V[i-1][y]<=V[i][x]) {
					sum+=dp[i-1][y];
					y++;
				}
				dp[i][x]=sum%mo;
			}
		}
		
		
	}
	ll ret=0;
	FOR(i,K) ret+=dp[N-1][i];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
