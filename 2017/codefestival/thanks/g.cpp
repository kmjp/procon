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

int ok[40][40];
ll okm[40];

int N,M;
int ma[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(y,N) FOR(x,N) {
		ok[x][y]=x!=y;
		okm[x]|=1LL<<y;
	}
	FOR(i,M) {
		cin>>x>>y;
		ok[x-1][y-1]=ok[y-1][x-1]=0;
		okm[x-1]^=1LL<<(y-1);
		okm[y-1]^=1LL<<(x-1);
	}
	for(int mask=0;mask<1<<20;mask++) {
		int ng=0;
		ma[mask]=-1<<20;
		FOR(i,20) if(mask&(1<<i)) ma[mask] = max(ma[mask],ma[mask ^ (1<<i)]);
		
		FOR(y,20) if(mask&(1<<y)) {
			FOR(x,y) if((mask&(1<<x)) && ok[x][y]==0) ng=1;
		}
		if(ng==0) ma[mask]=__builtin_popcount(mask);
	}
	
	int ret=0;
	for(int mask=0;mask<1<<20;mask++) {
		int ng=0;
		ll tmask=(1<<20)-1;
		FOR(y,20) if(mask&(1<<y)) {
			tmask &= okm[y+20];
			FOR(x,y) if((mask&(1<<x)) && ok[20+x][20+y]==0) ng=1;
		}
		if(ng==0) {
			ret=max(ret,__builtin_popcount(mask)+ma[tmask]);
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
