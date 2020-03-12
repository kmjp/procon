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
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<ll,19> bt;

int N;
ll A[101010],B[101010],SA;
pair<ll,int> P[101010];
ll p,q=1;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		SA+=A[i];
		P[i]={-max(A[i],B[i]),i};
	}
	sort(P,P+N);
	
	FOR(i,N) {
		bt.add(i+1,-P[i].first);
	}
	FOR(i,N) {
		bt.add(i+1,P[i].first);
		ll t=SA-B[P[i].second];
		x=bt.lower_bound(t);
		if(x<N) {
			ll lef=SA-bt(x);
			if(lef<=B[P[i].second] && lef>=0) {
				if(x>i) x--;
				
				ll tq=B[P[i].second];
				//cout<<i<<" "<<x<<" "<<1.0*lef/tq<<endl;
				ll tp=(N-x)*tq-lef;
				tq*=N;
				ll g=__gcd(tp,tq);
				tp/=g;
				tq/=g;
				//cout<<tp<<" "<<tq<<" "<<1.0*tp/tq<<endl;
				if((__int128_t)tp*q>(__int128_t)p*tq) p=tp,q=tq;
			}
		}
		
		bt.add(i+1,-P[i].first);
	}
	cout<<p<<" "<<q<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
