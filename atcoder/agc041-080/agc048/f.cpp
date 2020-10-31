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

int N,M;
string S;
const ll mo=1000000007;

map<int,ll> dp[2][301][301];
int X[303],X0[303],X1[303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	reverse(ALL(S));
	
	while(S.size()) {
		string T;
		int len=0;
		FORR(c,S) {
			if(c-'0'!=(len%2)) {
				len++;
			}
			else {
				T+=c;
			}
		}
		if(len==0) return _P("0\n");
		X[M]=len;
		X0[M]=(len+1)/2;
		X1[M]=len/2;
		M++;
		S=T;
	}
	for(i=1;i<=N;i++) X0[i]+=X0[i-1],X1[i]+=X1[i-1];
	
	dp[0][0][0][300]=1;
	ll ret=0;
	FOR(i,N+1) {
		int t=i%2;
		int x0,x1;
		FOR(x0,N+1) FOR(x1,N+1) dp[t^1][x0][x1].clear();
		FOR(x0,N+1) FOR(x1,N+1) if(dp[t][x0][x1].size()) {
			if(x0+x1==N) {
				FORR(m,dp[t][x0][x1]) ret+=m.second;
			}
			else {
				FORR(m,dp[t][x0][x1]) {
					for(j=1;j<=m.first;j++) {
						if(x0+(j+1)/2<=X0[i]&&x1+j/2<=X1[i]) (dp[t^1][x0+(j+1)/2][x1+j/2][j]+=m.second)%=mo;
					}
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
