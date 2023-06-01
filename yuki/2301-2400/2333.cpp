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
ll A[303030],B[303030];
int Q;
ll T[303030],L[303030],R[303030];
vector<ll> X;

array<ll,4> const def={-(1LL<<60),-(1LL<<60),-(1LL<<60),-(1LL<<60)}; // L,R,sum,ma
template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		V a;
		a[0]=max(l[0],l[2]+r[0]);
		a[1]=max(r[1],r[2]+l[1]);
		a[2]=max(-(1LL<<60),l[2]+r[2]);
		a[3]=max({l[3],r[3],l[1]+r[0],-1LL<<60});
		return a;
	}
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v; //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<array<ll,4>,1<<20> st;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll sum=0;
	X.push_back(0);
	FOR(i,N) {
		cin>>A[i]>>B[i];
		sum+=B[i];
		X.push_back(sum);
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>T[i]>>L[i]>>R[i];
		L[i]--;
		if(T[i]==1) {
			X.push_back(L[i]);
			X.push_back(L[i]+1);
		}
		else {
			X.push_back(L[i]);
			X.push_back(R[i]);
		}
	}
	sort(ALL(X));
	X.erase(unique(ALL(X)),X.end());
	int cur=0;
	FOR(i,X.size()-1) {
		if(B[cur]==0) cur++;
		ll a=X[i+1]-X[i];
		B[cur]-=a;
		st.update(i,{max(A[cur],a*A[cur]),max(A[cur],a*A[cur]),a*A[cur],max(A[cur],a*A[cur])});
	}
	
	FOR(i,Q) {
		ll a=lower_bound(ALL(X),L[i])-X.begin();
		if(T[i]==1) {
			st.update(a,{R[i],R[i],R[i],R[i]});
		}
		else {
			ll b=lower_bound(ALL(X),R[i])-X.begin();
			auto p=st.getval(a,b);
			cout<<p[3]<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
