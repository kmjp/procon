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
vector<pair<int,int>> E[4040];
ll dp[4040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>k;
		x--;
		E[x].push_back({y,k});
		E[y].push_back({x,-k});
	}
	FOR(i,N) E[i+1].push_back({i,-1});
	
	FOR(i,N+1) dp[i]=1LL<<60;
	dp[N]=0;
	FOR(i,N+2) {
		int up=0;
		FOR(x,N+1) FORR2(a,b,E[x]) if(chmin(dp[a],dp[x]+b)) up=1;
		if(i==N+1&&up) {
			cout<<-1<<endl;
			return;
		}
	}
	cout<<-dp[0]<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
