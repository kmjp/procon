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

int N,M,L;
vector<int> E[202020];
int dp[202020];
vector<int> Qs[202020];
int D[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	MINUS(dp);
	cin>>L;
	FOR(i,L) {
		cin>>x>>y;
		dp[x-1]=max(dp[x-1],y);
	}
	
	FOR(i,N) if(dp[i]>=0) Qs[dp[i]].push_back(i);
	for(i=1000;i>=1;i--) {
		FORR(e,Qs[i]) if(dp[e]==i) {
			FORR(e2,E[e]) if(chmax(dp[e2],dp[e]-1)) {
				Qs[dp[e2]].push_back(e2);
			}
		}
	}
	
	FOR(i,N) D[i]=1<<20;
	D[0]=0;
	queue<int> Q;
	if(dp[0]==-1) Q.push(0);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		if(cur==N-1) {
			cout<<"Yes"<<endl;
			cout<<D[N-1]<<endl;
			return;
		}
		FORR(e,E[cur]) if(chmin(D[e],D[cur]+1)&&dp[e]==-1) Q.push(e);
	}
	cout<<"No"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
