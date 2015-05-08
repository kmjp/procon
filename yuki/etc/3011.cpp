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

int N,M;
int mat[51][51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	while(M--) {
		cin>>x>>y>>r;
		mat[x][y]=r;
	}
	
	ll ma=-1;
	int cur[51];
	int pat[51];
	FOR(i,N) cur[i]=i;
	
	srand(time(NULL));
	FOR(i,100000) {
		random_shuffle(cur,cur+N);
		ll tot=0;
		FOR(y,N) FOR(x,y) tot+=mat[cur[x]][cur[y]];
		FOR(j,100) {
			x=rand()%N;
			y=rand()%N;
			if(x==y) continue;
			if(x>y) swap(x,y);
			int diff=mat[cur[y]][cur[x]]-mat[cur[x]][cur[y]];
			for(r=x+1;r<=y-1;r++) diff+=mat[cur[r]][cur[x]]-mat[cur[x]][cur[r]]+mat[cur[y]][cur[r]]-mat[cur[r]][cur[y]];
			
			if(diff>0) {
				tot += diff;
				swap(cur[x],cur[y]);
				if(tot>ma) {
					ma=tot;
					FOR(x,N) pat[x]=cur[x];
				}
			}
		}
	}
	
	_P("%d\n",ma);
	FOR(i,N) _P("%d%c",pat[i],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
