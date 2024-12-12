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

int N,X,K;
vector<pair<int,int>> C[555];
ll dp[50505][2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>K;
	FOR(i,N) {
		cin>>x>>y>>k;
		C[k-1].push_back({x,y});
	}
	FOR(i,N) {
		FORR2(a,b,C[i]) {
			for(x=X-a;x>=0;x--) {
				dp[x+a][1]=max(dp[x+a][1],dp[x][0]+b+K);
				dp[x+a][1]=max(dp[x+a][1],dp[x][1]+b);
			}
		}
		FOR(j,X+1) dp[j][0]=max(dp[j][0],dp[j][1]);
	}
	ll ret=0;
	FOR(x,X+1) ret=max(ret,dp[x][0]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
