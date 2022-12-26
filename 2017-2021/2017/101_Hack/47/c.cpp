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

int T;
double XH,YH;
double XC,YC,VC;
double X,Y,V;

double dist(double t) {
	double cx=XH-XC;
	double cy=YH-YC;
	double C=hypot(cx,cy);
	cx/=C;
	cy/=C;
	double tx=XC+cx*t*VC;
	double ty=YC+cy*t*VC;
	
	double dx=tx-X;
	double dy=ty-Y;
	return t*V-hypot(dx,dy);
}

int ok() {
	
	double a=hypot(X-XH,Y-YH)/V;
	double b=hypot(XC-XH,YC-YH)/VC;
	if(b<1e-9) return 1;
	if(a<b-1e-9) return 0;
	double L=0,R=b;
	int i;
	FOR(i,200) {
		double M1=(2*L+R)/3;
		double M2=(L+2*R)/3;
		double v1=dist(M1);
		double v2=dist(M2);
		if(v1>1e-9 || v2>1e-9) return 0;
		if(v1<v2) L=M1;
		else R=M2;
	}
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>XH>>YH;
		cin>>XC>>YC>>VC;
		
		string R="YES";
		FOR(i,5) {
			cin>>X>>Y>>V;
			if(ok()==0) R="NO";
		}
		cout<<R<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
