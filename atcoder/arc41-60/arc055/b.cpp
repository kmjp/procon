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
double memo[1010][1010];

double dfs(int step,int k) {
	if(k<=0) return 0;
	if(k>=N-step+1) return 1;
	if(memo[step][k]>=0) return memo[step][k];
	
	int left=N+1-step;
	double yes=1.0/left;
	double fake=(1-yes)/step;
	double no=1-fake-yes;
	
	double take = (yes*1 + fake*dfs(step+1,k-1));
	double nottake = (fake*dfs(step+1,k));
	
	return memo[step][k] = no*dfs(step+1,k) + max(take,nottake);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>K;
	
	FOR(x,N+1) FOR(y,N+1) memo[x][y]=-1;
	_P("%.12lf\n",dfs(1,K));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
