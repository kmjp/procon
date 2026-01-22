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

ll N;
const ll mo=998244353;

ll dp[61][61][2][61];

ll dfs(int d,int must,int le,int lef) {
	if(lef<0) return 0;
	if(d<0) return lef==0;
	if(dp[d][must][le][lef]>=0) return dp[d][must][le][lef];
	int i;
	ll ret=0;
	FOR(i,2) {
		if(le==0&&i==1&&(N&(1LL<<d))==0) continue;
		if(must==d&&i==0) continue;
		ret+=dfs(d-1,must,le||(i==0&&(N&(1LL<<d))),lef-i);
	}
	return dp[d][must][le][lef]=ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ret=0;
	MINUS(dp);
	
	FOR(i,60) {
		FOR(j,61) {
			ll num=dfs(60,i,0,j)%mo;
			(ret+=(num*(num+1)/2%mo)*((1LL<<i)%mo))%=mo;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
