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
ll X[101],Y[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	double pi=atan(1)*4;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(i,N) {
		double L=-1010,R=0;
		vector<double> D;
		FOR(j,N) if(i!=j) {
			ll dx=X[j]-X[i];
			ll dy=Y[j]-Y[i];
			D.push_back(atan2(dx,dy));
		}
		
		sort(ALL(D));
		D.push_back(D[0]+2*pi);
		double ret=0;
		FOR(j,D.size()-1) {
			if(D[j+1]-D[j]>=pi) ret=(D[j+1]-D[j])-pi;
		}
		
		_P("%.12lf\n",ret/(2*pi));
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
