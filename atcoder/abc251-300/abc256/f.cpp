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

int N,Q;
const ll mo=998244353;
template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		V v;
		v[0]=(l[0]+r[0])%mo;
		v[1]=(l[1]+r[1])%mo;
		v[2]=(l[2]+r[2]+l[1]*r[0])%mo;
		v[3]=(l[3]+r[3]+l[2]*r[0]+l[1]*r[0]%mo*(r[0]+1)%mo*(mo+1)/2%mo)%mo;
		return v;
	};
	
	SegTree_1(){
		val=vector<V>(NV*2);
		int i;
		FOR(i,NV*2) val[i][0]=1;
		for(i=NV-1;i>=1;i--) val[i][0]=val[2*i][0]+val[2*i+1][0];
		
	};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0,0,0,0};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, int v) {
		entry += NV;
		val[entry]={1,v,v,v};
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<array<ll,4>,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>x;
		st.update(i,x);
	}
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>y;
			st.update(x-1,y);
		}
		else {
			cin>>x;
			auto v=st.getval(0,x);
			cout<<v[3]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
