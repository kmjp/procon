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
vector<int> E[202020];
int dp[202020];
int S[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	if(E[0].empty()) {
		FOR(i,N) cout<<0<<endl;
		return;
	}
	
	
	FOR(i,N) dp[i]=1<<20;
	dp[0]=0;
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		int cur=Q.front();
		S[dp[cur]]++;
		Q.pop();
		FORR(e,E[cur]) if(dp[e]==1<<20) {
			dp[e]=dp[cur]+1;
			Q.push(e);
		}
	}
	
	for(i=1;i<=N;i++) {
		if(i>=2) S[i]+=S[i-2];
		cout<<S[i]<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
