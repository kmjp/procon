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

int H,W;
int A,SY,SX;
int B,GY,GX;
string M[51];

int ok[51][51][3600];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>A>>SY>>SX;
	cin>>B>>GY>>GX;
	FOR(y,H) cin>>M[y];
	
	
	ok[SY][SX][A]=1;
	queue<int> Q;
	Q.push(A*10000+SY*100+SX);
	
	while(Q.size()) {
		int r=Q.front();
		Q.pop();
		int sz=r/10000;
		int cy=r/100%100;
		int cx=r%100;
		
		FOR(i,4) {
			int dd[]={0,1,0,-1};
			int ty=cy+dd[i];
			int tx=cx+dd[i^1];
			if(ty<0 || ty>=H || tx<0 || tx>=W) continue;
			int nz=sz+((M[ty][tx]=='*')?1:-1);
			if(nz<=0 || nz>3500) continue;
			if(ok[ty][tx][nz]) continue;
			ok[ty][tx][nz]=1;
			Q.push(nz*10000+ty*100+tx);
		}
	}
	
	if(ok[GY][GX][B]) _P("Yes\n");
	else _P("No\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
