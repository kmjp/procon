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

int A[2],B[2],C[2];
double memo[11][11][11][11][11][11];

double hoge(int a1,int a2,int b1,int b2,int c1,int c2) {
	if(a1+a2+b1+b2+c1+c2==0) return 0;
	if(memo[a1][a2][b1][b2][c1][c2]>-1000000) return memo[a1][a2][b1][b2][c1][c2];
	
	double ma=-101010101;
	if(a1+a2>0) {
		double pat;
		if(a1==0) pat=50-hoge(a1,a2-1,b1,b2,c1,c2);
		if(a2==0) pat=100-hoge(a1-1,a2,b1,b2,c1,c2);
		if(a1&&a2) pat=((100-hoge(a1-1,a2,b1,b2,c1,c2))*a1+(50-hoge(a1,a2-1,b1,b2,c1,c2))*a2)/(a1+a2);
		ma=max(ma,pat);
	}
	if(b1+b2>0) {
		double pat;
		if(b1==0) pat=50-hoge(a1,a2,b1,b2-1,c1,c2);
		if(b2==0) pat=100-hoge(a1,a2,b1-1,b2,c1,c2);
		if(b1&&b2) pat=((100-hoge(a1,a2,b1-1,b2,c1,c2))*b1+(50-hoge(a1,a2,b1,b2-1,c1,c2))*b2)/(b1+b2);
		ma=max(ma,pat);
	}
	if(c1+c2>0) {
		double pat;
		if(c1==0) pat=50-hoge(a1,a2,b1,b2,c1,c2-1);
		if(c2==0) pat=100-hoge(a1,a2,b1,b2,c1-1,c2);
		if(c1&&c2) pat=((100-hoge(a1,a2,b1,b2,c1-1,c2))*c1+(50-hoge(a1,a2,b1,b2,c1,c2-1))*c2)/(c1+c2);
		ma=max(ma,pat);
	}
	
	return memo[a1][a2][b1][b2][c1][c2]=ma;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A[0]>>A[1];
	cin>>B[0]>>B[1];
	cin>>C[0]>>C[1];
	
	int D[6];
	FOR(D[0],11)
	FOR(D[1],11)
	FOR(D[2],11)
	FOR(D[3],11)
	FOR(D[4],11)
	FOR(D[5],11) memo[D[0]][D[1]][D[2]][D[3]][D[4]][D[5]]=-10101010;
	
	double sum=A[0]*100+A[1]*50+B[0]*100+B[1]*50+C[0]*100+C[1]*50;
	double ret=hoge(A[0],A[1],B[0],B[1],C[0],C[1]);
	_P("%.12lf\n",sum-(sum-ret)/2);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
