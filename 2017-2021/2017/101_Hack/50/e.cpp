#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll mo=1000000007;
int A[303030][3];

template<class V,int NV> class SegTree {
public:
	vector<V> mult,sum;
	SegTree(){mult.resize(NV*2,1); sum.resize(NV*2,0);}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			(mult[k]*=v)%=mo;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=(mult[2*k]*sum[2*k]+mult[2*k+1]*sum[2*k+1])%mo;
		}
	}
	void add(int x,int v) {
		x+=NV;
		while(x>0) {
			sum[x]+=v;
			x/=2;
		}
	}
	
};
ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

SegTree<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i][0]>>A[i][1]>>A[i][2];
		sort(A[i],A[i]+3);
	}
	
	vector<pair<int,int>> V[3];
	V[0].push_back({1<<30,-1});
	V[1].push_back({1<<30,-1});
	V[2].push_back({1<<30,-1});
	
	ll P=0;
	FOR(i,N) {
		st.add(i,1);
		FOR(j,3) {
			st.update(i,i+1,A[i][j]);
			while(V[j].size()>=2 && V[j].back().first<=A[i][j]) {
				ll mul=A[i][j]*modpow(V[j].back().first)%mo;
				x=V[j].back().second;
				V[j].pop_back();
				y=V[j].back().second;
				st.update(y+1,x+1,mul);
			}
			V[j].push_back({A[i][j],i});
		}
		(P+=st.mult[1]*st.sum[1])%=mo;
	}
	
	cout<<P*modpow(1LL*N*(N+1)/2%mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

