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
int X[1010],Y[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>x>>y;
	cin>>N;
	double mi=101010;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		X[i]-=x; Y[i]-=y;
		mi=min(mi,sqrt(X[i]*X[i]+Y[i]*Y[i]));
	}
	X[N]=X[0],Y[N]=Y[0];
	
	FOR(i,N) {
		double dx=X[i+1]-X[i];
		double dy=Y[i+1]-Y[i];
		double r=sqrt(dx*dx+dy*dy);
		dx/=r;
		dy/=r;
		double dot=-X[i]*dx-Y[i]*dy;
		double tx=X[i]+dot*dx;
		double ty=Y[i]+dot*dy;
		
		if((tx*Y[i]-ty*X[i])*(tx*Y[i+1]-ty*X[i+1])<0) mi=min(mi,sqrt(tx*tx+ty*ty));
	}
	
	_P("%.12lf\n",mi);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
