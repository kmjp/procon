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
double X[202020],Y[202020];

template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	const int cmptype=0;
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
			(cmptype^((calc(Q[M],x)<=calc(Q[M+1],x)))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};
ConvexHull<double> ch;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	double ma=0;
	double my=0;
	vector<pair<double,double>> V;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		if(Y[i]<0) X[i]=-X[i],Y[i]=-Y[i];
		my=max(my,abs(Y[i]));
		V.push_back({-Y[i],X[i]});
		V.push_back({Y[i],-X[i]});
	}
	ch.add(V);
	
	FOR(i,N) {
		if(Y[i]==0) {
			ma=max(ma,abs(X[i]*my));
		}
		else {
			ma=max(ma,Y[i]*ch.query(X[i]/Y[i]));
		}
	}
	cout<<(ll)(round(ma))<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
