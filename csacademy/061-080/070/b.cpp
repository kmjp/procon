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
int A[303][303];
int D[303][303][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int ret=0;
	cin>>H>>W;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		if(A[y][x]==0) D[y][x][0]=-1010;
		else D[y][x][0]=1;
		D[y][x][1]=D[y][x][2]=-1010;
	}
	FOR(y,H) FOR(x,W) if(A[y][x]) {
		// right
		if(D[y][x][0]>=0 && x<W-1 && A[y][x+1]==1) D[y][x+1][1]=max(D[y][x+1][1],D[y][x][0]+1);
		if(D[y][x][1]>=0 && x<W-1 && A[y][x+1]==1) D[y][x+1][1]=max(D[y][x+1][1],D[y][x][1]+1);
		if(D[y][x][1]>=0 && y<H-1 && A[y+1][x]==1) D[y+1][x][2]=max(D[y+1][x][2],D[y][x][1]+1);
		if(D[y][x][2]>=0 && y<H-1 && A[y+1][x]==1) D[y+1][x][2]=max(D[y+1][x][2],D[y][x][2]+1);
		ret=max(ret,D[y][x][2]);
	}
	cout<<ret<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
