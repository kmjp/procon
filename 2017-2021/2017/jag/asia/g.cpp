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
int R[16],SX[16],SY[16],TX[16],TY[16];
int col[16][16][2];

int hoge(int v,int X,int Y,int R) {
	double sx=SX[v]-X;
	double sy=SY[v]-Y;
	double tx=TX[v]-X;
	double ty=TY[v]-Y;
	double d=hypot(tx-sx,ty-sy);
	double dx=(tx-sx)/d;
	double dy=(ty-sy)/d;
	double a;
	for(a=0;a<d;a+=0.01) {
		sx+=0.01*dx;
		sy+=0.01*dy;
		if(hypot(sx,sy)<=R) return 1;
	}
	return 0;
	
}
int ok[1<<16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>R[i]>>SX[i]>>SY[i]>>TX[i]>>TY[i];
	FOR(x,N) FOR(y,N) if(x!=y) {
		col[x][y][0]=hoge(x,SX[y],SY[y],R[x]+R[y]);
		col[x][y][1]=hoge(x,TX[y],TY[y],R[x]+R[y]);
	}
	
	int ret=0;
	ok[0]=1;
	for(int mask=0;mask<1<<N;mask++) if(ok[mask]) {
		ret=max(ret,__builtin_popcount(mask));
		FOR(x,N) if((mask&(1<<x))==0) {
			int ng=0;
			FOR(y,N) ng|=col[x][y][(mask>>y)&1];
			if(ng==0) ok[mask | (1<<x)]=1;
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
