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

int N,K;
/*
int memo[51][2080];

int lose(int cur,int mask) {
	int fail=1;
	int i;
	if(memo[cur][mask]>=0) return memo[cur][mask];
	FOR(i,N) if(abs(i-cur)>K && ((mask & (1<<i))==0) && lose(i,mask|(1<<i))) fail=0;
	return memo[cur][mask]=fail;
}
*/
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	if(N%2) return _P("first\n");
	if(K<N/2) return _P("second\n");
	return _P("first\n");
	/*
	for(N=1;N<=10;N++) for(K=1;K<=10;K++) {
		MINUS(memo);
		FOR(i,N) if(lose(i,1<<i)==1) {
			_P("%d %d first\n",x,y);
			goto out;
		}
		_P("%d %d second\n",x,y);
		out:;
	}
	*/
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
