#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

const int mamo=10005;
int N;
string G[300];
int E[300][300];
ll dp[250][mamo];

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) cin>>G[i];
	FOR(y,N) FOR(x,N) cin>>E[y][x];
	FOR(y,N) FOR(x,mamo) dp[y][x]=1LL<<60;
	
	//if(N>50) return;
	dp[0][0]=0;
	set<pair<ll,int> > S;
	S.insert(make_pair(0,0));
	
	while(!S.empty()) {
		ll co=S.begin()->first;
		int po=S.begin()->second/(mamo+10);
		int mo=S.begin()->second%(mamo+10);
		S.erase(S.begin());
		if(co>dp[po][mo]) continue;
		if(po==N-1 && mo==0) return _P("%lld\n",co);

		FOR(i,N) {
			int nm=mo;
			if(G[po][i]=='x') continue;
			if(G[po][i]=='+') nm++;
			if(G[po][i]=='-') nm--;
			if(nm<0 || nm>=mamo-1) continue;
			if(dp[i][nm]<co+E[po][i]) continue;
			S.erase(make_pair(dp[i][nm],i*(mamo+10)+nm));
			dp[i][nm]=co+E[po][i];
			S.insert(make_pair(dp[i][nm],i*(mamo+10)+nm));
		}
		
	}
	_P("-1\n");
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


