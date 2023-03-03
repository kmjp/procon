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

int T;
int A,B,C,D;
ll dp[30][30];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>C>>D;
		vector<int> W;
		W.push_back(0);
		W.push_back(1);
		W.push_back(2);
		FOR(i,4) if(A+2-i>=0) W.push_back(A+2-i);
		FOR(i,4) if(B+2-i>=0) W.push_back(B+2-i);
		FOR(i,4) if(C+2-i>=0) W.push_back(C+2-i);
		FOR(i,4) if(D+2-i>=0) W.push_back(D+2-i);
		sort(ALL(W));
		W.erase(unique(ALL(W)),W.end());
		int N=W.size();
		FOR(y,N) FOR(x,N) dp[y][x]=1LL<<60;
		A=lower_bound(ALL(W),A)-W.begin();
		B=lower_bound(ALL(W),B)-W.begin();
		C=lower_bound(ALL(W),C)-W.begin();
		D=lower_bound(ALL(W),D)-W.begin();
		priority_queue<pair<ll,int>> Q;
		dp[A][B]=0;
		Q.push({0,A*100+B});
		while(Q.size()) {
			ll co=-Q.top().first;
			x=Q.top().second/100;
			y=Q.top().second%100;
			Q.pop();
			if(dp[x][y]!=co) continue;
			if(y&&dp[0][y]>co+1) {
				dp[0][y]=co+1;
				Q.push({-dp[0][y],y});
			}
			if(x&&dp[x][0]>co+1) {
				dp[x][0]=co+1;
				Q.push({-dp[x][0],x*100});
			}
			if(x+1<N&&x+1!=y&&dp[x+1][y]>co+W[x+1]-W[x]) {
				dp[x+1][y]=co+W[x+1]-W[x];
				Q.push({-dp[x+1][y],(x+1)*100+y});
			}
			if(y+1<N&&y+1!=x&&dp[x][y+1]>co+W[y+1]-W[y]) {
				dp[x][y+1]=co+W[y+1]-W[y];
				Q.push({-dp[x][y+1],x*100+y+1});
			}
		}
		
		
		cout<<dp[C][D]<<endl;
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
