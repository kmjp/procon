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
ll X[51],Y[51];

double ret;

void hoge(double x,double y) {
	double r=0;
	int i;
	FOR(i,N) r=max(r,hypot(X[i]-x,Y[i]-y));
	ret=min(ret,r);
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	ret=1e9;
	
	FOR(z,N) FOR(y,z) {
		double rx=(X[y]+X[z])/2.0;
		double ry=(Y[y]+Y[z])/2.0;
		hoge(rx,ry);
		
		FOR(x,y) {
			double a=hypot(X[y]-X[z],Y[y]-Y[z]);
			double b=hypot(X[z]-X[x],Y[z]-Y[x]);
			double c=hypot(X[x]-X[y],Y[x]-Y[y]);
			
			if(abs(a+b-c)<1e-9) continue;
			if(abs(a+c-b)<1e-9) continue;
			if(abs(c+b-a)<1e-9) continue;
			
			double rx=(a*a*(b*b+c*c-a*a)*X[x]+b*b*(a*a+c*c-b*b)*X[y]+c*c*(b*b+a*a-c*c)*X[z])/(a*a*(b*b+c*c-a*a)+b*b*(a*a+c*c-b*b)+c*c*(b*b+a*a-c*c));
			double ry=(a*a*(b*b+c*c-a*a)*Y[x]+b*b*(a*a+c*c-b*b)*Y[y]+c*c*(b*b+a*a-c*c)*Y[z])/(a*a*(b*b+c*c-a*a)+b*b*(a*a+c*c-b*b)+c*c*(b*b+a*a-c*c));
			hoge(rx,ry);
		}
	}
	_P("%.12lf\n",ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
