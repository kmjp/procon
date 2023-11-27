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

int N,M;
ll A[303030],D[303030];
int cur[303030];

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
			//aが同じ場合
			if(b<=Q.back().second) return; //maxの場合
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
ConvexHull<ll> ch;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<pair<ll,ll>> C;
	C.push_back({-(3LL<<30),-(1LL<<40)});
	priority_queue<pair<ll,int>> Q;
	FOR(i,N) {
		cin>>A[i]>>D[i];
		if(D[i]>=0) {
			C.push_back({D[i],2*A[i]-D[i]});
		}
		else {
			Q.push({A[i],i});
		}
	}
	ch.add(C);
	A[N]=-1LL<<42;
	Q.push({A[N],N});
	ll ret=M*ch.query(M)/2;
	ll sum=0;
	for(i=M-1;i>=0;i--) {
		auto p=Q.top();
		Q.pop();
		sum+=p.first;
		x=p.second;
		A[x]+=D[x];
		Q.push({A[x],x});
		ret=max(ret,sum+i*ch.query(i)/2);
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
