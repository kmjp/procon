#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
double X[1010],Y[1010],Z[1010];
double PX,PY,PZ;

double hoge(int a,int b,int c) {
	double dx[2],dy[2],dz[2];
	dx[0]=X[b]-X[a];
	dy[0]=Y[b]-Y[a];
	dz[0]=Z[b]-Z[a];
	dx[1]=X[c]-X[a];
	dy[1]=Y[c]-Y[a];
	dz[1]=Z[c]-Z[a];
	
	double rx=dy[0]*dz[1]-dy[1]*dz[0];
	double ry=dz[0]*dx[1]-dz[1]*dx[0];
	double rz=dx[0]*dy[1]-dx[1]*dy[0];
	
	double r=sqrt(rx*rx+ry*ry+rz*rz);
	return abs(X[a]*rx+Y[a]*ry+Z[a]*rz)/r;
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N;
	cin>>PX>>PY>>PZ;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>Z[i];
		X[i]-=PX;
		Y[i]-=PY;
		Z[i]-=PZ;
	}
	double ret=0;
	FOR(x,N) FOR(y,x) FOR(z,y) ret += hoge(z,y,x);
	_P("%.12lf\n",ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
