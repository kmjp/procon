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

int N;
int K[30];
int memo[1<<14];

int win(int mask) {
	int x,y,z;
	if(memo[mask]>=0) return memo[mask];
	FOR(x,N) for(y=x+1;y<N;y++) for(z=y+1;z<N;z++) if((mask>>x)&(mask>>y)&(mask>>z)&1) {
		if(K[x]<K[y]&&K[y]<K[z]) continue;
		if(K[x]>K[y]&&K[y]>K[z]) continue;
		if(K[x]==K[y]) continue;
		if(K[x]==K[z]) continue;
		if(K[y]==K[z]) continue;
		if(win(mask^(1<<x)^(1<<y)^(1<<z))==0) return memo[mask]=x*10000+y*100+z;
	}
	return memo[mask]=0;
	
}


void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N;
	FOR(i,N) cin>>K[i];
	
	MINUS(memo);
	x = win((1<<N)-1);
	if(x) _P("%d %d %d\n",x/10000,x/100%100,x%100);
	else _P("-1\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
