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

int N,K,A;

static ll const def=1LL<<60;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+min(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<ll,1<<20> st;
vector<pair<int,int>> ev[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>A;
	vector<vector<int>> cand;
	ll sum=0;
	FOR(i,N) {
		int x,y,c;
		cin>>x>>y>>c;
		sum+=c;
		ev[y].push_back({x,c});
	}
	st.update(0,K,1LL<<60);
	st.update(K,K+1,sum+1LL*K*A);
	
	for(x=1;x<=K;x++) {
		y=K-x;
		ll v=1LL<<60;
		//Á‚³‚È‚¢
		if(x) {
			v=min(v,st.getval(y+1,y+2)-(y+1)*A);
		}
		FORR2(x2,c,ev[y]) {
			st.update(y+x-x2,K+1,-c);
		}
		//Á‚·
		v=min(v,st.getval(y+1,K+1)-y*A);
		st.update(y,y+1,v+(y*A)-(1LL<<60));
		
	}
	
	cout<<st.getval(0,1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
