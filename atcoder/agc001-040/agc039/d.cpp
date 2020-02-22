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

int N,L;
double T[3030];
double X[3030],Y[3030];
double W[3030];
double D[3030][3030];
double DX,DY;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	double pi=atan(1)*4;
	FOR(i,N) {
		cin>>x;
		T[i]=2*pi*x/L;
	}
	
	FOR(x,N) FOR(y,N) if(x!=y) {
		int num;
		double d;
		if(y>x) {
			num=N-(y-x+1);
			d=(T[x]+T[y])/2;
		}
		else {
			num=x-y-1;
			d=(T[x]+T[y])/2+pi;
		}
		DX+=cos(d)*num;
		DY+=sin(d)*num;
		
	}
	
	
	DX/=1LL*N*(N-1)*(N-2)/6;
	DY/=1LL*N*(N-1)*(N-2)/6;
	_P("%.12lf %.12lf\n",DX,DY);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
