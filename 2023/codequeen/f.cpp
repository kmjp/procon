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

int N;
double R[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	double pi=atan(1)*4;
	cin>>N;
	FOR(i,N) cin>>R[i];
	double sum=-R[0]*R[N-1]*sin(pi*2/3)/2;
	
	double VL=0,VR=10000000;
	FOR(j,200) {
		double M=(VL+VR)/2;
		double F=0;
		FOR(i,N-1) {
			double v=min(cos(pi/2/N),2/R[i]/R[i+1]*M);
			F+=acos(v);
		}
		if(F<pi*2/3) VR=M;
		if(F>=pi*2/3) VL=M;
	}
	FOR(i,N-1) {
		double v=min(cos(pi/2/N),2/R[i]/R[i+1]*VL);
		v=acos(v);
		sum+=R[i]*R[i+1]/2*sin(v);
	}
	
	
	_P("%.12lf\n",sum);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
