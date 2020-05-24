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

const int MAT=2008;
struct Mat { ll v[MAT]; Mat(){ZERO(v);};};

const ll mo=1000000007;

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	ll mo2=4*mo*mo;
	int x,y,z; 
	static Mat r;
	FOR(x,n) r.v[x]=0;
	r.v[0]=0;
	FOR(x,n) FOR(y,n) {
		if(y-x<0) continue;
		(r.v[y]+=a.v[y-x]*b.v[x])%=mo;
	}
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y;
	static Mat r;
	FOR(x,n) r.v[x]=0;
	r.v[0]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

int N,X;
ll D;
Mat A;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	while(scanf("%d%lld%d",&N,&D,&X)==3) {
		if(N==0) break;
		ZERO(A.v);
		for(y=0;y<=min(N,X-1);y++) A.v[y]=1;
		A=powmat(D,A,N+1);
		cout<<A.v[N]<<endl;
	
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
