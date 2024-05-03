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
double X1[101],Y1[101],X2[101],Y2[101];

double dist(double rx,double ry,double ax,double ay,double bx,double by) { //点と線分の距離
	double ret=min(hypot(rx-ax,ry-ay),hypot(rx-bx,ry-by)); //両端
	//垂線が線分上にない(角度が90度以上)
	if((rx-ax)*(bx-ax)+(ry-ay)*(by-ay)<=0) return ret;
	if((rx-bx)*(ax-bx)+(ry-by)*(ay-by)<=0) return ret;
	double dot=abs((rx-ax)*(by-ay)-(ry-ay)*(bx-ax))/hypot(ax-bx,ay-by);
	return dot;
}




double ok(double rx,double ry) {
	
	double ma=0;
	int i;
	
	FOR(i,N) ma=max(ma,dist(rx,ry,X1[i],Y1[i],X2[i],Y2[i]));
	return ma;
}

double hoge(double Y) {
	double LX=0,RX=1000;
	int i;
	FOR(i,100) {
		double X1=(LX*2+RX)/3;
		double X2=(LX+RX*2)/3;
		double V1=ok(X1,Y);
		double V2=ok(X2,Y);
		if(V1<=V2) RX=X2;
		else LX=X1;
	}
	return ok(LX,Y);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
	
	double LY=0,RY=1000;
	FOR(i,100) {
		double Y1=(LY*2+RY)/3;
		double Y2=(LY+RY*2)/3;
		double V1=hoge(Y1);
		double V2=hoge(Y2);
		if(V1<=V2) RY=Y2;
		else LY=Y1;
	}
	
	_P("%.12lf\n",hoge(LY));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
