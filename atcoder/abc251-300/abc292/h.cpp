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
ll B;
ll A[505050];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> sum,ma;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){
		sum=vector<V>(NV*2,def);
		ma=vector<V>(NV*2,def);
		ma[NV]=-(1LL<<60);
	};
	pair<V,V> getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0LL,-1LL<<60};
		if(x<=l && r<=y) return {sum[k],ma[k]};
		auto a=getval(x,y,l,(l+r)/2,k*2);
		auto b=getval(x,y,(l+r)/2,r,k*2+1);
		return {a.first+b.first,max(a.second,a.first+b.second)};
	}
	
	void update(int entry, V v) {
		entry += NV;
		sum[entry]=v;
		ma[entry]=v;
		while(entry>1) {
			entry>>=1;
			sum[entry]=sum[entry*2]+sum[entry*2+1];
			ma[entry]=max(ma[entry*2],sum[entry*2]+ma[entry*2+1]);
		}
	}
};
SegTree_1<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>B>>Q;
	for(i=1;i<=N;i++) {
		cin>>A[i];
		A[i]-=B;
		st.update(i,A[i]);
	}
	
	FOR(i,Q) {
		cin>>x>>y;
		A[x]=y-B;
		st.update(x,y-B);
		if(st.ma[1]>=0) {
			int R=N;
			for(j=20;j>=0;j--) if(R-(1<<j)>=1&&st.getval(0,R-(1<<j)+1).second>=0) R-=(1<<j);
			_P("%.12lf\n",1.0*st.getval(0,R+1).first/R+B);
			
		}
		else {
			_P("%.12lf\n",1.0*st.sum[1]/N+B);
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
