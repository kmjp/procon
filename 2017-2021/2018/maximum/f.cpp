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

int N,K,L;
ll dp[366][8][8][8][8];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>L;
	for(i=1;i<=7;i++) {
		for(j=1;j<=7;j++) {
			for(k=1;k<=7;k++) {
				for(l=1;l<=7;l++) {
					dp[K-1][i][(K>2)?j:0][(K>3)?k:0][(K>4)?l:0]=1;
				}
			}
		}
	}
	for(x=K;x<=N;x++) {
		FOR(i,8) FOR(j,8) FOR(k,8) FOR(l,8) for(y=1;y<=7;y++) {
			int ng=0;
			FOR(r,3) {
				int cnt=0;
				if(K>=1) cnt += (y>>r)&1;
				if(K>=2) cnt += (i>>r)&1;
				if(K>=3) cnt += (j>>r)&1;
				if(K>=4) cnt += (k>>r)&1;
				if(K>=5) cnt += (l>>r)&1;
				if(cnt>L) ng=1;
			}
			if(ng==0) (dp[x][y][i][j][k]+=dp[x-1][i][j][k][l])%=mo;
		}
	}
	
	ll ret=0;
	for(i=0;i<=7;i++) {
		for(j=0;j<=7;j++) {
			for(k=0;k<=7;k++) {
				for(l=0;l<=7;l++) {
					ret+=dp[N][i][j][k][l];
				}
			}
		}
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
