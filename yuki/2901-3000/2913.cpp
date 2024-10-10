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


int H,W;
string S[505];
ll dp[505][505];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) dp[y][x]=1LL<<60;
	}
	dp[0][0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cy=Q.top().second/1000;
		int cx=Q.top().second%1000;
		Q.pop();
		int d[4]={0,1,0,-1};
		FOR(i,4) {
			int ty=cy+d[i];
			int tx=cx+d[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W||S[ty][tx]=='#') continue;
			int c=d[i^1]?1000000000:1;
			if(chmin(dp[ty][tx],co+c)) Q.push({-dp[ty][tx],ty*1000+tx});
		}
	}
	
	ll ret=dp[H-1][W-1];
	if(ret==1LL<<60) {
		cout<<"No"<<endl;
	}
	else {
		cout<<"Yes"<<endl;
		cout<<ret/1000000000<<" "<<ret%1000000000<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
