#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N,EX,EY,SX,SY;
int GX[21],GY[21];

#include<complex>
typedef complex<double> Po;

struct Line {
	Po a,b;
	Line(const Po &a,const Po &b) : a(a),b(b){Rep();};
	static Line PerBis(const Po &a,const Po &b) {
		Po c,d;
		if(a==b) return Line(0,0);
		c.real() = (a.real()+b.real())/2; c.imag() = (a.imag()+b.imag())/2;
		d.real() = c.real()+(b.imag()-c.imag());
		d.imag() = c.imag()-(b.real()-c.real());
		return Line(c,d);
	}; // perpendicular bisector
	void Rep(){
		// assert(a!=b);
		if(a.real()==b.real()) { a.imag()=0;b.imag()=1; return;} // Y-axis
		Po c,d;
		d.real()=1;
		d.imag()=(b.imag()-a.imag())/(b.real()-a.real());
		d.imag()+=c.imag()=b.imag()-b.real()*d.imag();
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

struct Circle {
	Po c;
	double r;
	Circle(const Po &c,double r) : c(c),r(r){};
};

vector<Po> CrossPoint(const Circle &c,const Line &l) {
	Po aa=c.c-l.a, bb=(l.b-l.a)/abs(l.b-l.a);
	double dist=aa.real()*bb.real()+aa.imag()*bb.imag();
	vector<Po> tt;
	aa=-(aa-dist*bb);
	if(abs(c.r-abs(aa))<1e-9) {
		tt.push_back(c.c + aa);
		return tt;
	}
	if(abs(aa)>c.r) return tt;
	tt.push_back(c.c + aa + sqrt(c.r*c.r-norm(aa))*bb);
	tt.push_back(c.c + aa - sqrt(c.r*c.r-norm(aa))*bb);
	return tt;
}

vector<Line> lines;
vector<pair<int,int> > lb;

double mc[420][420];
double cpa[420][420];
pair<double,double> bp[420];
Po ppo[420];
Po cpp[420][420];

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>EX>>EY>>SX>>SY;
	SX-=EX; SY-=EY;
	FOR(i,N) {
		cin>>GX[i]>>GY[i];
		GX[i]-=EX; GY[i]-=EY;
		ppo[i].real()=GX[i];
		ppo[i].imag()=GY[i];
	}
	if(SX*SX+SY*SY<=100*100 || N==0) return _P("%.12lf\n",sqrt(SX*SX+SY*SY));
	
	// enum lines
	FOR(x,N) for(y=x+1;y<N;y++) lines.push_back(Line::PerBis(Po(GX[x],GY[x]),Po(GX[y],GY[y]))),lb.push_back(make_pair(x,y));
	FOR(x,404) FOR(y,404) mc[x][y]=1e9, cpp[x][y]=Po(1e9,1e9);
	
	multimap<double, pair<int,int> > S;
	Circle c1(Po(0,0),50.0),c2(Po(SX,SY),50.0);
	
	FOR(x,lines.size()) {
		vector<double> bpl;
		bpl.push_back(-1e9);
		bpl.push_back(1e9);
		
		// enum cross point
		FOR(y,lines.size()) {
			Po p = CrossPoint(lines[x],lines[y]);
			cpp[x][y]=p;
			if(p.real()>=1e9-1) continue;
			if(lines[x].a.real() == lines[x].b.real()) cpa[x][y]=p.imag();
			else cpa[x][y]=p.real();
			bpl.push_back(cpa[x][y]);
		}
		
		sort(bpl.begin(),bpl.end());
		bp[x].first=1e9;
		bp[x].second=-1e9;
		
		FOR(y,bpl.size()-1) {
			Po pp;
			if(lines[x].a.real() == lines[x].b.real()) {
				pp.real()=lines[x].a.real();
				pp.imag()=(bpl[y]+bpl[y+1])/2.0;
			}
			else {
				pp.real()=(bpl[y]+bpl[y+1])/2.0;
				pp.imag()=lines[x].a.imag() + pp.real()*(lines[x].b.imag()-lines[x].a.imag());
			}
			
			int ng=-1;
			double cl=abs(pp-ppo[lb[x].first]);
			FOR(i,N) {
				if(i==lb[x].first) continue;
				if(i==lb[x].second) continue;
				if(abs(pp-ppo[i])<cl-1e-9) ng=i;
			}
			if(ng==-1) {
				bp[x].first=min(bp[x].first,bpl[y]);
				bp[x].second=max(bp[x].second,bpl[y+1]);
			}
		}
		
		// enum cross point with circle
		vector<Po> p = CrossPoint(c1,lines[x]);
		FOR(i,p.size()) {
			if(lines[x].a.real() == lines[x].b.real()) cpa[400+i][x] = p[i].imag();
			else cpa[400+i][x] = p[i].real();
			
			if(cpa[400+i][x]>=bp[x].first-1e-9 && cpa[400+i][x]<=bp[x].second+1e-9) {
				S.insert(make_pair(50,make_pair(400+i,x)));
				mc[400+i][x]=50;
				cpp[400+i][x]=p[i];
			}
		}
		p = CrossPoint(c2,lines[x]);
		FOR(i,p.size()) {
			if(lines[x].a.real() == lines[x].b.real()) cpa[x][402+i] = p[i].imag();
			else cpa[x][402+i] = p[i].real();
			if(cpa[x][402+i]>=bp[x].first-1e-9 && cpa[x][402+i]<=bp[x].second+1e-9) {
				cpp[x][402+i]=p[i];
			}
			
		}
	}
	
	double res=1e9;
	while(!S.empty() && S.begin()->first<10001) {
		double cost = S.begin()->first;
		int cpf = S.begin()->second.first;
		int cpt = S.begin()->second.second;
		S.erase(S.begin());
		if(cost>mc[cpf][cpt]) continue;
		//_P("%lf %d %d %lf %lf\n",cost,cpf,cpt,cpp[cpf][cpt].real(),cpp[cpf][cpt].imag());
		
		FOR(i,lines.size()+2) {
			x=i;
			if(i>=lines.size()) x=402+(i-lines.size());
			Po cp=cpp[cpt][x];
			if(cost+abs(cpp[cpt][x]-cpp[cpf][cpt])>10001) continue;
			if(cost+abs(cpp[cpt][x]-cpp[cpf][cpt])>=mc[cpt][x]) continue;
			
			double popo=cpp[cpt][x].real();
			if(lines[cpt].a.real()==lines[cpt].b.real()) popo=cpp[cpt][x].imag();
			if(popo<bp[cpt].first-1e-9 || popo>bp[cpt].second+1e-9) continue;
			
			if(x<400) {
				popo=cpp[cpt][x].real();
				if(lines[x].a.real()==lines[x].b.real()) popo=cpp[cpt][x].imag();
				if(popo<bp[x].first-1e-9 || popo>bp[x].second+1e-9) continue;
			}
			
			
			//_P("++cost:%lf,%lf,%d\n",cost,abs(cpp[cpt][x]-cpp[cpf][cpt]),x);
			mc[cpt][x]=cost+abs(cpp[cpt][x]-cpp[cpf][cpt]);
			if(x>=402) res=min(res,mc[cpt][x]+50);
			else S.insert(make_pair(mc[cpt][x],make_pair(cpt,x)));
		}
		
	}
	if(res<10000) return _P("%.12lf\n",res);
	_P("impossible\n");
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


