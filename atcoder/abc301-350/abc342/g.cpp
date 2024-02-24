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

template<class V,int NV> class SegTree_2 {
public:
	multiset<V> val[2*NV];
	SegTree_2(){
		int i;
		FOR(i,2*NV) val[i].insert(0);
	};
	
	V getval(int entry) {
		entry += NV;
		ll ret=*val[entry].rbegin();
		while(entry>1) {
			entry>>=1;
			ret=max(ret,*val[entry].rbegin());
		}
		return ret;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) val[k].insert(v);
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
		}
	}
	void del(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) val[k].erase(val[k].find(v));
		else if(l < y && x < r) {
			del(x,y,v,l,(l+r)/2,k*2);
			del(x,y,v,(l+r)/2,r,k*2+1);
		}
	}
};

int N;
SegTree_2<ll,1<<20> st;
int Q;
int A[202020],B[202020],C[202020],D[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		st.update(i,i+1,x);
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>A[i]>>B[i];
		if(A[i]==1) {
			cin>>C[i]>>D[i];
			st.update(B[i]-1,C[i],D[i]);
		}
		if(A[i]==2) {
			x=B[i]-1;
			st.del(B[x]-1,C[x],D[x]);
			
		}
		if(A[i]==3) {
			cout<<st.getval(B[i]-1)<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
