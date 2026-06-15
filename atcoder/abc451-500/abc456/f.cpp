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

int T,N,K;
ll A[202020];

template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	V comp(V l,V r){
		V m={1LL<<60,1LL<<60,1LL<<60,1LL<<60};
		if(l[0]<0) return r;
		if(r[0]<0) return l;
		m[3]=min(l[1]+r[3],l[3]+r[2]);
		m[1]=min({m[3],l[1]+r[1],l[3]+r[0]});
		m[2]=min({m[3],l[0]+r[3],l[2]+r[2]});
		m[0]=min({m[1],m[2],l[0]+r[1],l[2]+r[0]});
		return m;
	};
	
	SegTree_ma(){val=vector<V>(NV*2);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {-1,0,0,0};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, ll v) {
		entry += NV;
		val[entry]={0,v,v,v};
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_ma<array<ll,4>,1<<20> st;



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) {
			cin>>A[i];
			st.update(i,A[i]);
		}
		ll ret=1LL<<60;
		FOR(i,N) {
			for(j=i+K;j<=i+K+3&&j<=N;j++) {
				ret=min(ret,st.getval(i,j)[3]);
			}
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
