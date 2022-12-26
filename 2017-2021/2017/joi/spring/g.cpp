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
	const V inf=(1LL<<60)+1;
	const int cmptype=1; // 0-max 1-min
	map<V,V> Q; // Q[a]=b -> a*x+b, P[a]=c ax+b is best unti x<=c PR[c]=a
	map<double,V> PR;
	map<V,double> P;
	ConvexHullOnline() {
		Q[inf]=Q[-inf]=-inf*inf;
	}
	int ok(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		if(A.first==-inf && C.first==inf) return 1;
		return (B.second-A.second)*(B.first-C.first)<=(C.second-B.second)*(A.first-B.first);
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
			P[it->first]=(double)(it2->second-it->second)/(double)(it->first-it2->first);
			PR[P[it->first]]=it->first;
		}
	}
	
	void add(V a, V b) { // add ax+b
		if(cmptype) a=-a, b=-b;
		if(Q.count(a)) if(Q[a]==b || Q[a]>b) return;
		Q[a]=b;
		auto it=Q.find(a);
		if(bad(it)) return (void)Q.erase(it);
		while(bad(next(it))) erase(next(it)), it=Q.find(a);
		while(bad(prev(it))) erase(prev(it)), it=Q.find(a);
		PR.erase(P[it->first]); P.erase(it->first);
		if(prev(it)!=Q.begin()) PR.erase(P[prev(it)->first]); P.erase(prev(it)->first);
		update(it);update(prev(it));
	}
	V query(V x) {
		if(PR.empty()) return (-1LL<<60)*(cmptype?-1:1);
		auto it=PR.lower_bound(x);
		return (it->second*x+Q[it->second])*(cmptype?-1:1);
	}
};
ll X;
ll N,M;
ll T,W;
ll S[202020];
ll turn[202020];
pair<ll,ll> P[202020];
__int128 dp0[202020];

ConvexHullOnline<__int128> ch;

void solve() {
	ll i,j,k,l,r,x,y; string s;
	
	cin>>X>>N>>M>>W>>T;
	FOR(i,N) cin>>S[i];
	FOR(i,M) {
		cin>>P[i].first>>P[i].second;
		dp0[M]+=P[i].second;
	}
	sort(P,P+M);
	FOR(i,M+1) turn[i]=1LL<<60;
	
	S[N]=X;
	N++;
	FOR(i,N) {
		x=lower_bound(P,P+M,make_pair(S[i]%T,0LL))-P;
		turn[x]=min(turn[x],S[i]/T);
	}
	
	for(i=M-1;i>=0;i--) {
		__int128 cur=min(dp0[i+1],ch.query(i+1));
		dp0[i]=cur+__int128(X/T+(P[i].first<X%T))*W-P[i].second;
		if(turn[i+1]<1LL<<60) {
			ch.add(-W*turn[i+1],__int128(W)*turn[i+1]*(i+1)+cur);
		}
	}
	
	__int128 ret=min(dp0[0],ch.query(0));
	
	ret+=(X/T+1)*W;
	cout<<(ll)ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
