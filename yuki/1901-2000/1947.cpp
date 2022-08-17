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

int N,V,C;
int v[5050],w[5050];

ll dp[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>V>>C;
	FOR(i,N) {
		cin>>v[i]>>w[i];
		for(j=V-v[i];j>=0;j--) {
			dp[j+v[i]]=max(dp[j+v[i]],dp[j]+C+w[i]);
		}
		FOR(j,V-v[i]+1) dp[j+v[i]]=max(dp[j+v[i]],dp[j]+w[i]);
	}
	
	ll ma=0;
	FOR(i,V+1) {
		ma=max(ma,dp[i]);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
