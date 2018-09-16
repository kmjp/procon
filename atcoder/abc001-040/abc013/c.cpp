#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

ll N,H,A,B,C,D,E;

void solve() {
	int f,i,j,k,l,x,y;
	ll mi=1LL<<60;
	
	cin>>N>>H>>A>>B>>C>>D>>E;
	ll xx;
	
	for(xx=0;xx<=N;xx++) {
		ll le=N-xx;
		ll HH=H+B*xx;
		ll AA=D+E;
		ll BB=le*E-HH;
		ll yy=max(0LL,BB/(D+E)+1);
		if(BB<0) yy=0;
		
		//_P("%lld %lld  %lld\n",xx,yy,xx*A+yy*C);
		mi=min(mi,xx*A+yy*C);
	}
	cout << mi << endl;
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


