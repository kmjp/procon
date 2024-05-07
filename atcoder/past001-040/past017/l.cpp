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
int A[303][303];
int B[303][303];
ll dp[303][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		for(x=y+1;x<N;x++) {
			cin>>A[y][x];
			A[x][y]=A[y][x];
		}
	}
	FOR(y,N) {
		for(x=y+1;x<N;x++) {
			cin>>B[y][x];
			B[x][y]=B[y][x];
		}
	}
	FOR(x,N) {
		FOR(y,N) dp[y][0]=dp[y][1]=1LL<<60;
		priority_queue<pair<ll,int>> Q;
		dp[x][0]=dp[x][1]=0;
		Q.push({0,x*2});
		Q.push({0,x*2+1});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second/2;
			int id=Q.top().second%2;
			Q.pop();
			if(dp[cur][id]!=co) continue;
			
			FOR(i,N) {
				if(chmin(dp[i][id],co+A[cur][i])) Q.push({-dp[i][id],i*2+id});
				if(id==0&&chmin(dp[i][1],co+B[cur][i])) Q.push({-dp[i][1],i*2+1});
			}
			
		}
		for(i=x+1;i<N;i++) cout<<dp[i][1]<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
