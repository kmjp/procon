#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
	V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void update(int e, V val) {e++; while(e<=1<<ME) bit[e-1]+=val,e+=e&-e;}
};
BIT<ll,20> Lbt;
BIT<ll,20> Rbt;


int N,N2,Q;
string X[30000];
int Y[30000],Z[30000];

ll momo(ll a) { return (a%N2+N2)%N2;}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	N2=2*N;
	FOR(i,Q) {
		cin>>X[i]>>Y[i]>>Z[i];
		if(X[i][0]=='L') {
			Lbt.update(1+momo(Y[i]+i+1),Z[i]);
		}
		if(X[i][0]=='R') {
			Rbt.update(1+momo(Y[i]-(i+1)),Z[i]);
		}
		if(X[i][0]=='C') {
			Z[i]--;
			ll ret=0;
			x=momo(Y[i]+(i+1));
			y=momo(Z[i]+(i+1));
			if(x<=y) ret +=Lbt.total(y+1)-Lbt.total(x);
			else ret +=Lbt.total(N2+2)-Lbt.total(x) + Lbt.total(y+1);
			
			x=momo(N2-1-Z[i]+(i+1));
			y=momo(N2-1-Y[i]+(i+1));
			if(x<=y) ret +=Lbt.total(y+1)-Lbt.total(x);
			else ret +=Lbt.total(N2+2)-Lbt.total(x) + Lbt.total(y+1);
			
			x=momo(Y[i]-(i+1));
			y=momo(Z[i]-(i+1));
			if(x<=y) ret +=Rbt.total(y+1)-Rbt.total(x);
			else ret +=Rbt.total(N2+2)-Rbt.total(x) + Rbt.total(y+1);
			
			x=momo(N2-1-Z[i]-(i+1));
			y=momo(N2-1-Y[i]-(i+1));
			if(x<=y) ret +=Rbt.total(y+1)-Rbt.total(x);
			else ret +=Rbt.total(N2+2)-Rbt.total(x) + Rbt.total(y+1);
			
			cout<<ret<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
