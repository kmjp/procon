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

int N;
int C[101010];
vector<int> E[101010];

ll dp[101010][4];
const ll mo=1000000007;

void dfs(int cur,int pre) {
	ll from[4]={0,0,0,0};
	from[C[cur]+1]=1;
	int i;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		ll to[4]={0,0,0,0};
		FOR(i,4) {
			(to[i|1]+=from[i]*dp[e][1])%=mo;
			(to[i|2]+=from[i]*dp[e][2])%=mo;
			(to[i|3]+=from[i]*dp[e][3])%=mo;
			(to[i]+=from[i]*dp[e][3])%=mo;
		}
		
		swap(from,to);
	}
	FOR(i,4) dp[cur][i]=from[i];
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		C[i]=s=="b";
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0);
	cout<<dp[0][3]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
