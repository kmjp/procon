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

int N;
int S[4];
int T[101][2];
int L,R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	L=0,R=24*60*60*1000;
	
	scanf("%d",&N);
	
	FOR(i,N) {
		FOR(j,2) {
			scanf("%d:%d:%d.%d",&S[0],&S[1],&S[2],&S[3]);
			T[i][j]=S[0]*60*60*1000+S[1]*60*1000+S[2]*1000+S[3];
		}
		if(T[i][0]>=T[i][1]) {
			L=max(L,T[i][0]-1000);
			R=min(R,T[i][1]+1000);
		}
	}
	
	FOR(x,N) {
		int tt=T[x][1]-T[x][0];
		if(tt<=0 || (T[x][0]<=L && R<=T[x][1])) _P("%d\n", tt+1000);
		else if(R<=T[x][0] || T[x][1]<=L) _P("%d\n", tt);
		else _P("-1\n");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
