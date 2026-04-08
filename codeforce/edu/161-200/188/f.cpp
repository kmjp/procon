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
int A[505050],K[505050];
ll add[505050],sub[505050];
const ll mo=998244353;

template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<V,int> > val;
	static V const def=1<<30;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return min(l,r);}
	SegTree_Pair(){
		val.resize(NV*2);
		int i;
		FOR(i,NV) val[i+NV]=make_pair(def,i);
		for(i=NV-1;i>=1;i--) val[i]=comp(val[2*i],val[2*i+1]);
	};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,NV);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=make_pair(v,entry-NV);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_Pair<int,1<<20> st;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

unordered_map<int,ll> D;
ll ret;
void dfs(int L,int R) {
	if(L>=R) return;
	auto p=st.getval(L,R);
	int C=p.second;
	(D[A[C]]+=1LL*(C-L+1)*(R-C))%=mo;
	dfs(L,C);
	dfs(C+1,R);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>A[i];
		st.update(i,A[i]);
		(ret+=1LL*(i+1)*(N-i)%mo*modpow(A[i]))%=mo;
	}
	FOR(i,M) cin>>K[i];
	dfs(0,N);
	
	FORR2(a,b,D) {
		x=lower_bound(K,K+M,a)-K;
		if(a==0) {
			(add[0]+=b)%=mo;
		}
		else {
			(add[0]+=b*modpow(a))%=mo;
			(add[x]+=mo-b*modpow(a)%mo)%=mo;
			(add[x]+=b)%=mo;
			(sub[x]+=b*(a-1)-b*(a-1)%mo*modpow(a))%=mo;
		}
	}
	FOR(i,M) {
		(add[i+1]+=add[i])%=mo;
		(sub[i+1]+=sub[i])%=mo;
		ll v=ret+add[i]*K[i]+mo-sub[i];
		cout<<v%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
