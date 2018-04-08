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

int T,testcase;
double A;


vector<double> rotz(vector<double> V,double d) {
	double s=sin(d),c=cos(d);
	vector<double> R(3);
	R[0]=c*V[0]-s*V[1];
	R[1]=s*V[0]+c*V[1];
	R[2]=V[2];
	return R;
}
vector<double> rotx(vector<double> V,double d) {
	double s=sin(d),c=cos(d);
	vector<double> R(3);
	R[0]=V[0];
	R[1]=c*V[1]-s*V[2];
	R[2]=s*V[1]+c*V[2];
	return R;
}

double sqarea(vector<double> A,vector<double> B,vector<double> C) {
	int i;
	FOR(i,3) B[i]-=A[i], C[i]-=A[i];
	B[1]=C[1]=0;
	double X=B[1]*C[2]-B[2]*C[1];
	double Y=B[2]*C[0]-B[0]*C[2];
	double Z=B[0]*C[1]-B[1]*C[0];
	return sqrt(X*X+Y*Y+Z*Z);
}

double area(double rz,double rx) {
	vector<vector<double>> D={
		{0.5,0.5,0.5},
		{-0.5,0.5,0.5},
		{-0.5,-0.5,0.5},
		{0.5,-0.5,0.5},
		{0.5,0.5,-0.5},
		{-0.5,0.5,-0.5},
		{-0.5,-0.5,-0.5},
		{0.5,-0.5,-0.5}
	};
	FORR(d,D) d=rotx(rotz(d,rz),rx);
	vector<vector<int>> F={
		{0,1,2,3},
		{4,5,6,7},
		{0,1,5,4},
		{1,2,6,5},
		{2,3,7,6},
		{3,0,4,7},
	};
	double A=0;
	FORR(f,F) A+=sqarea(D[f[0]],D[f[1]],D[f[3]]);
	return A/2;
}

void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	double pi=atan(1)*4;
	cin>>A;
	double rx=0,rz=0;
	if(A<=sqrt(2)) {
		double L=0,R=pi/4;
		FOR(i,200) {
			double M=(L+R)/2;
			if(area(M,0)<=A) L=M;
			else R=M;
		}
		rz=L;
	}
	else {
		rz=pi/4;
		double L=0,R=atan2(1,sqrt(2));
		FOR(i,200) {
			double M=(L+R)/2;
			if(area(rz,M)<=A) L=M;
			else R=M;
		}
		rx=L;
	}
	vector<vector<double>> D={
		{0.5,0,0},
		{0,0.5,0},
		{0,0,0.5},
	};
	
	_P("Case #%d:\n", TC);
	FORR(d,D) {
		d=rotx(rotz(d,rz),rx);
		_P("%.10lf %.10lf %.10lf\n",d[0],d[1],d[2]);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
