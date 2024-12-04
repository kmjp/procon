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

int H,W,N;
int Y[202020],X[202020],L[202020];
vector<int> C[202020];

static ll const def=1<<20;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val,ma; //区間全体を覆う最大値・区間内のいずれかの最大値
	SegTree_3(){
		val.resize(NV*2,def);
		ma.resize(NV*2,def);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return ma[k];
		return min({val[k],getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1)});
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]=min(val[k],v);
			ma[k]=min(ma[k],v);
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=min({ma[k],ma[k*2],ma[k*2+1]});
		}
	}
};

SegTree_3<int,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	FOR(i,N) {
		cin>>Y[i]>>X[i]>>L[i];
		C[Y[i]].push_back(i);
	}
	st.update(0,W+1,H+1);
	for(y=H;y>=1;y--) {
		FORR(e,C[y]) {
			int ty=st.getval(X[e],X[e]+L[e]);
			Y[e]=ty-1;
			st.update(X[e],X[e]+L[e],Y[e]);
		}
	}
	FOR(i,N) cout<<Y[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
