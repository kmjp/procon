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


typedef complex<long double> Po;

struct Line {
	Po a,b;
	Line(){};
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
	long double aa=ld.real()*rd.imag()-ld.imag()*rd.real();
	long double bb=ld.real()*d3.imag()-ld.imag()*d3.real();
	if(abs(aa)<1e-16 && abs(bb)<1e-16) return Po(1e9,-1e9); //same
	if(abs(aa)<1e-12) return Po(1e9,1e9); //parallel
	return r.a+bb/aa*(r.b-r.a);
};

int N;
ll X1[1010],X2[1010],Y1[1010],Y2[1010];
int val[1010];
Line L[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
		L[i]=Line(Po(X1[i],Y1[i]),Po(X2[i],Y2[i]));
	}
	
	
	int ret=1;
	FOR(y,N) {
		int add=1;
		set<pair<long double,long double>> P;
		FOR(x,y) {
			Po p=CrossPoint(L[x],L[y]);
			
			if(p.real()==1e9 && p.imag()==-1e9) {
				add=0;
				break;
			}
			if(p.real()!=1e9 || p.imag()!=1e9) {
				
				long double X=round(p.real()*1e8);
				long double Y=round(p.imag()*1e8);
				add+=1-P.count({X,Y});
				P.insert({X,Y});
			}
		}
		ret+=add;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
