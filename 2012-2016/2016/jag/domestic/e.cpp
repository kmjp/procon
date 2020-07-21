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

int cross(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4) {
	const double EPS=1e-8;
	double XX[3],YY[3];
	XX[0]=x2-x1; YY[0]=y2-y1;
	XX[1]=x3-x1; YY[1]=y3-y1;
	XX[2]=x4-x1; YY[2]=y4-y1;
	double c1=XX[0]*YY[1]-XX[1]*YY[0];
	double c2=XX[0]*YY[2]-XX[2]*YY[0];
	if((c1<EPS&&c2<EPS)||(c1>-EPS&&c2>-EPS)) return 0;
	XX[0]=x4-x3; YY[0]=y4-y3;
	XX[1]=x1-x3; YY[1]=y1-y3;
	XX[2]=x2-x3; YY[2]=y2-y3;
	c1=XX[0]*YY[1]-XX[1]*YY[0];
	c2=XX[0]*YY[2]-XX[2]*YY[0];
	if((c1<EPS&&c2<EPS)||(c1>-EPS&&c2>-EPS)) return 0;
	return 1;
}

int N,M;
vector<pair<int,int>> P[10];
int X[10],Y[10];
vector<pair<int,int>> cand;
vector<pair<double,double>> PC;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>r;
		FOR(j,r) {
			cin>>x>>y;
			P[i].push_back({x,y});
			cand.push_back({x,y});
			PC.push_back({x,y});
		}
		P[i].push_back(P[i][0]);
	}
	FOR(i,M) {
		cin>>X[i]>>Y[i];
		PC.push_back({X[i],Y[i]});
	}
	
	
	FOR(x,M) FOR(y,M) if(x!=y) {
		FORR(a,cand) FORR(b,cand) if(a!=b) {
			Line la(Po(X[x],Y[x]),Po(a.first,a.second));
			Line lb(Po(X[y],Y[y]),Po(b.first,b.second));
			auto pp=CrossPoint(la,lb);
			if(pp.real()==1e9) continue;
			PC.push_back({pp.real(),pp.imag()});
			
		}
	}
	int ret=0;
	FORR(p,PC) {
		int num=0;
		FOR(i,M) {
			int ok=1;
			FOR(j,N) {
				FOR(r,P[j].size()-1) {
					if(cross(X[i],Y[i],p.first,p.second,P[j][r].first,P[j][r].second,P[j][r+1].first,P[j][r+1].second)) {
						ok=0;
					}
				}
			}
			num+=ok;
		}
		ret=max(ret,num);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
