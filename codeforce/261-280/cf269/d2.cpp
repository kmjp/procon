#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,W;
ll A[300000],B[300000];
ll D[300000],E[300000];

ll mo1=999999937,mo2=1000000009;
ll d1,d2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W;
	FOR(i,N) cin>>A[i];
	FOR(i,W) cin>>B[i];
	N--;W--;
	FOR(i,N) D[i]=A[i+1]-A[i];
	FOR(i,W) E[i]=B[i+1]-B[i];
	ll ha1=0,ha2=0;
	d1=d2=1;
	ll m1=10009,m2=10007;
	ll a1=1000000000+10007,a2=1000000000+3333331;
	
	if(N<W) return _P("0\n");
	if(W==0) return _P("%d\n",N+1);
	
	FOR(i,W) {
		ha1=(ha1*m1+E[i]+a1)%mo1;
		ha2=(ha2*m2+E[i]+a2)%mo2;
		d1=d1*m1%mo1;
		d2=d2*m2%mo2;
	}
	
	
	ll c1=0,c2=0;
	int ret=0,t=0;
	FOR(i,N) {
		c1=(c1*m1+D[i]+a1)%mo1;
		c2=(c2*m2+D[i]+a2)%mo2;
		t++;
		if(t>=W+1) {
			c1-=d1*(D[i-W]+a1)%mo1;
			c2-=d2*(D[i-W]+a2)%mo2;
			if(c1<0) c1+=mo1;
			if(c2<0) c2+=mo2;
		}
		if(t>=W && c1==ha1 &&c2==ha2) {
			ret++;
			/*i++;
			t=0;
			c1=c2=0;*/
		}
	}
	cout << ret << endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
