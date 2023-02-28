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

int N,X;
int A,B,C;

pair<int,int> dp[3030],ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,3020) dp[i]={-1<<25,0};
	dp[X]=ret={0,1000000000};
	
	FOR(i,N) {
		cin>>A>>B>>C;
		for(x=B;x<=X;x++) {
			chmax(dp[x-B],{dp[x].first+C,dp[x].second-A});
			chmax(ret,dp[x-B]);
		}
	}
	
	for(i=X;i>=0;i--) if(dp[i]==ret) {
		cout<<dp[i].first<<" "<<dp[i].second<<" "<<i<<endl;
		return;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
