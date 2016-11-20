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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	V set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};

int N,Q;
ll A,B;
BIT<ll,18> bit;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	bit.add(N,2LL*10000000000001LL);
	FOR(i,Q) {
		cin>>A>>B;
		x=N-A;
		while(B) {
			ll xv=bit.total(x);
			y = bit.lower_bound(xv+1);
			ll yv=bit.total(y);
			
			
			if(B>=(yv-xv)*(y-x)) {
				B -= (yv-xv)*(y-x);
				bit.add(x,yv-xv);
				bit.add(y,-(yv-xv));
			}
			else {
				bit.add(x,B/(y-x));
				bit.add(y,-B/(y-x));
				B %= (y-x);
				bit.add(y-B,1);
				bit.add(y,-1);
				break;
			}
		}
	}
	
	FOR(i,N) cout<<bit.total(N-1-i)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
