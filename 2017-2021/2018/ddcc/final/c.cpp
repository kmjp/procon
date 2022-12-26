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

double LX[11],LY[11];
double RX[11],RY[11];
double PX,PY,PR,SX,SY;
int K;

double angle(double ax,double ay,double bx,double by) {
	double ret=atan2(by,bx)-atan2(ay,ax);
	ret/=8*atan(1);
	if(ret<0) ret+=1;
	return ret;
}

pair<double,double> hoge(double X,double Y,int dir) {
	double r=hypot(X-PX,Y-PY);
	double deg=atan2(PY-Y,PX-X)+dir*asin(PR/r);
	double dx=cos(deg);
	double dy=sin(deg);
	
	int i;
	double di=2;
	FOR(i,100) {
		double nx=X+di*dx;
		double ny=Y+di*dy;
		if(ny*ny+nx*nx<=1) {
			X=nx;
			Y=ny;
		}
		di/=2;
	}
	
	return {X,Y};
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>PX>>PY>>PR;
	cin>>SX>>SY>>K;
	
	auto a=hoge(SX,SY,1);
	LX[0]=a.first,LY[0]=a.second;
	a=hoge(SX,SY,-1);
	RX[0]=a.first,RY[0]=a.second;
	
	
	double ret=angle(LX[0],LY[0],RX[0],RY[0]);
	_P("%.12lf\n",min(1.0,ret));
	FOR(i,K) {
		a=hoge(LX[i],LY[i],1);
		LX[i+1]=a.first,LY[i+1]=a.second;
		a=hoge(RX[i],RY[i],-1);
		RX[i+1]=a.first,RY[i+1]=a.second;
		ret+=angle(LX[i+1],LY[i+1],LX[i],LY[i]);
		ret+=angle(RX[i],RY[i],RX[i+1],RY[i+1]);
		_P("%.12lf\n",min(1.0,ret));
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
