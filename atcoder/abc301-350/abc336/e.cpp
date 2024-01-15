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
ll p10[16];

ll dp[20][155][155][2];

ll dfs(int d,int cs,int mo,int le,int sum) {
	if(cs>sum) return 0;
	if(d<0) {
		return (cs==sum&&mo==0);
	}
	if(dp[d][cs][mo][le]>=0) return dp[d][cs][mo][le];
	int i;
	ll v=N/p10[d]%10;
	ll ret=0;
	FOR(i,10) {
		if(i>v&&le==0) continue;
		ret+=dfs(d-1,cs+i,(mo+i*p10[d])%sum,le|(i<v),sum);
		
	}
	return dp[d][cs][mo][le]=ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	p10[0]=1;
	FOR(i,15) p10[i+1]=p10[i]*10;
	
	cin>>N;
	ll ret=0;
	for(i=1;i<=9*15;i++) {
		MINUS(dp);
		ret+=dfs(15,0,0,0,i);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
