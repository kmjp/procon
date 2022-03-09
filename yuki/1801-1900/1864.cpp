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
ll X[202020],Y[202020];
ll mo=998244353;
template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) { if(e<0) return 0; ll s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		X[i]=x+y;
		Y[i]=x-y;
	}
	for(i=N-1;i>=0;i--) {
		X[i]-=X[0];
		Y[i]-=Y[0];
	}
	if(X[N-1]<0) {
		FOR(i,N) X[i]=-X[i];
	}
	if(Y[N-1]<0) {
		FOR(i,N) Y[i]=-Y[i];
	}
	vector<ll> Ys;
	vector<pair<ll,int>> P;
	FOR(i,N) {
		if(X[i]<X[0]||X[i]>X[N-1]) continue;
		if(Y[i]<Y[0]||Y[i]>Y[N-1]) continue;
		Ys.push_back(Y[i]);
	}
	sort(ALL(Ys));
	FOR(i,N) {
		if(i==0) continue;
		if(X[i]<X[0]||X[i]>X[N-1]) continue;
		if(Y[i]<Y[0]||Y[i]>Y[N-1]) continue;
		Y[i]=lower_bound(ALL(Ys),Y[i])-Ys.begin();
		P.push_back({X[i],Y[i]});
	}
	sort(ALL(P));
	ll ret;
	bt.add(0,1);
	FORR2(x,y,P) {
		ret=bt(y);
		bt.add(y,ret);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
