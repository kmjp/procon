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

double A,B,C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	double pi=4*atan(1);
	
	cin>>A>>B;
	C=sqrt(B*B-A*A);
	double theta=2*atan(A/C);
	_P("%.12lf\n",2*pi-theta);
	
	double S1=pi*(A+B)*(A+B);
	double S2=pi*(B-A)*(B-A);
	double ret=(S1-S2)*(2*pi-theta)/(2*pi)+pi*A*A;
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
