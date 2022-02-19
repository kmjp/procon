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

double X[3],Y[3];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) cin>>X[i]>>Y[i];
	double dx=X[2]-X[1],dy=Y[2]-Y[1];
	double d=hypot(dx,dy);
	dx/=d, dy/=d;
	
	double ba=hypot(X[1]-X[0],Y[1]-Y[0]);
	double dot=dx*(X[0]-X[1])+dy*(Y[0]-Y[1]);
	
	double ret;
	if(dot<0||dot>d) {
		ret=min(hypot(X[1]-X[0],Y[1]-Y[0]),hypot(X[2]-X[0],Y[2]-Y[0]));
	}
	else {
		X[1]=X[1]+dot*dx;
		Y[1]=Y[1]+dot*dy;
		ret=hypot(X[1]-X[0],Y[1]-Y[0]);
	}
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
