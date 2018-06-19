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

template<typename V> struct ConvexHullOnline {
	const V inf=1LL<<40+1;
	const int cmptype=1; // 0-max 1-min
	map<V,V> Q,PR; // Q[a]=b -> a*x+b, P[a]=c ax+b is best unti x<=c PR[c]=a
	unordered_map<V,V> P;
	ConvexHullOnline() { Q[inf]=-inf*inf; Q[-inf]=inf*inf;}
	int ok(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		if(A.first==-inf && C.first==inf) return 1;
		return ((__int128_t)(B.second-A.second)*(B.first-C.first)<=(__int128)(C.second-B.second)*(A.first-B.first));
	}
	bool bad(typename map<V,V>::iterator it) {
		if(it==Q.begin() || next(it)==Q.end() || next(it)->first==inf || prev(it)->first==-inf) return false;
		return ok(*prev(it),*it,*next(it))==0;
	}
	void erase(typename map<V,V>::iterator it) { PR.erase(P[it->first]); P.erase(it->first); Q.erase(it);}
	void update(typename map<V,V>::iterator it) {
		if(next(it)==Q.end() || it==Q.begin()) return;
		auto it2=next(it);
		if(it2->first==inf) {
			P[it->first]=inf; PR[inf]=it->first;
		}
		else {
			P[it->first]=(it2->second-it->second)/(it->first-it2->first);
			PR[P[it->first]]=it->first;
		}
	}
	
	void add(V a, V b) { // add ax+b
		if(cmptype) a=-a, b=-b;
		if(Q.count(a)) if(Q[a]==b || Q[a]>b) return;
		Q[a]=b;
		auto it=Q.find(a);
		if(bad(it)) return (void)Q.erase(it);
		while(bad(next(it))) erase(next(it));
		while(bad(prev(it))) erase(prev(it));
		PR.erase(P[it->first]); P.erase(it->first);
		if(prev(it)!=Q.begin()) PR.erase(P[prev(it)->first]); P.erase(prev(it)->first);
		update(it);update(prev(it));
	}
	V query(V x) {
		auto it=PR.lower_bound(x);
		return (it->second*x+Q[it->second])*(cmptype?-1:1);
	}
};

int N;
ll A[303030];
ll X[303030];
ll Y[303030];
ll D[303030];
ConvexHullOnline<ll> cht;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>X[i];
	FOR(i,N) cin>>Y[i];
	
	FOR(i,N) {
		cht.add(-2*X[i],D[i]+X[i]*X[i]+Y[i]*Y[i]);
		D[i+1]=cht.query(A[i])+A[i]*A[i];
	}
	cout<<D[N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
