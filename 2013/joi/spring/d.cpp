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

int N,W,H;
int X[101],Y[101];
double eps=1e-9;

int hoge(int a,int b,int c,int d) {
	if(a==b||a==c||a==d||b==c||b==d||c==d) return 0;
	
	ll X1=abs(X[a]-X[b]),Y1=abs(Y[a]-Y[b]);
	ll X2=abs(X[c]-X[d]),Y2=abs(Y[c]-Y[d]);
	ll XD=abs(X[a]-X[c]),YD=abs(Y[a]-Y[c]);
	ll R1=X1*X1+Y1*Y1;
	ll R2=X2*X2+Y2*Y2;
	ll RD=XD*XD+YD*YD;
	if(X[a]*X[a]<R1) return 0;
	if((W-X[a])*(W-X[a])<R1) return 0;
	if(Y[a]*Y[a]<R1) return 0;
	if((H-Y[a])*(H-Y[a])<R1) return 0;
	
	ll RD2=R1-R2-RD;
	if(RD2<0) return 0;
	if(4*R2*RD >= RD2*RD2) return 0;
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W>>H;
	FOR(i,N) cin>>X[i]>>Y[i];
	int ret=0;
	FOR(i,N) FOR(j,N) FOR(x,N) FOR(y,N) {
		ret += hoge(i,j,x,y);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
