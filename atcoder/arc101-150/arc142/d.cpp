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
vector<int> E[202020];
const ll mo=998244353;
ll dp[202020][5];


void dfs(int cur,int pre) {
	int i,j;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
	
	ll from[4]={1,1,0};
	FORR(e,E[cur]) if(e!=pre) {
		ll to[4]={};
		(to[0]=from[0]*dp[e][2])%=mo;
		(to[1]=from[1]*dp[e][4])%=mo;
		(to[2]=from[2]*dp[e][4]+from[1]*dp[e][0])%=mo;
		swap(from,to);
	}
	dp[cur][0]=dp[cur][1]=(from[0]+from[2])%mo;
	from[0]=1, from[1]=0;
	FORR(e,E[cur]) if(e!=pre) {
		ll to[4]={};
		(to[0]=from[0]*dp[e][3])%=mo;
		(to[1]=from[0]*dp[e][0]+from[1]*dp[e][3])%=mo;
		swap(from,to);
	}
	dp[cur][2]=dp[cur][3]=from[1];
	from[0]=1, from[1]=from[2]=from[3]=0;
	FORR(e,E[cur]) if(e!=pre) {
		ll to[4]={};
		
		(to[0]=from[0]*dp[e][4])%=mo;
		(to[1]=from[0]*dp[e][0]+from[1]*dp[e][4])%=mo;
		(to[2]=from[0]*dp[e][1]+from[2]*dp[e][4])%=mo;
		(to[3]=from[1]*dp[e][1]+from[2]*dp[e][0]+from[3]*dp[e][4])%=mo;
		swap(from,to);
	}
	dp[cur][4]=from[3];
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	if(N<=2) {
		cout<<2<<endl;
		return;
	}
	FOR(i,N) if(E[i].size()>=2) {
		dfs(i,i);
		ll ret=dp[i][2]+dp[i][3]+dp[i][4];
		cout<<ret%mo<<endl;
		break;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
