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
int H,W;

template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	int cmptype=0; // 0-min 1-max
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		return cmptype^((B.second-C.second)*(B.first-A.first)<=(A.second-B.second)*(C.first-B.first));
	}
	void add(V a, V b) { // add ax+b
		Q.push_back({a,b});
		int v;
		while((v=Q.size())>=3 && dodo(Q[v-3],Q[v-2],Q[v-1]))
			Q[v-2]=Q[v-1], Q.pop_back();
	}
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			(cmptype^((calc(Q[M],x)<=calc(Q[M+1],x)))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};

ll A[101][10101];
ll C[101][10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ConvexHull<ll> chr,chl;
	
	cin>>H>>W;
	FOR(y,H) {
		
		FOR(x,W) cin>>A[y][x], C[y][x]=A[y][x];
		ConvexHull<ll> chr,chl;
		FOR(x,W) {
			if(x) C[y][x]=min(C[y][x],chl.query(x)+x*x);
			chl.add(-2*x,A[y][x]+x*x);
			if(x) C[y][W-1-x]=min(C[y][W-1-x],chr.query(x)+x*x);
			chr.add(-2*x,A[y][W-1-x]+x*x);
		}
	}
	
	ll mi=1LL<<60;
	FOR(x,W) {
		ll tot=0;
		FOR(y,H) tot+=C[y][x];
		mi=min(mi,tot);
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
