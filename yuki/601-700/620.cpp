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
int T;
long double P,W,V,GX,GY;

pair<long double,long double> nex(pair<long double,long double> p,long double vx=0,long double vy=0) {
	long double x2=(1+V)*p.first-W*p.second+vx;
	long double y2=W*p.first+(1+V)*p.second+vy;
	return {x2,y2};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	while(N--) {
		cin>>T>>P>>W>>V>>GX>>GY;
		
		pair<long double,long double> A[20];
		A[0]={1,0};
		FOR(i,T) A[i+1]=nex(A[i]);
		
		long double scale=sqrt((1+V)*(1+V)+W*W);
		long double co=(1+V)/scale;
		long double si=W/scale;
		
		if(scale<1e-10) {
			for(i=1;i<=T;i++) {
				if(i<T) _P("0 0\n");
				else _P("%lf %lf\n",(double)GX,(double)GY);
			}
			continue;
		}
		
		
		long double ssum=0;
		FOR(i,T) ssum+=pow(scale,2*i);
		long double cost=0;
		for(i=1;i<=T;i++) {
			long double vx=(GX-A[T].first)*pow(scale,T-i)/ssum;
			long double vy=(GY-A[T].second)*pow(scale,T-i)/ssum;
			FOR(j,T-i) {
				long double dx=vx,dy=vy;
				vx=co*dx+si*dy;
				vy=-si*dx+co*dy;
			}
			
			_P("%.15lf %.15lf\n",(double)vx,(double)vy);
			A[i]=nex(A[i-1],vx,vy);
			cost+=(vx*vx+vy*vy);
			//_P("%.15lf %.15lf  : %.15lf\n",(double)A[i].first,(double)A[i].second,(double)(vx*vx+vy*vy));
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
