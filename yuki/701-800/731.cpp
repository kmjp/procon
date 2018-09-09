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
double V[101010];
double X2,X,Y,XY;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>V[i];
		XY += i*V[i];
		X += i;
		Y += V[i];
		X2 += 1.0*i*i;
	}
	
	double A=(N*XY-X*Y)/(N*X2-X*X);
	double B=(X2*Y-XY*X)/(N*X2-X*X);
	double T=0;
	FOR(i,N) T+=abs(V[i]-(A*i+B))*abs(V[i]-(A*i+B));
	_P("%.12lf %.12lf\n",B,A);
	_P("%.12lf\n",T);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
