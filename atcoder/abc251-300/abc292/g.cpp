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

int N,M;
string S[40];
const ll mo=998244353;

ll memo[41][41][41][10];

ll dfs(int C,int L,int R,int D) {
	if(L==R) return 1;
	if(D>=10) return 0;
	
	if(C==M) {
		if(L+1==R) return 1;
		return 0;
	}
	if(memo[C][L][R][D]>=0) return memo[C][L][R][D];
	ll ret=0;
	ret+=dfs(C,L,R,D+1);
	for(int i=L;i<R;i++) {
		if(S[i][C]!='?'&&S[i][C]!=D+'0') break;
		(ret+=dfs(C+1,L,i+1,0)*dfs(C,i+1,R,D+1))%=mo;
	}
	return memo[C][L][R][D]=ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>S[i];
	
	MINUS(memo);
	cout<<dfs(0,0,N,0)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
