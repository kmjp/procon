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
int A[101][2],B[101][2];

int cross(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4) {
	ll XX[3],YY[3];
	XX[0]=x2-x1; YY[0]=y2-y1;
	XX[1]=x3-x1; YY[1]=y3-y1;
	XX[2]=x4-x1; YY[2]=y4-y1;
	ll c1=XX[0]*YY[1]-XX[1]*YY[0];
	ll c2=XX[0]*YY[2]-XX[2]*YY[0];
	if((c1<0&&c2<0)||(c1>0&&c2>0)) return 0;
	return 1;
}

int dodo(int x1,int y1,int x2,int y2) {
	if(x1==x2 && y1==y2) return 0;
	int i,ret=0;
	int dx=x2-x1;
	int dy=y2-y1;
	y2+=dy*300;
	y1-=dy*300;
	x2+=dx*300;
	x1-=dx*300;
	
	FOR(i,N) ret += cross(x1,y1,x2,y2,A[i][0],B[i][0],A[i][1],B[i][1]);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N<=2) return _P("%d\n",N);
	
	FOR(i,N) cin>>A[i][0]>>B[i][0]>>A[i][1]>>B[i][1];
	int ma=0;
	FOR(y,2*N) FOR(x,y) ma=max(ma,dodo(A[x/2][x%2],B[x/2][x%2],A[y/2][y%2],B[y/2][y%2]));
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
