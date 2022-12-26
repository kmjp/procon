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

int M;
int A,B;
double T;

double score(double t) {
	double ret=1;
	int x=A;
	while(x--) ret*=t;
	t=log(t);
	x=B;
	while(x--) ret*=t;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,M) {
		cin>>A>>B>>T;
		
		if(B==0) {
			_P("%.12lf\n",pow(T,1.0/A));
		}
		else {
			double L=1,R=1e9;
			while(R-L>5e-10) {
				double MM=(L+R)/2;
				if(score(MM)<T) L=MM;
				else R=MM;
			}
			_P("%.12lf\n",L);
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
