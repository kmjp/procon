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
	const V inf=1e9+1;
	const int cmptype=1; // 0-max 1-min
	map<V,V> Q,PR; // Q[a]=b -> a*x+b, P[a]=c ax+b is best unti x<=c PR[c]=a
	unordered_map<V,V> P;
	ConvexHullOnline() { Q[inf]=Q[-inf]=-inf*inf;}
	int ok(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		if(A.first==-inf && C.first==inf) return 1;
		return ((B.second-A.second)*(B.first-C.first)<=(C.second-B.second)*(A.first-B.first));
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

	/*
	ConvexHullOnline<double> cht;
	cht.add(2,-6);
	cht.add(1,0);
	cht.add(3,-8);
	cht.add(1,5);
	cht.add(4,1);
	FORR(q,cht.Q) cout<<"Q"<<q.first<<" "<<q.second<<endl;
	FORR(q,cht.P) cout<<"P"<<q.first<<" "<<q.second<<endl;
	FORR(q,cht.PR) cout<<"PR"<<q.first<<" "<<q.second<<endl;
	for(double a=-1;a<=8;a+=0.1) _P("%.2lf %.2lf\n",a,cht.query(a));
	*/

int N,K;
ll A[10101];
ll dp[10101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i+1];
		dp[i+1][1]=(A[i+1]-A[1])*(A[i+1]-A[1]);
	}
	
	for(i=2;i<=K;i++) {
		ConvexHullOnline<ll> cht;
		for(j=1;j<=N;j++) {
			if(j<i) {
				dp[j][i]=1LL<<60;
			}
			else {
				dp[j][i]=A[j]*A[j]+cht.query(A[j]);
			}
			if(dp[j][i-1]<1LL<<60) {
				cht.add(-2*A[j+1],A[j+1]*A[j+1]+dp[j][i-1]);
			}
		}
	}
	cout<<dp[N][K]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
