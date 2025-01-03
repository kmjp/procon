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
int P[5];

int memo[202][202][202];

int dfs(int a1,int a2,int a3) {
	if(a1+a2+a3==0) return 0;
	if(memo[a1][a2][a3]>=0) return memo[a1][a2][a3];
	int ret=0;
	if(a1) ret=max(ret,dfs(a1-1,a2,a3));
	if(a2) ret=max(ret,dfs(a1,a2-1,a3));
	if(a3) ret=max(ret,dfs(a1,a2,a3-1));
	if((((a1%2)?1:0)^((a2%2)?2:0)^((a3%2)?3:0))==0) ret++;
	return memo[a1][a2][a3]=ret;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	cin>>T;
	while(T--) {
		FOR(i,4) cin>>P[i+1];
		
		cout<<P[4]/2+dfs(P[1],P[2],P[3])<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
