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

string D;
int N;
int ND[10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D;
	N=D.size();
	FORR(r,D) r-='0';
	
	set<int> difs;
	FOR(i,N-1) difs.insert(D[i+1]-D[i]+((D[i+1]<D[i])?10:0));
	if(difs.size()<=1) return _P("%d\n",D[0]);
	int dif = *difs.begin();
	if(dif==0 && difs.count(9)==1) dif=9;
	
	ND[0]=D[0];
	for(i=1;i<N;i++) {
		x = (D[i]==(D[i-1]+dif+1)%10);
		if(D[i]!=(D[i-1]+dif+x)%10) return _P("-1\n");
		ND[i]=ND[i-1]+dif+x;
	}
	
	double ma_ax=1010;
	double mi_ax=-1;
	FOR(y,N) FOR(x,y) {
		mi_ax=max(mi_ax,(ND[y]-ND[x]-(1.0-1e-9))/(y-x));
		ma_ax=min(ma_ax,(ND[y]-ND[x]+(1.0-1e-9))/(y-x));
	}
	if(mi_ax>ma_ax-1e-10) return _P("-1\n");
	
	ll p10=1;
	for(;;p10*=10) {
		ll maax_i = floor(ma_ax*p10);
		ll miax_i = ceil(mi_ax*p10);
		if(miax_i <= maax_i) {
			ll b=0;
			FOR(i,N) b=max(b,ND[i]*p10-maax_i*i);
			cout<<b<<endl;
			return;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
