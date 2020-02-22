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

int N,K;
ll A[202020];
ll S[202020];
vector<ll> V;

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

BIT<int,20> bit;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	V.push_back(-1LL<<60);
	V.push_back(0);
	FOR(i,N) {
		cin>>A[i];
		A[i]-=K;
		S[i+1]=S[i]+A[i];
		V.push_back(S[i+1]);
	}
	sort(ALL(V));
	ll ret=0;
	int added=0;
	for(i=N-1;i>=0;i--) {
		x=lower_bound(ALL(V),S[i+1])-V.begin();
		added++;
		bit.add(x,1);
		y=lower_bound(ALL(V),S[i])-V.begin();
		ret += added-bit.total(y-1);
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
