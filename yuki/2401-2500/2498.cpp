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
	vector<V> val;
	SegTree_2(){val.resize(NV*2); FORR(v,val) v.second=(1<<30)-1;};
	int merge(int cur,pair<int,int> a) {
		return (cur&a.second)|(~cur&a.first);
	}
	pair<int,int> merge(pair<int,int> cur,pair<int,int> a) {
		
		return {merge(cur.first,a),merge(cur.second,a)};
	}
	
	V getval(int k) {
		int e=k+NV;
		V ret={0,(1<<30)-1};
		while(e>=1) {
			ret=merge(ret,val[e]);
			e/=2;
		}
		return ret;
	}
	
	void update(int x,int y, int orv,int xorv ,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			if(orv) {
				val[k].first|=orv;
				val[k].second|=orv;
			}
			else {
				val[k].first^=xorv;
				val[k].second^=xorv;
			}
		}
		else if(l < y && x < r) {
			val[k*2]=merge(val[k*2],val[k]);
			val[k*2+1]=merge(val[k*2+1],val[k]);
			val[k]={0,(1<<30)-1};
			update(x,y,orv,xorv,l,(l+r)/2,k*2);
			update(x,y,orv,xorv,(l+r)/2,r,k*2+1);
		}
	}
};


SegTree_2<pair<int,int>, 1<<20> st;

int N,Q;
ll M[101010];
ll C[31][31];

ll from[33];
ll to[33],dp[33];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,31) {
		C[i][0]=C[i][i]=1;
		for(j=1;j<i;j++) C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	
	cin>>N>>Q;
	
	FOR(i,N) cin>>M[i];
	while(Q--) {
		int L,R,X;
		cin>>s>>L>>R>>X;
		L--;
		if(s=="o") {
			st.update(L,R,X,0);
		}
		else {
			st.update(L,R,0,X);
		}
	}
	FOR(i,31) from[i]=1;
	
	FOR(i,N) {
		ZERO(to);
		ZERO(dp);
		auto p=st.getval(i);
		int add=0;
		for(j=29;j>=0;j--) {
			if(M[i]&(1<<j)) {
				int add2=add+((p.first>>j)%2);
				int both=__builtin_popcountll((p.first&p.second)&((1<<j)-1));
				int one=__builtin_popcountll((p.first^p.second)&((1<<j)-1));
				for(x=0;x<=one;x++) {
					(dp[add2+both+x]+=C[one][x]*(1LL<<(j-one)))%=mo;
				}
				if(p.second&(1<<j)) add++;
			}
			else {
				if(p.first&(1<<j)) add++;
			}
		}
		dp[add]++;
		FOR(j,31) {
			(dp[j+1]+=dp[j])%=mo;
			from[j]=from[j]*dp[j]%mo;
		}
	}
	
	ll ret=0;
	for(i=1;i<=30;i++) (ret+=i*(from[i]+mo-from[i-1]))%=mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
