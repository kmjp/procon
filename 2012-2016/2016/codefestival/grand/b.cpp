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

int X[3],Y[3];
double L[4];
double A,R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) cin>>X[i]>>Y[i];
	L[0]=hypot(X[0]-X[1],Y[0]-Y[1]);
	L[1]=hypot(X[1]-X[2],Y[1]-Y[2]);
	L[2]=hypot(X[2]-X[0],Y[2]-Y[0]);
	L[3]=max({L[0],L[1],L[2]});
	A = abs((X[1]-X[0])*(Y[2]-Y[0])-(X[2]-X[0])*(Y[1]-Y[0]))/2.0;
	R=2*A/(L[0]+L[1]+L[2]);
	double X = L[3]/(2+(L[3])/R);
	_P("%.12lf\n",X);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
