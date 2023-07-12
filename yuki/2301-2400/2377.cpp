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
int A[202020];
int C[202020];

ll dp[202020][2];
const ll mo=998244353;
void dfs(int cur,int pre) {
	ll from[2]={0,0};
	from[C[cur]]=1;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		ll to[2]={};
		//‚Â‚È‚°‚é
		(to[0]+=from[0]*dp[e][0]+from[1]*dp[e][1])%=mo;
		(to[1]+=from[1]*dp[e][0]+from[0]*dp[e][1])%=mo;
		//Œq‚°‚È‚¢
		(to[0]+=from[0]*dp[e][1])%=mo;
		(to[1]+=from[1]*dp[e][1])%=mo;
		swap(from,to);
	}
	dp[cur][0]=from[0];
	dp[cur][1]=from[1];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) cin>>A[i];
	
	ll ret=0;
	FOR(i,30) {
		FOR(j,N) C[j]=(A[j]>>i)&1;
		dfs(0,0);
		(ret+=dp[0][1]<<i)%=mo;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
