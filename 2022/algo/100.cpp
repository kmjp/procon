#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int Q;
double X,Y,Z;
int T;

const int MAT=3;
double G[MAT][MAT],G2[MAT][MAT];
void powmat(ll p,int n,double a[MAT][MAT],double r[MAT][MAT]) {
	int i,x,y,z;
	double a2[MAT][MAT];
	FOR(x,n) FOR(y,n) a2[x][y]=a[x][y];
	FOR(x,n) FOR(y,n) r[x][y]=(x==y);
	while(p) {
		double h[MAT][MAT];
		if(p%2) {
			FOR(x,n) FOR(y,n) h[x][y]=0;
			FOR(x,n) FOR(z,n) FOR(y,n) h[x][y] += r[x][z]*a2[z][y];
			FOR(x,n) FOR(y,n) r[x][y]=h[x][y];
		}
		FOR(x,n) FOR(y,n) h[x][y]=0;
		FOR(x,n) FOR(z,n) FOR(y,n) h[x][y] += a2[x][z]*a2[z][y];
		FOR(x,n) FOR(y,n) a2[x][y]=h[x][y];
		p>>=1;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	FOR(i,Q) {
		cin>>X>>Y>>Z>>T;
		G[0][0]=(1-X);
		G[2][0]=X;
		G[1][1]=(1-Y);
		G[0][1]=Y;
		G[2][2]=(1-Z);
		G[1][2]=Z;
		powmat(T,3,G,G2);
		_P("%.12lf %.12lf %.12lf\n",G2[0][0]+G2[0][1]+G2[0][2],G2[1][0]+G2[1][1]+G2[1][2],G2[2][0]+G2[2][1]+G2[2][2]);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
