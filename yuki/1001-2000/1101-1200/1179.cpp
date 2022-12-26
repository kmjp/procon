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
	
	cin>>A>>B>>C;
	double D=B*B-4*A*C;
	
	if(D<0) {
		cout<<"imaginary"<<endl;
		return;
	}
	else if(D==0) {
		double X=-B/(2*A);
		_P("%.12lf\n",X);
	}
	else {
		D=sqrt(D);
		double X=(-B+D)/(2*A);
		double Y=(-B-D)/(2*A);
		if(X>Y) swap(X,Y);
		_P("%.12lf %.12lf\n",X,Y);
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
