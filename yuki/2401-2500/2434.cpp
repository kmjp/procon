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

int N,H,X;
set<int> G,B;
vector<int> Xs;

int dp[25252][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>H>>X;
	Xs.push_back(0);
	Xs.push_back(N);
	cin>>x;
	FOR(i,x) {
		cin>>j;
		G.insert(j);
		for(y=max(0,j-X);y<=min(N,j+X);y++) Xs.push_back(y);
	}
	cin>>x;
	FOR(i,x) {
		cin>>j;
		B.insert(j);
		for(y=max(0,j-X);y<=min(N,j+X);y++) Xs.push_back(y);
	}
	sort(ALL(Xs));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	H=min(H,(int)(B.size()+G.size()+1));
	FOR(i,Xs.size()) FOR(x,2020) dp[i][x]=-1<<30;
	dp[0][H]=0;
	FOR(i,Xs.size()) {
		x=i+1;
		y=lower_bound(ALL(Xs),Xs[i]+X)-Xs.begin();
		int addx=G.count(Xs[x]);
		int delx=B.count(Xs[x]);
		int addy=(y<Xs.size())&&G.count(Xs[y]);
		int dely=(y<Xs.size())&&B.count(Xs[y]);
		FOR(j,H+1) {
			dp[x][j]=max(dp[x][j],dp[i][j]+addx-delx);
			if(j&&y<Xs.size()) dp[y][j-1]=max(dp[y][j-1],dp[i][j]+addy-dely);
		}
	}
	int ma=-101010;
	FOR(j,H+1) ma=max(ma,dp[Xs.size()-1][j]);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
