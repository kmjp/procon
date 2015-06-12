#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
string S[1010],T[1010];
ll mo=1000000007;
ll dp[101][2];

ll pat() {
	int i,j,x,y;
	
	ZERO(dp);
	dp[0][0]=1;
	FOR(x,W) {
		FOR(i,2) FOR(j,2) {
			int ng=0;
			FOR(y,H) if(S[y][x]!='?' && S[y][x]!='0'+(i+j+y)%2) ng++;
			if(ng==0) (dp[x+1][(i+j)%2]+=dp[x][i])%=mo;
		}
	}
	return dp[W][0]+dp[W][1];
}

ll perf() {
	int ok1=1,ok2=1;
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,H) FOR(x,W) if(S[y][x]!='?') {
		if((S[y][x]-'0')!=((y+x)%2)) ok1=0;
		if((S[y][x]-'0')==((y+x)%2)) ok2=0;
	}
	return ok1+ok2;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	ll ret=mo-perf();
	FOR(i,2) {
		ret += pat();
		FOR(x,W) FOR(y,H) T[x]+=S[y][x];
		FOR(x,W) S[x]=T[x];
		swap(H,W);
	}
	
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
