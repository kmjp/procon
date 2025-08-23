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

string N;
pair<ll,ll> dp[1010101][2];
const ll mo=998244353;

pair<ll,ll> dfs(int d,int le) {
	if(d<0) return {1,0};
	if(dp[d][le].first>=0) return dp[d][le];
	ll no8=0,yes8=0;
	int i;
	FOR(i,10) {
		if(le==0&&i>N[d]-'0') continue;
		auto p=dfs(d-1,le||(i<N[d]-'0'));
		if(i==8) yes8+=p.first+p.second;
		else no8+=p.first,yes8+=p.second;
	}
	
	return dp[d][le]={no8%mo,yes8%mo};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	reverse(ALL(N));
	MINUS(dp);
	
	auto p=dfs(N.size()-1,0);
	cout<<p.second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
