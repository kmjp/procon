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

int H,W,N;
int A[400][400];
int dis[400][400];
int pat[1<<21];
int row[404];
int ng[404];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		dis[y][x]=1;
	}
	
	if(W>H) {
		FOR(y,400) FOR(x,y) swap(A[y][x],A[x][y]),swap(dis[y][x],dis[x][y]);
		swap(W,H);
	}
	assert(W<=20);
	
	FOR(y,H) FOR(x,W) row[y] |= A[y][x]<<x, ng[y] |= dis[y][x]<<x;
	
	
	int mask;
	FOR(mask,1<<W) {
		int x=0;
		FOR(i,W) if(mask&(1<<i)) pat[mask] ^= 7<<i;
		pat[mask]>>=1;
		pat[mask]&=(1<<W)-1;
	}
	
	int mi=1<<30;
	FOR(mask,1<<W) if((mask&ng[0])==0) {
		int cnt=__builtin_popcount(mask);
		int cur=row[0]^pat[mask];
		int nex=row[1]^mask;
		for(y=1;y<H;y++) {
			int nmask=cur;
			if(nmask&ng[y]) break;
			cur=nex^pat[nmask];
			nex=row[y+1]^nmask;
			cnt+=__builtin_popcount(nmask);
		}
		if(y==H && cur==0) mi=min(mi,cnt);
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
