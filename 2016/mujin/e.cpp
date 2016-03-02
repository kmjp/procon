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


typedef complex<double> Po;
struct Line {
	Po a,b;
	Line(const Po &a,const Po &b) : a(a),b(b){Rep();};
	void Rep(){
		// assert(a!=b);
		if(a.real()==b.real()) { a.imag(0);b.imag(1); return;} // Y-axis
		Po c,d;
		d.real(1);
		d.imag((b.imag()-a.imag())/(b.real()-a.real()));
		c.imag(b.imag()-b.real()*d.imag());
		d.imag(d.imag()+c.imag());
		a=c; b=d;
	};
};


Po CrossPoint(const Line &l,const Line &r) {
	Po p,ld=l.b-l.a,rd=r.b-r.a,d3=l.b-r.a;
	double aa=ld.real()*rd.imag()-ld.imag()*rd.real();
	double bb=ld.real()*d3.imag()-ld.imag()*d3.real();
	if(abs(aa)<1e-9 && abs(bb)<1e-9) return Po(1e9,-1e9); //same
	if(abs(aa)<1e-9) return Po(1e9,1e9); //parallel
	return r.a+bb/aa*(r.b-r.a);
};

ll X[7],Y[7];

void solve() {
	int i,j,k,l,x,y; string s;
	
	FOR(i,6) cin>>X[i]>>Y[i];
	X[6]=X[0],Y[6]=Y[0];
	
	FOR(i,3) {
		ll dx1=X[i+1]-X[i];
		ll dy1=Y[i+1]-Y[i];
		ll dx2=X[i+4]-X[i+3];
		ll dy2=Y[i+4]-Y[i+3];
		if(dx1*dy2-dx2*dy1!=0) return _P("-1\n");
	}
	
	Line L1(Po(X[0],Y[0]),Po(X[1],Y[1]));
	Line L2(Po(X[2],Y[2]),Po(X[3],Y[3]));
	Line L3(Po(X[4],Y[4]),Po(X[5],Y[5]));
	Po P=CrossPoint(L1,L2);
	Po Q=CrossPoint(L2,L3);
	Po R=CrossPoint(L1,L3);
	double PQ=norm(P-Q);
	double QR=norm(Q-R);
	double RP=norm(R-P);
	
	if(PQ+QR-1e-8<RP) return _P("-1\n");
	if(PQ+RP-1e-8<QR) return _P("-1\n");
	if(QR+RP-1e-8<PQ) return _P("-1\n");
	
	double A = sqrt((PQ+RP-QR)/2);
	double B = sqrt((PQ+QR-RP)/2);
	double C = sqrt((QR+RP-PQ)/2);
	double V=A*B*C;
	V *= abs(Po(X[0],Y[0])-P)/abs(R-P);
	V *= abs(Po(X[1],Y[1])-R)/abs(R-P);
	V *= abs(Po(X[3],Y[3])-P)/abs(Q-P);
	_P("%.12lf\n",V);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
