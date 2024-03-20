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
int X[16],Y[16];

map<pair<int,int>,int> M[4];
map<int,vector<int>> C;
set<int> S;
int mi=1010;
int dp[1<<16];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		M[0][{X[i]-2,Y[i]-1}]|=1<<i;
		M[0][{X[i]-2,Y[i]+1}]|=1<<i;
		M[1][{X[i]+2,Y[i]-1}]|=1<<i;
		M[1][{X[i]+2,Y[i]+1}]|=1<<i;
		M[2][{X[i]-1,Y[i]-2}]|=1<<i;
		M[2][{X[i]+1,Y[i]-2}]|=1<<i;
		M[3][{X[i]-1,Y[i]+2}]|=1<<i;
		M[3][{X[i]+1,Y[i]+2}]|=1<<i;
	}
	FOR(j,4) FORR2(a,b,M[j]) {
		FOR(i,N) if(a.first==X[i]&&a.second==Y[i]) break;
		if(i==N) {
			C[a.first*2000+a.second].push_back(b);
		}
	}
	int mask;
	FOR(mask,1<<N) dp[mask]=1010;
	dp[0]=0;
	FORR2(a,b,C) {
		for(mask=(1<<N)-1;mask>=0;mask--) {
			FORR(v,b) chmin(dp[mask|v],dp[mask]+1);
		}
	}
	
	if(dp[(1<<N)-1]==1010) dp[(1<<N)-1]=-1;
	cout<<dp[(1<<N)-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
