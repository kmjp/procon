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
int W[505050];
int pre[505050];
vector<int> A[1050500];
ll dp[1010101];

template<class V,int NV> class SegTree_2 {
public:
	vector<V> val;
	vector<V> ma;
	SegTree_2(){val.resize(NV*2,0); ma.resize(NV*2,-1LL<<60);}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=max(ma[k*2],ma[k*2+1])+val[k];
		}
	}
};
SegTree_2<ll,1<<21> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	scanf("%d",&N);
	FOR(i,N) scanf("%d",&W[i]);
	FOR(i,N) {
		scanf("%d",&x);
		FOR(j,x) scanf("%d",&y), A[y].push_back(i);
	}
	
	dp[1]=0;
	st.update(1,2,(1LL<<60)+dp[1]);
	
	ll ret=0;
	for(i=2;i<=1000500;i++) {
		FORR(r,A[i]) st.update(pre[r],i,W[r]), pre[r]=i;
		dp[i]=st.ma[1];
		st.update(i,i+1,(1LL<<60)+dp[i]);
		ret=max(ret,dp[i]);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
