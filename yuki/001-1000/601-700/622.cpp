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

double X[4],Y[4],Z[4];

void solve() {
	int i,j,k,l,x,y; string s;
	
	FOR(i,4) cin>>X[i]>>Y[i]>>Z[i];
	for(i=3;i>=0;i--) X[i]-=X[0],Y[i]-=Y[0],Z[i]-=Z[0];
	
	double PX=Y[1]*Z[2]-Z[1]*Y[2];
	double PY=Z[1]*X[2]-X[1]*Z[2];
	double PZ=X[1]*Y[2]-Y[1]*X[2];
	
	double r=sqrt(PX*PX+PY*PY+PZ*PZ);
	PX/=r;
	PY/=r;
	PZ/=r;
	
	double d=PX*X[3]+PY*Y[3]+PZ*Z[3];
	X[3]-=d*PX;
	Y[3]-=d*PY;
	Z[3]-=d*PZ;
	
	int A[3]={};
	FOR(i,3) {
		double ax=X[(i+1)%3]-X[i];
		double ay=Y[(i+1)%3]-Y[i];
		double az=Z[(i+1)%3]-Z[i];
		double bx=X[3]-X[i];
		double by=Y[3]-Y[i];
		double bz=Z[3]-Z[i];
		
		double cx=ay*bz-az*by;
		double cy=az*bx-ax*bz;
		double cz=ax*by-ay*bx;
		
		if(cx<0) A[i]++;
		if(cy<0) A[i]++;
		if(cz<0) A[i]++;
		
	}
	
	if(A[0]==A[1] && A[0]==A[2]) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
