#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int N;
ll A[303030];

const ll EPS=0;
__int128 veccross(pair<__int128,__int128> p1,pair<__int128,__int128> p2,pair<__int128,__int128> p3) {
	p3.first-=p1.first;p2.first-=p1.first;
	p3.second-=p1.second;p2.second-=p1.second;
	return p3.first*p2.second-p2.first*p3.second;
}

template<class C> vector<int> convex_hull_bottom(vector< pair<C, C> >& vp) {
	vector<pair<pair<C, C>, int> > sorted;
	vector<int> res;
	int i,k=0,rb;
	
	if(vp.size()<=2) {
		if(vp.size()>=1) res.push_back(0);
		if(vp.size()>=2) res.push_back(1);
		return res;
	}
	
	FOR(i,vp.size()) sorted.push_back(make_pair(vp[i],i));
	sort(sorted.begin(),sorted.end());
	
	res.resize(vp.size()*2);
	/* bottom */
	FOR(i,vp.size()) {
		while(k>1 && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)<=0) k--;
		res[k++]=sorted[i].second;
	}
	res.resize(k);
	return res;
}

template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) {
		return ((__int128)(B.second-C.second)*(B.first-A.first)<=(__int128)(A.second-B.second)*(C.first-B.first));
	}
	void add(V a, V b) { // add ax+b
		if(Q.size() && Q.back().first==a) {
			//aÇ™ìØÇ∂èÍçá
			//if(b>=Q.back().second) return; //minÇÃèÍçá
			if(b<=Q.back().second) return; //maxÇÃèÍçá
			Q.pop_back();
		}
		Q.push_back({a,b});
		int v;
		while((v=Q.size())>=3 && dodo(Q[v-3],Q[v-2],Q[v-1]))
			Q[v-2]=Q[v-1], Q.pop_back();
	}
	void add(vector<pair<V,V>> v) {
		sort(v.begin(),v.end());
		for(auto r=v.begin();r!=v.end();r++) add(r->first,r->second);
	}
	
	
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			(0^((calc(Q[M],x)<=calc(Q[M+1],x)))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};
ConvexHull<__int128> ch;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll mi=1LL<<41;
	A[0]=1LL<<41;
	FOR(i,N) {
		cin>>A[i+1];
		mi=min(mi,A[i+1]);
	}
	A[N+1]=1LL<<41;
	
	vector<pair<ll,ll>> V;
	FOR(i,N+2) V.push_back({i,-A[i]});
	vector<int> W=convex_hull_bottom(V);
	
	vector<pair<__int128,__int128>> L;
	for(i=1;i<W.size()-1;i++) {
		ll dy=A[W[i]]-A[W[i-1]];
		ll dx=W[i]-W[i-1];
		__int128 a1=dy/dx;
		if(dx*a1<dy) a1++;
		
		dy=A[W[i+1]]-A[W[i]];
		dx=W[i+1]-W[i];
		
		__int128 a2=dy/dx;
		if(dx*a2>dy) a2--;
		
		
		if(a1<=a2) {
			L.push_back({a1,A[W[i]]-a1*W[i]});
			L.push_back({a2,A[W[i]]-a2*W[i]});
		}
	}
	L.push_back({0,mi});
	ch.add(L);
	
	ll ret=0;
	for(i=1;i<=N;i++) {
		ret+=ch.query(i);
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
