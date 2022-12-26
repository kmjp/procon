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

int N,W;
int X[12],Y[12],R[12];
double V[12],A[12];

double dp[1<<12][12];


double tim(double cx,double cy,double S,int tar) {
	double T=S+1e4;
	double now=S;
	while(T-S>1e-6) {
		double M=(S+T)/2;
		double ax=X[tar]+R[tar]*cos(V[tar]*M+A[tar]);
		double ay=Y[tar]+R[tar]*sin(V[tar]*M+A[tar]);
		double l=hypot(ax-cx,ay-cy);
		if(l<=(M-now)*W) T=M;
		else S=M;
	}
	return S;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	double pi=atan(1)*4;
	
	cin>>N>>W;
	int mask;
	FOR(mask,1<<N) FOR(i,N) dp[mask][i]=1e10;
	
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>R[i]>>V[i]>>A[i];
		V[i]*=pi/180;
		A[i]*=pi/180;
		dp[1<<i][i]=tim(0,0,0,i);
	}
	double ret=1e10;
	FOR(mask,1<<N) if(mask) {
		FOR(i,N) if(mask&(1<<i)) {
			double t=dp[mask][i];
			double ax=X[i]+R[i]*cos(V[i]*t+A[i]);
			double ay=Y[i]+R[i]*sin(V[i]*t+A[i]);
			FOR(j,N) if((mask&(1<<j))==0) dp[mask|(1<<j)][j]=min(dp[mask|(1<<j)][j],tim(ax,ay,t,j));
			if(mask==(1<<N)-1) ret=min(ret,dp[mask][i]);
		}
	}
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
