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


double X[5],Y[5];
double T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X[0]>>Y[0]>>T;
	FOR(i,4) cin>>X[i+1]>>Y[i+1];
	
	double dif=atan2(Y[4]-Y[3],X[4]-X[3])-atan2(Y[2]-Y[1],X[2]-X[1]);
	
	double xx=X[3]+cos(dif)*(X[0]-X[1])-sin(dif)*(Y[0]-Y[1]);
	double yy=Y[3]+sin(dif)*(X[0]-X[1])+cos(dif)*(Y[0]-Y[1]);
	double x2=X[0]+cos(-dif)*(X[0]-xx)-sin(-dif)*(Y[0]-yy);
	double y2=Y[0]+sin(-dif)*(X[0]-xx)+cos(-dif)*(Y[0]-yy);
	
	double a=fmod(360+T-dif*180/(atan(1)*4),360);
	_P("%.12lf %.12lf %.12lf\n",x2,y2,a);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
