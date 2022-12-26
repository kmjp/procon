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

int N,M;
string S,T;
int dp[1300][1300][3];
int pat[1300][1300][3];

string RS,RT;

int dpdp(int s,int t,int st) { // 0-none 1-add 2-del
	if(s==N && t==M) return 0;
	int& ret=dp[s][t][st];
	if(ret>=0) return ret;
	
	ret=10101010;
	//match
	if(s<N && t<M) ret = min(ret, dpdp(s+1,t+1,0)+((S[s]==T[t])?0:5));
	// del
	if(s<N) ret = min(ret, dpdp(s+1,t,2)+((st==2)?2:9));
	// add
	if(t<M) ret = min(ret, dpdp(s,t+1,1)+((st==1)?2:9));
	return ret;
}

void dfs(int s,int t,int st) {
	if(s==N && t==M) return;
	int& ret=dp[s][t][st];
	
	if(s<N && t<M && ret==dpdp(s+1,t+1,0)+((S[s]==T[t])?0:5)) RS+=S[s], RT+=T[t], dfs(s+1,t+1,0);
	else if(s<N && ret==dpdp(s+1,t,2)+((st==2)?2:9))       RS+=S[s], RT+='-',  dfs(s+1,t,2);
	else RS+='-', RT+=T[t], dfs(s,t+1,1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S>>T;
	MINUS(dp);
	
	cout<<dpdp(0,0,0)<<endl;
	dfs(0,0,0);
	cout<<RS<<endl<<RT<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
