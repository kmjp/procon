#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
int R,S,P;
string T;
string ST[101010];
int dp[101010][3];
ll hoge(string T) {
	int N=T.size();
	int i,x,y;
	FOR(i,3) FOR(x,N+1) dp[x][i]=0;
	FOR(i,N) {
		FOR(x,3) FOR(y,3) if(x!=y) {
			int cur=dp[i][x];
			if(y==0 && T[i]=='r') cur+=P;
			if(y==1 && T[i]=='p') cur+=S;
			if(y==2 && T[i]=='s') cur+=R;
			dp[i+1][y]=max(dp[i+1][y],cur);
		}
	}
	return max({dp[N][0],dp[N][1],dp[N][2]});
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	cin>>R>>S>>P;
	cin>>T;
	FOR(i,N) ST[i%K]+=T[i];
	ll ret=0;
	FOR(i,K) ret+=hoge(ST[i]);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
