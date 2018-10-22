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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val[3];
	
	SegTree_1(){
		val[0].resize(NV*2);
		val[1].resize(NV*2);
		val[2].resize(NV*2);
	};
	pair<V,V> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return {0,0};
		if(x<=l && r<=y) return {val[0][k],val[1][k]};
		pair<ll,ll> a=getval(x,y,l,(l+r)/2,k*2);
		pair<ll,ll> b=getval(x,y,(l+r)/2,r,k*2+1);
		a.first+=b.first;
		a.second+=b.second;
		if(val[2][k]) swap(a.first,a.second);
		return a;
	}
	
	void update(int x,int y, int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			swap(val[0][k],val[1][k]);
			val[2][k]^=1;
		}
		else if(l < y && x < r) {
			update(x,y,l,(l+r)/2,k*2);
			update(x,y,(l+r)/2,r,k*2+1);
			val[0][k]=val[0][k*2]+val[0][k*2+1];
			val[1][k]=val[1][k*2]+val[1][k*2+1];
			if(val[2][k]) swap(val[0][k],val[1][k]);
		}
	}
};

int N,M,K;
int A[101010],B[101010],C[101010],D[101010];
vector<pair<int,int>> ev;
SegTree_1<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	vector<int> Xs;
	Xs.push_back(1);
	Xs.push_back(M+1);
	FOR(i,K) {
		cin>>A[i]>>B[i]>>C[i]>>D[i];
		ev.push_back({A[i]-1,i});
		ev.push_back({B[i],i});
		Xs.push_back(C[i]);
		Xs.push_back(D[i]+1);
	}
	ev.push_back({N,-1});
	sort(ALL(Xs));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	FOR(i,Xs.size()-1) st.val[0][i+(1<<20)]=Xs[i+1]-Xs[i];
	for(i=(1<<20)-1;i>=1;i--) st.val[0][i]=st.val[0][2*i]+st.val[0][2*i+1];
	int pre=0;
	sort(ALL(ev));
	ll ret=0;
	FORR(e,ev) {
		if(e.first!=pre) {
			ret+=(e.first-pre)*st.getval(0,(int)Xs.size()).first;
			pre=e.first;
		}
		if(e.second!=-1) {
			x=e.second;
			i=lower_bound(ALL(Xs),C[x])-Xs.begin();
			j=lower_bound(ALL(Xs),D[x]+1)-Xs.begin();
			st.update(i,j);
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
