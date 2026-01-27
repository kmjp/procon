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
vector<pair<int,int>> E[202020];
vector<ll> dp[202020][11];
ll S,T;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>L>>S>>T;
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
	}
	dp[0][0]={0};
	FOR(i,L) {
		FOR(x,N) FORR(a,dp[x][i]) FORR2(e,c,E[x]) dp[e][i+1].push_back(c+a);
	}
	FOR(i,N) {
		FORR(a,dp[i][L]) if(a>=S&&a<=T) {
			cout<<i+1<<" ";
			break;
		}
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
