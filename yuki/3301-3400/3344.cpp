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

int T;
double C1X,C1Y,C2X,C2Y;
double R1,R2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>C1X>>C1Y>>R1;
		cin>>C2X>>C2Y>>R2;
		if(C2Y<C1Y) {
			swap(C1X,C2X);
			swap(C1Y,C2Y);
			swap(R1,R2);
		}
		
		double D[4];
		double dis=hypot(C2X-C1X,C2Y-C1Y);
		
		if(C2Y>C1Y) {
			D[0]=asin((R1+R2)/dis)-atan((C2X-C1X)/(C2Y-C1Y));
			D[1]=M_PI-asin((R1+R2)/dis)-atan((C2X-C1X)/(C2Y-C1Y));
			D[2]=M_PI+asin((R2-R1)/dis)-atan((C2X-C1X)/(C2Y-C1Y));
			D[3]=2*M_PI-asin((R2-R1)/dis)-atan((C2X-C1X)/(C2Y-C1Y));
		}
		else {
			D[0]=acos((R1+R2)/(C2X-C1X));
			D[1]=-D[0];
			D[2]=acos((R2-R1)/(C1X-C2X));
			D[3]=-D[2];
		}
		
		
		double ret=0;
		FOR(i,4) {
			double a=cos(D[i]);
			double b=sin(D[i]);
			double c=-R1-C1X*cos(D[i])-C1Y*sin(D[i]);
			double m=max({abs(a),abs(b),abs(c)});
			ret+=abs((a+b+c)/m);
		}
		_P("%.12lf\n",ret);
	}
	
}

int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
