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

int N,Q;
int dswap[1<<20];

void dfs(int ML,int MR,int L,int R,int d,int cur,int mask,int lv) {
	if(R<=ML || L>=MR) return;
	if(L<=ML && R>=MR) {
		dswap[cur] ^= 1<<d;
	}
	else {
		mask ^= dswap[cur];
		int p=(mask>>lv)&1;
		
		dfs(ML,(MR+ML)/2,L,R,d,cur*2+p,mask,lv+1);
		dfs((MR+ML)/2,MR,L,R,d,cur*2+p^1,mask,lv+1);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	
	while(Q--) {
		cin>>i>>x>>y;
		if(i==1) {
			x--;
			y=1;
			int mask=0;
			for(i=0;i<N;i++) {
				mask^=dswap[y];
				y=y*2 + (((mask>>i)^(x>>(N-1-i)))&1);
			}
			_P("%d\n",y-(1<<N)+1);
		}
		else {
			y++;
			for(i=0;i<N;i++) {
				int L=1<<i,R=L*2;
				L=max(L,x);
				R=min(R,y);
				if(L>R) continue;
				dfs(1<<i,2<<i,L,R,i,1,0,0);
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
