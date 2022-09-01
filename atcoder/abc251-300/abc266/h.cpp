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

template<class V, int ME> class BIT_map {
public:
	unordered_map<ll,V> bit;
	V op(V a,V b){ return max(a,b); };
	//V op(V a,V b){ return a+b };
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s=op(s,bit[e-1]),e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]=op(bit[e-1],v),e+=e&-e;}
};

template<class BIT,class V,int ME> class BIT_2D {
public:
	vector<BIT> bit;
	BIT_2D(): bit(1<<ME){};
	V op(V a,V b){ return bit[0].op(a,b); };
	V operator()(int e,int b) {if(e<0) return 0;V s=0;e++;while(e) s=op(s,bit[e-1](b)),e-=e&-e; return s;}
	void add(int e,int b,V v) { e++; while(e<=1<<ME) bit[e-1].add(b,v),e+=e&-e;}
};
BIT_2D<BIT_map<ll,18>,ll,18> bit;

int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<vector<ll>> V;
	vector<ll> Xs,Ys;
	Xs.push_back(0);
	Ys.push_back(0);
	
	cin>>N;
	FOR(i,N) {
		ll t,x,y,a;
		cin>>t>>x>>y>>a;
		if(t-x-y>=0&&t+x-y>=0) {
			V.push_back({y,t-x-y,t+x-y,a});
			Xs.push_back(t-x-y);
			Ys.push_back(t+x-y);
		}
	}
	sort(ALL(V));
	sort(ALL(Xs));
	sort(ALL(Ys));
	
	ll ma=0;
	FORR(v,V) {
		ll x=lower_bound(ALL(Xs),v[1])-Xs.begin();
		ll y=lower_bound(ALL(Ys),v[2])-Ys.begin();
		ll r=bit(x,y)+v[3];
		ma=max(ma,r);
		bit.add(x,y,r);
	}
	cout<<ma<<endl;
		
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
