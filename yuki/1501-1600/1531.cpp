#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll N,K;
ll dp[62][65][2];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	dp[0][0][0]=1;
	FOR(i,61) {
		int n=(N>>i)%2;
		int k=(K>>i)%2;
		FOR(j,62) {
			FOR(x,2) {
				// not take
				(dp[i+1][j+(k^x)][k&x]+=dp[i][j][x])%=mo;
				if(n) {
					(dp[i+1][j+(k^x^1)][((k+x+1)>>1)]+=dp[i][j][x])%=mo;
				}
			}
		}
	}
	ll ret=0;
	FOR(j,62) (ret+=dp[61][j][0]%mo*((1LL<<j)%mo))%=mo;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
