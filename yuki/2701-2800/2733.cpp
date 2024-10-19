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

int N,M;
int E[6][6];
int K;
const int mo=998244353;

ll p[7];

unordered_map<int,int> dp[50][7];




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1][y-1]=E[y-1][x-1]=1;
	}
	p[0]=1;
	FOR(i,N) p[i+1]=p[i]*(K+1);
	
	FOR(i,N) dp[1][i][p[i]]=1;
	
	ll ret=0;
	for(i=1;i<=N*K;i++) {
		FOR(x,N) FORR2(a,b,dp[i][x]) {
			if(i==N*K) {
				ret+=b;
				continue;
			}
			FOR(y,N) if(E[x][y]) {
				ll v=a/p[y]%(K+1);
				if(v<K) {
					v=a+p[y];
					(dp[i+1][y][v]+=b)%=mo;
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
