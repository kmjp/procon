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
ll B[500][500],B2[500][500];
ll S[500][500];

ll L[400],R[400];
ll from[400][400],to[400][400];
ll ma;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>B[y][x],B2[y][x]=B[y][x];
	ma=-1LL<<60;
	
	FOR(i,2) {
		FOR(x,W) FOR(y,H) S[x][y+1]=S[x][y]+B[y][x];
		
		memset(L,0xcf,sizeof(L));
		memset(R,0xcf,sizeof(R));
		
		ZERO(from);
		FOR(x,W-1) {
			int y1,y2;
			FOR(y2,H) FOR(y1,y2+1) {
				to[y1][y2]=max(0LL,from[y1][y2])+S[x][y2+1]-S[x][y1];
				L[x]=max(L[x],to[y1][y2]);
			}
			if(x) L[x]=max(L[x],L[x-1]);
			swap(from,to);
		}
		ZERO(from);
		for(x=W-1;x>=1;x--) {
			int y1,y2;
			FOR(y2,H) FOR(y1,y2+1) {
				to[y1][y2]=max(0LL,from[y1][y2])+S[x][y2+1]-S[x][y1];
				R[x]=max(R[x],to[y1][y2]);
			}
			if(x<W-1) R[x]=max(R[x],R[x+1]);
			ma=max(ma,L[x-1]+R[x]);
			swap(from,to);
		}
		
		FOR(y,300) FOR(x,300) B[y][x]=B2[x][y];
		swap(H,W);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
