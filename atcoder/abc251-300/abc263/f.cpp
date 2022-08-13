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
ll C[1<<16][17];
ll dp[1<<16][17];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,1<<N) FOR(x,N) cin>>C[y][x+1];
	FOR(x,N) {
		for(int start=0;start<(1<<N);start+=2<<x) {
			ll ma[2]={};
			FOR(y,1<<x) {
				ma[0]=max(ma[0],dp[start+y][x]+C[start+y][x]);
				ma[1]=max(ma[1],dp[start+(1<<x)+y][x]+C[start+(1<<x)+y][x]);
			}
			FOR(y,1<<x) {
				dp[start+y][x+1]=dp[start+y][x]+ma[1];
				dp[start+y+(1<<x)][x+1]=dp[start+y+(1<<x)][x]+ma[0];
			}
		}
	}
	ll ma=0;
	FOR(x,1<<N) ma=max(ma,dp[x][N]+C[x][N]);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
