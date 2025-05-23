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


//区間加算・区間最小値、また最小値を取る要素数
static ll const def=1<<30;
template<class V,int NV> class SegTree_3_num {
public:
	vector<V> val;
	vector<pair<V,int>> mi;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){
		if(l.second==0) return r;
		if(r.second==0) return l;
		if(l.first<r.first) return l;
		if(l.first>r.first) return r;
		l.second+=r.second;
		return l;
	};
	
	SegTree_3_num(){
		int i;
		val.resize(NV*2,0); mi.resize(NV*2,{0,1});
		for(i=NV-1;i>=1;i--) mi[i]=comp(mi[2*i],mi[2*i+1]);
	};
	
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return {def,0};
		if(x<=l && r<=y) return mi[k];
		auto p=comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		p.first+=val[k];
		return p;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			mi[k].first+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			mi[k]=comp(mi[k*2],mi[k*2+1]);
			mi[k].first+=val[k];
		}
	}
};
SegTree_3_num<int,1<<20> st;

int N,Q;
int A[202020],B[202020],C[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>A[i];
		if(A[i]==1) {
			cin>>B[i]>>C[i];
			st.update(B[i],C[i],1);
		}
		else if(A[i]==2) {
			cin>>x;
			x--;
			st.update(B[x],C[x],-1);
		}
		else if(A[i]==3) {
			auto p=st.getval(1,N+1);
			cout<<p.second<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
