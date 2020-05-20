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

BIT<ll,20> num,sum;

int N,X;
pair<ll,ll> V[202020];
pair<ll,int> W[202020];
int id[202020];
ll ret=-1LL<<60;

void add(int x,int v) { // v=1 or -1
	num.add(id[x],v);
	sum.add(id[x],v*V[x].second);
}

// [L,SL)‚Íbit‚ðset‚µ‚½ó‘Ô‚Å—ˆ‚é
void dfs(int L,int R,int SL,int SR) {
	if(L>=R) return;
	if(SR-L<X) return;
	int M=(L+R)/2;
	
	if(SR-M<X) {
		dfs(L,M,SL,SR);
		return;
	}
	
	int SM=-1;
	ll best=-1LL<<60;
	int i;
	for(i=L;i<M;i++) add(i,-1);
	for(i=SL;i<SR;i++) {
		add(i,1);
		if(num(1<<19)>=X) {
			int y=num.lower_bound(X);
			ll sc=sum(y)-V[i].first+V[M].first;
			if(sc>best) {
				best=sc;
				ret=max(ret,sc);
				SM=i;
			}
		}
	}
	
	for(i=L;i<M;i++) add(i,1);
	for(i=SL;i<SR;i++) add(i,-1);
	dfs(L,M,SL,SM+1);
	
	if(M+1<R) {
		for(i=L;i<=M;i++) add(i,-1);
		for(i=SL;i<SM;i++) add(i,1);
		dfs(M+1,R,SM,SR);
		for(i=SL;i<SM;i++) add(i,-1);
		for(i=L;i<=M;i++) add(i,1);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) {
		cin>>x>>y;
		V[i]={2*y,x};
	}
	sort(V,V+N);
	FOR(i,N) W[i]={-V[i].second,i};
	sort(W,W+N);
	FOR(i,N) id[W[i].second]=i;
	
	dfs(0,N,0,N);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
