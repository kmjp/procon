#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

const int MAT=36;
struct Mat { int v[MAT][MAT]; };
Mat mulmat_gf2(Mat& a,Mat& b,int n=MAT) {
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) r.v[x][y] ^= a.v[x][z]&b.v[z][y];
	return r;
}

Mat powmat_gf2(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=x==y;
	while(p) {
		if(p%2) r=mulmat_gf2(r,a,n);
		a=mulmat_gf2(a,a,n);
		p>>=1;
	}
	return r;
}

ll A,B,X;
Mat BM,BMH;
ll BMH2[36];
map<ll,int> M;

ll getval(Mat m,ll v) {
	ll ret=0;
	int i,x;
	FOR(i,36) FOR(x,36) if(m.v[i][x] && (v&(1LL<<x))) ret ^= 1LL<<i;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>X;
	
	ll T=A;
	FOR(i,1<<18) {
		if(A==X) return _P("%d\n",i);
		A=(A/2)^(A%2*B);
	}
	if(B<1<<18) return _P("-1\n");
	
	ll X2=X;
	FOR(i,1<<18) {
		if(M.count(X2)==0) M[X2]=i;
		X2=(X2/2)^(X2%2*B);
	}
	
	FOR(i,35) BM.v[i][i+1]=1;
	FOR(i,36) BM.v[i][0]=(B>>i)&1;
	BMH=powmat_gf2(1<<18,BM);
	FOR(i,36) FOR(x,36) if(BMH.v[i][x]) BMH2[i] |= 1LL<<x;
	
	ll A2=A;
	FOR(i,1<<18) {
		if(M.count(A2)) {
			ll t=(1LL<<18)*i-M[A2];
			if(t>=0 && X==getval(powmat_gf2(t,BM),A)) return _P("%lld\n",t+(1<<18));
		}
		ll A3=0;
		FOR(x,36) A3 |= (__builtin_popcountll(BMH2[x]&A2)&1LL)<<x;
		A2=A3;
	}
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
