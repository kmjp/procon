#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int X,Y,VX,VY,VH;

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>X>>Y>>VX>>VY>>VH;
	double A=VX*VX+VY*VY-VH*VH;
	double B=2*X*VX+2*Y*VY;
	double C=X*X+Y*Y;
	
	if(A==0) {
		if(B==0) {
			if(C==0) return _P("0\n");
			else return _P("IMPOSSIBLE\n");
		}
		else {
			double ho=-C/(double)B;
			if(ho<0) return _P("IMPOSSIBLE\n");
			else return _P("%.12lf\n",ho);
		}
	}
	
	double D=B*B-4*A*C;
	if(D<0) return _P("IMPOSSIBLE\n");
	double V1=(-B-sqrt(D))/(2*A);
	double V2=(-B+sqrt(D))/(2*A);
	if(V1>V2) swap(V1,V2);
	if(V1>=0) return _P("%.12lf\n",V1);
	if(V2>=0) return _P("%.12lf\n",V2);
	return _P("IMPOSSIBLE\n");
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


