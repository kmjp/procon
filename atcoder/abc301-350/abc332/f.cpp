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

int N,M;
int A[202020];

const ll mo=998244353;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		V p;
		p.first=(l.first*r.second+r.first)%mo;
		p.second=l.second*r.second%mo;
		return p;
	};
	
	SegTree_1(){val=vector<V>(NV*2,{0,1});};
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v; //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<pair<ll,ll>,1<<20> st;

int L[202020],R[202020],X[202020];
vector<int> add[202020],del[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	
	FOR(i,M) {
		cin>>L[i]>>R[i]>>X[i];
		L[i]--;
		add[L[i]].push_back(i);
		del[R[i]].push_back(i);
	}
	FOR(i,N) {
		FORR(a,add[i]) {
			x=R[a]-L[a];
			y=modpow(x);
			st.update(a+1,{1LL*X[a]*y%mo,(1+mo-y)%mo});
		}
		FORR(a,del[i]) {
			st.update(a+1,{0,1});
		}
		st.update(0,{A[i],0});
		
		cout<<st.val[1].first<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
