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

int N,K;
double X[100],Y[100],C[100];

double mi=1e9;

int go(double x,double y,double T) {
	int count=0;
	int i;
	
	
	FOR(i,N) if(hypot(x-X[i],y-Y[i])*C[i]<=T+(1e-9)) count++;
	return count;
}

double ok(double T) {
	int i,j;
	FOR(i,N) if(go(X[i],Y[i],T)>=K) return 1;
	
	FOR(j,N) FOR(i,j) {
		double r1=T/C[i];
		double r2=T/C[j];
		double d=hypot(X[i]-X[j],Y[i]-Y[j]);
		if(r1+r2<d) continue;
		if(r1+d<r2) continue;
		if(d+r2<r1) continue;
		double s=(r1+r2+d)/2;
		double a=sqrt(s*(s-r1)*(s-r2)*(s-d));
		double h=a/d*2;
		double d2=sqrt(r1*r1-h*h);
		double dx1=(X[j]-X[i])/d;
		double dy1=(Y[j]-Y[i])/d;
		double dx2=dy1;
		double dy2=-dx1;
		for(int cx=-1;cx<=1;cx+=2) {
			for(int cy=-1;cy<=1;cy+=2) {
				double tx=X[i]+cx*d2*dx1+cy*h*dx2;
				double ty=Y[i]+cx*d2*dy1+cy*h*dy2;
				if(go(tx,ty,T)>=K) return 1;
			}
		}
		
		
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>X[i]>>Y[i]>>C[i];
	
	double L=0,R=1e9;
	FOR(i,100) {
		double M=(L+R)/2;
		if(ok(M)) R=M;
		else L=M;
	}
	
	_P("%.12lf\n",L);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
