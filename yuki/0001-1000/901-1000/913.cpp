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


int N;
ll A[202020];
ll S[202020];
ll ret[202020];
ll cand[202020];

template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		return ((__int128)(C.second-A.second)*(A.first-B.first)<=(__int128)(B.second-A.second)*(A.first-C.first));
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
			(((calc(Q[M],x)>=calc(Q[M+1],x)))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};

void dfs(int L,int R) {
	if(R-L<=2) {
		if(R-L==2) {
			ret[L]=min(ret[L],4+A[L]+A[L+1]);
			ret[L+1]=min(ret[L+1],4+A[L]+A[L+1]);
		}
		return;
	}
	int M=(L+R)/2;
	dfs(L,M);
	dfs(M+1,R);
	int i;
	ConvexHull<ll> ch;
	for(i=L;i<=M;i++) cand[i]=1LL<<60;
	for(i=M+1;i<=R;i++) {
		ch.add(-2*i,1LL*i*i+S[i]);
	}
	for(i=M;i>=L;i--) {
		cand[i]=1LL*i*i-S[i]+ch.query(i);
	}
	for(i=L;i<=M;i++) {
		cand[i+1]=min(cand[i+1],cand[i]);
		ret[i]=min(ret[i],cand[i]);
	}
	ch.Q.clear();
	for(i=M;i<=R;i++) cand[i]=1LL<<60;
	for(i=L;i<=M;i++) {
		ch.add(-2*i,1LL*i*i-S[i]);
	}
	for(i=M;i<R;i++) {
		cand[i]=1LL*(i+1)*(i+1)+S[i+1]+ch.query(i+1);
	}
	for(i=R-1;i>=M;i--) {
		cand[i-1]=min(cand[i],cand[i-1]);
		ret[i]=min(ret[i],cand[i]);
	}
	
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
		ret[i]=1+A[i];
	}
	
	dfs(0,N);
	FOR(i,N) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
