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

int T,N;
ll A[202020];


template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	// static V const def=1LL<<60; min
	V comp(V l,V r){
		V R;
		int i;
		FOR(i,8) R[i]=-1LL<<40;
		int a1,b1,c1,a2,b2,c2;
		FOR(a1,2) FOR(b1,2) FOR(c1,2) {
			ll v1=l[a1+b1*2+c1*4];
			FOR(a2,2) FOR(b2,2) FOR(c2,2) {
				ll v2=r[a2+b2*2+c2*4];
				if(b1&&a2) continue;
				if(c1&&c2) continue;
				int n=a1+b2*2+max(c1,c2)*4;
				R[n]=max(R[n],v1+v2);
			}
		}
		return R;
		
		
	};
	
	SegTree_1(){val=vector<V>(NV*2);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0,-1LL<<40,-1LL<<40,-1LL<<40,-1LL<<40,-1LL<<40,-1LL<<40,-1LL<<40};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, ll v) {
		entry += NV;
		
		if(v>=0) {
			val[entry]={0,-1LL<<40,-1LL<<40,1,-1LL<<40,-1LL<<40,-1LL<<40,1+v};
		}
		else {
			val[entry]={0,-1LL<<40,-1LL<<40,-1LL<<40,-1LL<<40,-1LL<<40,-1LL<<40,-1LL<<40};
		}
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<array<ll,8>,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<pair<int,int>> V;
		FOR(i,N) {
			cin>>A[i];
			st.update(i,A[i]);
			V.push_back({A[i],i});
		}
		ll ret=0;
		sort(ALL(V));
		FORR2(x,y,V) {
			auto a=st.getval(0,N);
			ret=max(ret,max({a[4],a[5],a[6],a[7]})+x);
			st.update(y,-1LL<<40);
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
