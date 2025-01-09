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
int A[20];

ll dp[20];
int from[20];

vector<pair<int,int>> ret;

void dfs(int L,int R) {
	if(L+1==R) return;
	dfs(L,R-1);
	ret.push_back({L,R-1});
	ret.push_back({L,R-2});
	dfs(L,R-1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	FOR(i,N+1) dp[i]=-1;
	dp[0]=0;
	FOR(i,N) {
		if(dp[i]+A[i]>dp[i+1]) {
			dp[i+1]=dp[i]+A[i];
			from[i+1]=i;
		}
		for(x=i+1;x<=N;x++) {
			if(dp[x]<dp[i]+(x-i)*(x-i)) {
				dp[x]=dp[i]+(x-i)*(x-i);
				from[x]=i;
			}
		}
	}
	
	int cur=N;
	while(cur) {
		x=from[cur];
		if(A[x]==0||cur-x>1) {
			for(j=x;j<cur;j++) if(A[j]==0) break;
			if(j==cur) {
				ret.push_back({x,cur-1});
			}
			else {
				ret.push_back({x,cur-1});
				ret.push_back({x,cur-1});
			}
			dfs(x,cur);
			ret.push_back({x,cur-1});
		}
		cur=x;
	}
	
	cout<<dp[N]<<" "<<ret.size()<<endl;
	FORR2(a,b,ret) cout<<a+1<<" "<<b+1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
